/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:08:35 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/10 17:54:04 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include "../utils/ft_enable_if.hpp"
# include "../utils/ft_is_integral.hpp"
# include "../utils/ft_utility.hpp" 
# include "../iterator/iterator_vector.hpp"
# include "../iterator/reverse_iterator.hpp"


namespace ft
{   
    template <class T, class Allocator = std::allocator<T> >
    class vector {
			public:
                typedef                 T                                          value_type;
                typedef           const T                                          const_value_type;
                typedef           Allocator                                        allocator_type;
                typedef typename  allocator_type::size_type                        size_type;
                typedef typename  allocator_type::reference                        reference;
                typedef typename  allocator_type::const_reference                  const_reference;
                typedef typename  allocator_type::const_pointer                    const_pointer;
                typedef typename  allocator_type::pointer                          pointer;
                typedef typename  allocator_type::difference_type                  difference_type;
                typedef typename  ft::RandomAccessIter<value_type>                 iterator;
                typedef typename  ft::RandomAccessIter<const_value_type>           const_iterator;
                typedef typename  ft::reverse_iterator<iterator>                   reverse_iterator;    
                typedef typename  ft::reverse_iterator<const_iterator>             const_reverse_iterator;
                
        private:
            allocator_type  _alloc;       
            pointer         _start;
            pointer         _end;
            size_type       _capacity;
            size_type       _size;
            
            void    _extra_capacity(size_type n, pointer tmp, size_type _size)
            {     
                _start = _alloc.allocate(n);
                _end   = _start;
                _capacity = n;
                for (size_t i = 0; i < _size; i++)
                {
                    _alloc.construct(_end++, tmp[i]);
                	_alloc.destroy(tmp + i);
                }
                _alloc.deallocate(tmp, _size);             
            }
			
            void    _double( void )
            {
                _capacity *= 2;
                if (_capacity == 0)
                    _capacity = 1;
            }
            
			void    _destroy_range(size_type n, size_type _size)
            {
                for(; n < _size; n++) _alloc.destroy(--_end);
            };
			
			void	_fill_val(const value_type &val, size_type n)
			{
				clear();
				resize(n, val);
			}
			
            void    _insert_end(size_type n, const value_type& val, pointer tmp, size_type _size)
            {
                (void)tmp;
                reserve(n + _size);
                for(size_t i = 0; i < n; i++) _alloc.construct(_end++, val);
            }
            
            void    __extra_capacity(size_type n)
            {
                _alloc.deallocate(_start, size());
                _start = _alloc.allocate(n);
                _end = _start; 
                _capacity = n;
            }
            
            void    _middle_extra_capacity(size_type n, size_type pos, const value_type& val, size_type _size)
            {
                pointer tmp = _start;
                if (n + _size >= _capacity)
                       _double(); _extra_capacity(_capacity, tmp, size());
                size_type _end_pos = size() - pos; 
                _end = _end - _end_pos;
                size_t i = 0;
                for (; i < n; i++)
                {
                    _alloc.destroy(_end);
                    _alloc.construct(_end++, val);
                }
                if (size() < _size + n)
                {
                    for (; pos < _size; pos++)
                    {
                        _alloc.construct(_end++,tmp[pos]);
                    }
                }
            } 
          
            void    _insert_begin(size_type n, const value_type& val, pointer tmp, size_type _size)
            {
                for(size_t i = 0; i < n; i++)
                {
                    _alloc.construct(_end++, val);
                }
                for(size_t i = 0; i < _size; i++)
                {
                    _alloc.construct(_end++, tmp[i]);
                }
                _destroy_ptr(tmp, _size);
            }
    
            void    _destroy_ptr(pointer ptr, size_type _size)
            {
                for (size_t i = 0; i < _size; i++)
                    {
                        _alloc.destroy(ptr + i);   
                    }
                _alloc.deallocate(ptr, _size);
            }

            void    _insert_after(pointer _ptr, size_t i, size_type _size) 
            {
               while ( i++ < _size)
               {
                _alloc.destroy(_start + i), _alloc.construct(_start + i, _ptr[i]);
               }
            }

        public:
            explicit vector(const allocator_type& alloc = allocator_type()) : 
                    _alloc(alloc),
                           _capacity(0),
                                     _size(0)
                {
                     _start = _alloc.allocate(_capacity);
                     _end = _start;
                }
            explicit vector(size_type n, const value_type& val = value_type(),
                     const allocator_type& alloc = allocator_type()) : _size(n)
            {
                _alloc = alloc;
                _start = _alloc.allocate(n);
                _end = _start;
                _capacity = n;
                while (n--)
                    _alloc.construct(_end++, val);
            }

