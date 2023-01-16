/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:08:35 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/16 16:35:58 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <memory>
# include "../utils/ft_enable_if.hpp"
# include "../utils/ft_is_integral.hpp"
# include "../iterator/iterator_vector.hpp"

namespace ft
{   
    template <class T, class Allocator = std::allocator<T> >
    class Vector {
            
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
                typedef typename  ft::RandomAccessIterRev<value_type>              reverse_iterator;
                typedef typename  ft::RandomAccessIterRev<const_value_type>        const_reverse_iterator;
                
        private:
            allocator_type  _alloc;       
            pointer         _start;
            pointer         _end;
            size_type       _capacity;
            size_type       _size;
            
            void    _extra_capacity(size_type n, pointer tmp, size_type _size)
            {     
                _start = _alloc.allocate(n);
                _end = _start;
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
                reserve(n + _size);
                for(size_t i = 0; i < n; i++) _alloc.construct(_end++, val);
            }
            
            void    __extra_capacity(size_type n)
            {
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
               
                // iterator _ptr_end  = end();
                // // if (_ptr == end() - 1)
                // //     _alloc.destroy(_start + i), _alloc.construct(_start + i, *(++_ptr));
                    
                // while(_ptr++ != _ptr_end && i++ < _size)
                // {
                //     _alloc.destroy(_start + i), _alloc.construct(_start + i, *_ptr);
                // }
                
            
            
            }

        public:
            explicit Vector(const allocator_type& alloc = allocator_type()) : 
                    _alloc(alloc),
                            _start(nullptr),
                                    _end(nullptr),
                                            _capacity(0),
                                                _size(0)
                                    {}
            explicit Vector(size_type n, const value_type& val = value_type(),
                     const allocator_type& alloc = allocator_type()) : _size(0)
            {
                _alloc = alloc;
                _start = _alloc.allocate(n);
                _end = _start;
                _capacity = n;
                while (n--)
                    _alloc.construct(_end++, val);
            }

            template <class InputIterator>
            Vector(typename ft::enable_if<!(ft::is_integral<InputIterator>::value), InputIterator>::type first, 
                    InputIterator last,const allocator_type& alloc = allocator_type()) : _capacity(0), _size(0)
            {
                iterator tmp = first;
                for (; tmp != last; tmp++)
                    _size++;
                reserve(_size);
                for (iterator ptr = first; ptr != last; ptr++)
                    push_back(*ptr);
            }                    
            
            Vector(const Vector &x)
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
            
            ~Vector()
            {};
            Vector& operator= (const Vector& x)
            {
                if (*this != x)
                {
                    // if (size() == x.size())
                    // {
                        _alloc = x._alloc;
                       size_type _size = x.size(); 
                        _start = _alloc.allocate(_size);
                        _end = _start;
                        _capacity = x._capacity;
                        for (size_t i = 0; i < _size; i++)
                        {
                            _alloc.construct(_end++, x[i]);
                        }
                    // }
                    // else if (_capacity >=)
                }
                return (*this);
            } 
                   
            iterator begin()
            {
            	return (_start);        
            }
            
            iterator end()
            {
                return (_end);
            }
            
            const_iterator begin() const
            {
                return (_start);
            }
            
            const_iterator end() const
            {
                return (_end);
            }
            
            reverse_iterator rbegin()
            {
                return (_end);
            }
            
            reverse_iterator rend()
            {
                return (_start);        
            }
            
            const_reverse_iterator rend() const
            {
                return (_start);      
            }
            
            const_reverse_iterator rbegin() const
            {
                return (_end);
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
                    throw std::out_of_range("Vector::at: index out \
                        of range");
                return (_start[n]);
            }
            
            const_reference at(size_type n) const
            {
                if (n >= size())
                        throw std::out_of_range("Vector::at: index out \
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
                    return (true);
                return (false);
            }    

            allocator_type get_allocator() const 
            {
                return (_alloc);
            }

            reference front()
            {
                return (_start);
            }
            const_reference front() const 
            {
                return (_start);
            }
             
            reference back()
            {
                return (_end - 1);
            }
            
            const_reference back() const 
            {
                return (_end - 1);        
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
                size_t diff = 0 , i = 0;
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
                    // __extra_capacity(_range);
                    while (first != last)
                        push_back(*(first++));
              };
							
			void	assign (size_type n, const value_type& val)
			{
                std::cout << "in normale assign " << std::endl;
				_fill_val(val, n);
			}
			
            void    resize(size_type n, value_type val = value_type())
            {
                size_type _size = size();
                if (n < _size)
                      _destroy_range(n, _size);
                if (n > _size)
                {
                    if (n > _capacity)
                    {
                        pointer tmp = _start;
                        _extra_capacity(n, tmp, _size);
                        _capacity = n;
                        for(; _size < n; _size++)  _alloc.construct(_end++, val);
                    }
                    for(; _size < n; _size++)  _alloc.construct(_end++, val);
                }
            } 
            
            void push_back(const value_type &val)
            {
               insert(end(), val);
            }
            
            void    reserve(size_type n)
            {
                if (n > max_size())
                        throw std::length_error("Greater than max_size");                      
                if (n > _capacity)
                {
                    std::cout << "in reserveee" << std::endl;
                    pointer tmp = _start;
                    size_type u = size();
                    _extra_capacity(n, tmp, size());
                    _capacity = n;
                }
            };
            
            void pop_back()
            {
                --this->_end;
                this->_alloc.destroy(this->_end);
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
            
            void swap(Vector &x)
            {
                Vector tmp(x);
                x = *this;
                *this = tmp;
            };
        };
    
    template <class T, class Alloc>
        bool operator== (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
                return (lhs == rhs);
        }

    template <class T, class Alloc>
        bool operator!= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return !(lhs == rhs);
        }

    template <class T, class Alloc>
        bool operator<  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return (lhs < rhs);
        }

    template <class T, class Alloc>
        bool operator<= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return ( lhs <= rhs);
        }

    template <class T, class Alloc>
        bool operator>  (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return (lhs > rhs);
        }

    template <class T, class Alloc>
        bool operator>= (const Vector<T,Alloc>& lhs, const Vector<T,Alloc>& rhs)
        {
            return (lhs >= rhs);
        }
}

#endif