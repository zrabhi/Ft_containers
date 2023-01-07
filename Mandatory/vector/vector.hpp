/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:08:35 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/07 19:32:56 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <vector>
# include <memory>
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
                
                // Vector(){}; 
                //--Default constructor------
        private:
                allocator_type  _alloc;       
                pointer         _start;
                pointer         _end;
                size_type       _capacity;
                void    _extra_capacity(size_type n, pointer tmp, size_type size)
                {       
                        _start = _alloc.allocate(n);
                        _end = _start;
                        for(size_t i = 0; i < size; i++)
                        {
                                _alloc.construct(_end++, tmp[i]);
                        }
                        for (size_t i = 0; i < size; i++)
                        {
                                _alloc.destroy(tmp + i);
                        }
                        _alloc.deallocate(tmp, size);             
                }
                void    _double( void )
                {
                        _capacity *= 2;
                        if (_capacity == 0)
                                _capacity = 1;
                }
                
        public:
                explicit Vector(const allocator_type& alloc = allocator_type()) : 
                        _alloc(alloc),
                                _start(nullptr),
                                        _end(nullptr),
                                                _capacity(0)
                                        {}
                //--Fill constructor-------
                /// @brief printing the adress of each elements
                /// @param n size of vector
                /// @param val value of each elemts
                /// @param alloc allocator
                explicit Vector(size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type())
                {
                        this->_alloc = alloc;
                        this->_start = this->_alloc.allocate(n);
                        this->_end = this->_start;
                        this->_capacity = n;
                        while (n--)
                                this->_alloc.construct(this->_end++, val);
                }
                // ------range constructor----
                // template <class InputIterator>
                //         Vector(InputIterator first, InputIterator last,
                //              const allocator_type& alloc = allocator_type())
                // {  
                //         // first =  this->_start;
                //         // last  =  this->_end;
                //         //---not done yet                   
                        
                
                
                // }
                
                ///--Cpy constructor      
                Vector(const Vector &x)
                {
                        size_type size = x.size();        
                        this->_alloc = x._alloc;
                        this->_start = this->_alloc.allocate(size);
                        this->_end = this->_start;
                        this->_capacity = x._capacity;
                        for (size_t i = 0; i < size; i++)
                        {
                               this->_alloc.construct(this->_end++, x[i]);
                        }   
                };
                
                ~Vector()
                {};
                            
                iterator begin()
                {
                        return (this->_start);        
                }
                
                iterator end()
                {
                        return (this->_end);
                }
                
                const_iterator begin() const
                {
                        return (this->_start);
                }
                
                const_iterator end() const
                {
                        return (this->_end);
                }
                
                reverse_iterator rbegin()
                {
                        return (this->_end);
                }
                
                reverse_iterator rend()
                {
                        return (this->_start);        
                }
                
                const_reverse_iterator rend() const
                {
                        return (this->_start);      
                }
                
                const_reverse_iterator rbegin() const
                {
                        return (this->_end);
                }
                
                size_type       size() const
                {
                        return (this->_end - this->_start);
                }

                size_type max_size() const
                {
                        return (this->_alloc.max_size());       
                }
                
                reference at(size_type n)
                {
                        if (n >= this->size())
                                throw std::out_of_range("Vector::at: index out \
                                        of range");
                        return (this->_start[n]);
                }
                
                const_reference at(size_type n) const
                {
                        if (n >= this->size())
                                throw std::out_of_range("Vector::at: index out \
                                        of range");
                        return (this->_start[n]);    
                }
                
                reference operator[](size_type n)
                {
                        return (this->_start[n]);
                }
                
                const_reference operator[](size_type n) const
                {
                        return (this->_start[n]);
                }   
                
                bool empty()
                {
                        if (this->size())
                                return (true);
                        return (false);
                }    
                //--- get allocator_object
                allocator_type get_allocator() const 
                {
                        return (this->_alloc);
                }
                //----- element accessing (front, back)
                reference front()
                {
                        return (this->_start);
                }

                const_reference front() const 
                {
                        return (this->_start);
                }
                 
                reference back()
                {
                        return (this->_end - 1);
                }
                
                const_reference back() const 
                {
                        return (this->_end - 1);        
                } 
                ///////////////////////////////////

                size_type capacity()
                {         
                        return (_capacity);
                }
                //Removes all elements form the vector and leavin the container with a size of 0
                void clear()
                {
                        this->_end--;
                        while (this->_end != this->_start)
                                this->_alloc.destroy(--this->_end);
                        this->_alloc.destroy(this->_end);
                }
        
                void push_back(const value_type &val)
                {
                        if (size() == _capacity)
                        {
                               _double();
                                pointer tmp = _start; 
                                // clear();
                                _extra_capacity(_capacity, tmp, size());
                        }
                        _alloc.construct(_end++, val);
                }
                
                // void    resize(size_type n, value_type = value_type())
                // {
                //         if (n < this->size())
                //                 this->_alloc.destroy(this->_start + n);
                //         if (n > this->size())
                //         {
                //                 // this->_start = 
                //                 for (size_t i = this->size(); i < n; ++i)
                //                 {
                //                         this->_alloc.allocate()
                //                 }
                //         }
                // } 

                void    reserve(size_type n)
                {
                        if (n > max_size())
                                throw std::length_error("Greater than max_size");
                        if (n > _capacity)
                        {
                                /// reallocate the storage;
                                pointer ptr = this->_start;
                                size_type size = this->size();
                                this->clear();
                                this->_start = this->_alloc.allocate(n);                    
                                this->_end = this->_end;
                                this->_end_c = this->_start + n;
                                for (size_t i = 0; i < size; i++)
                                {
                                        this->_alloc.construct(this->_end[i], ptr[i]);
                                }
                        } 
                }         
                
                // Removes from the vector either a single element (position) or a range of elements([first, last]) 
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
}


#endif