            template <class InputIterator>
            vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, 
                    InputIterator last,const allocator_type& alloc = allocator_type()) : _alloc(alloc), _capacity(0), _size(0)
            {
                InputIterator tmp = first;
                for (; tmp != last; tmp++)
                    _size++;
                reserve(_size);
                for (InputIterator ptr = first; ptr != last; ptr++)
                    push_back(*ptr);
            }                    
            
            vector(const vector &x)
            {
                size_type size = x.size();        
                _alloc = x._alloc;
                _start = _alloc.allocate(size);
                _end = _start;
                _capacity = x._capacity;
                for (size_t i = 0; i < size; i++)
                {
                    _alloc.construct(_end++, x[i]);
                }   
            };
            
            ~vector()
            {
                clear();
               _alloc.deallocate(_start, size()); 
            };
            
            vector& operator= (const vector& x)
            {
                _alloc = x._alloc;
                size_type _size = x.size(); 
                _alloc.deallocate(_start, size());
                _start = _alloc.allocate(_size);
                _end = _start;
                _capacity = x._capacity;
                for (size_t i = 0; i < _size; i++)
                {
                    _alloc.construct(_end++, x[i]);
                }         
                return (*this);
            } 
                   
            iterator begin()
            {
            	return (iterator(_start));        
            }
            
            iterator end()
            {
                return (iterator(_end));
            }
            
            const_iterator begin() const
            {
                return (const_iterator(_start));
            }
            
            const_iterator end() const
            {
                return (const_iterator(_end));
            }
            
            reverse_iterator rbegin()
            {
                return (reverse_iterator(iterator(_end)));
            }
            
            reverse_iterator rend()
            {
                return (reverse_iterator(iterator(_start)));        
            }
            
            const_reverse_iterator rend() const
            {
                return (const_reverse_iterator(const_reverse_iterator(_start)));      
            }
            
            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(const_reverse_iterator(_end )));
            }
            
            size_type       size() const
            {
                return (_end - _start);
            }
            size_type max_size() const
            {
                return (_alloc.max_size());       
            }
            
            reference at(size_type n)
            {
                if (n >= size())
                    throw std::out_of_range("vector::at: index out \
                        of range");
                return (_start[n]);
            }
            
            const_reference at(size_type n) const
            {
                if (n >= size())
                        throw std::out_of_range("vector::at: index out \
                            of range");
                return (_start[n]);    
            }
            
            reference operator[](size_type n)
            {
                return (_start[n]);
            }
            
            const_reference operator[](size_type n) const
            {
                return (_start[n]);
            }   
            
            bool empty()
            {
                if (size())
                    return (false);
                return (true);
            }    

            allocator_type get_allocator() const 
            {
                return (_alloc);
            }

            reference front()
            {
                
                return (_start[0]);
            }
            const_reference front() const 
            {
                return (_start[0]);
            }
             
            reference back()
            {
                return (_start[size() - 1]);
            }
            
            const_reference back() const 
            {
                return (_start[size() - 1]);        
            } 

            size_type capacity()
            {         
                return (_capacity);
            }

            void clear()
            {
                for(;_end != _start; --_end)
                        _alloc.destroy(_end);
            }

            template <class InputIt>    
            void insert (iterator position, typename ft::enable_if<!(ft::is_integral<InputIt>::value), InputIt>::type first, 
                        InputIt last)
            {
                if (first == last)
                    return;
                size_type _size = size(); 
                size_type pos = &(*position) - _start;
                pointer _str = _start;
                size_t diff = 0;
                InputIt tmp = first;
                while (tmp++ != last)
                        diff++;
                if (diff + _size >= _capacity)
                       _double(); _extra_capacity(_capacity, _str, _size);
                size_type end_pos = _size - pos;
                _end = _end - end_pos;
                for (size_t i =0 ; i < diff; i++)
                {
                    _alloc.destroy(_start + pos + i);
                }
                for(size_t i = 0; i < diff; i++, first++)
                {
                    _alloc.destroy(_end);
                    _alloc.construct(_end++, *first);
                }
                size_t j = -1;
                size_type rest = _size - pos;
                while (++j < rest)
                {
                    _alloc.construct(_end++, _str[pos++]);
                }
            }

			iterator insert (iterator position, const value_type &val)
			{
                size_type pos = &(*position) - _start;         
                insert(position, 1, val);
                return (_start + pos);
            }
            
            iterator insert (iterator position, size_type n, const value_type& val)
            {
                if (n < 0)
                    throw std::length_error("ft::vector: negative_lenght");
                size_type pos = &(*position) - _start;
                _middle_extra_capacity(n, pos, val, size());
                return (_start + pos);
            }

			template <class InputIt>
				void assign(typename ft::enable_if<!(ft::is_integral<InputIt>::value), InputIt>::type first, InputIt last)
				{
                    InputIt tmp;
                    size_type _range = 0;
                    tmp = first;
                    while (tmp++ != last)
                        _range++;
                    clear();
                    resize(_range);
                    size_type i = 0;
                    for (; first != last; ++i, ++first)
                        _alloc.construct(&_end[i], *first);
                    _size = i;
              };
							
			void	assign (size_type n, const value_type& val)
			{
                _size = n;
				_fill_val(val, n);
			}
			
            void    resize(size_type n, value_type val = value_type())
            {
                if (n > _capacity)
                    __extra_capacity(n);
                while (n > size())
                    push_back(val);
                while (n < size())
                    pop_back();
            } 
            
            void push_back(const value_type &val)
            {
                insert(end(), 1, val);
            }
            
            void    reserve(size_type n)
            {
                if (n > max_size())
                        throw std::length_error("Greater than max_size");                      
                if (n > _capacity)
                {
                    pointer tmp = _start;
                    _extra_capacity(n, tmp, size());
                    _capacity = n;
                }
            };
            
            void pop_back()
            {
                // if (size())
                // {
                    _end--;
                    this->_alloc.destroy(_end);
                // }   
                // --this->_end;
            }
            
            iterator erase(iterator position)
            {
                if (position == this->end() - 1)
                        this->pop_back();
                else
                {
                    size_type pos = &(*position) - _start;
                    pointer   ptr = _start + pos + 1;
                    while (ptr != _end)
                        *(ptr - 1) = *ptr, ptr++;
                    _end--;
                }                        
              return (position);
            };
            
            iterator erase(iterator first, iterator last)
            {
               if (first == last)
                    return (first);
               if (first != last)
               {
                    while (first != last--)
                        erase(last);
               }
              return (first);                                                                                              
            };
            
            void swap(vector &x)
            {
                vector tmp(x);
                x = *this;
                *this = tmp;
            };
            
        friend bool operator== (const vector& lhs, const vector& rhs)
        {
            if (lhs.size() != rhs.size())
                    return (false);
            const_iterator __end = lhs.end();
            ft::pair<const_iterator, const_iterator> _it(lhs.begin(), rhs.begin());
            for (; _it.first !=  __end; ++_it.first, ++_it.second)
            {
                if (*(_it.first) != *(_it.second))
                        return false;
            }
            return true;
        }

        friend bool operator!= (const vector& lhs, const vector& rhs)
        {
            if (lhs.size() != rhs.size())
                    return (true);
            const_iterator __end = lhs.end();
            ft::pair<const_iterator, const_iterator> _it(lhs.begin(), rhs.begin());
            for (; _it.first !=  __end; ++_it.first, ++_it.second)
            {
                if (*(_it.first) != *(_it.second))
                        return true;
            }
            return false;
        }

        friend bool operator<  (const vector& lhs, const vector& rhs)
        {
            if (lhs.size() < rhs.size())
                return (true);
            const_iterator __end_l = lhs.end();
            const_iterator __end_r = rhs.end();
            ft::pair<const_iterator, const_iterator> _it(lhs.begin(), rhs.begin());
            for (; _it.first !=  __end_l && _it.second != __end_r ; ++_it.first, ++_it.second)
            {
                if (*(_it.first) < *(_it.second))
                        return true;
            }
            return false;
        }

        friend bool operator<= (const vector& lhs, const vector& rhs)
        {
            return (lhs < rhs || lhs == rhs);
        }

      friend  bool operator>  (const vector& lhs, const vector& rhs)
        {
            if (lhs.size() > rhs.size())
                return (true);
            const_iterator __end_l = lhs.end();
            const_iterator __end_r = rhs.end();
            ft::pair<const_iterator, const_iterator> _it(lhs.begin(), rhs.begin());
            for (; _it.first !=  __end_l && _it.second != __end_r ; ++_it.first, ++_it.second)
            {
                if (*(_it.first) > *(_it.second))
                        return true;
            }
            return false;
        }

        friend bool operator>= (const vector& lhs, const vector& rhs)
        {
           if (lhs.size() >= rhs.size())
                return (true);
            const_iterator __end_l = lhs.end();
            const_iterator __end_r = rhs.end();
            ft::pair<const_iterator, const_iterator> _it(lhs.begin(), rhs.begin());
            for (; _it.first !=  __end_l && _it.second != __end_r ; ++_it.first, ++_it.second)
            {
                if (*(_it.first) >= *(_it.second))
                        return true;
            }
            return false;
        }
};
    
}

#endif