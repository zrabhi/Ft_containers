/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:08:35 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/04 20:03:24 by zrabhi           ###   ########.fr       */
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
                pointer         _end_c;
        public:
                explicit Vector(const allocator_type& alloc = allocator_type()) : 
                        _alloc(alloc),
                                _start(nullptr),
                                        _end(nullptr),
                                                _end_c(nullptr)
                                        {}
                //--Fill constructor-------
                explicit Vector(size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type())
                {
                        this->_alloc = alloc;        
                        this->_start = this->_alloc.allocate(n);
                        this->_end = this->_start;
                        this->_end_c = this->_start + n;
                        while (n--)
                        {
                                this->_alloc.construct(this->_end, val);
                                /// @brief printing the adress of each elements
                                /// @param n size of vector
                                /// @param val value of each elemts
                                /// @param alloc allocator 
                                std::cout << "Value is : "<< this->_end << std::endl; 
                                this->_end++;
                        }
                        // std::cout << "Value of start is : "<< *this->_start << std::endl; 
                }
                //------range constructor----
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
                        this->_end_c = this->_start + size;
                        this->_end = this->_start;
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
                        return (this->_end_c - this->_start);       
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

                size_type capacity() const
                {
                        if (this->size() >= this->_end_c - this->_start)
                                return (this->size() * 2);
                        return (this->size());
                }
                //Removes all elements form the vector and leavin the container with a size of 0
                void clear()
                {
                        this->_end--;
                        while (this->_end != this->_start)
                                this->_alloc.destroy(this->_end--);
                }
                //pop_back
                
                void pop_back()
                {
                     --this->_end;
                     this->_alloc.destroy(this->_end);
                }
                ///
                // void    pop_back()
                // {
                //         this->_end--;
                //         this->_alloc.destroy(this->_end);        
                // }
                
                void push_back(const value_type &val)
                {
                        pointer tmp = this->_start; 
                        size_type size = this->size() + 1;
                        this->clear();
                        this->_start = this->_alloc.allocate(size);             
                        this->_end   = this->_start;
                        this->_end_c = this->_start + size;                    
                        size = size - 1;
                        while (size--)
                        {
                             this->_alloc.construct(this->_end++, *tmp);
                             tmp++;   
                        }
                        this->_alloc.construct(this->_end++, val);
                }
                
                // Removes from the vector either a single element (position) or a range of elements([first, last]) 
                iterator erase(iterator position)
                {
                        if (position == this->end() - 1)
                                this->pop_back();
                        else
                        {
                                Vector   tmp(*this);
                                size_type size = this->size();
                                size_t i(-1); 
                                iterator nav = this->begin();
                                while (++i < size && this->_start != this->_end - 1)
                                {
                                        if (nav == position)
                                              tmp._start++, nav++, this->_alloc.destroy(this->_start);
                                  this->_start = tmp._start;
                                  this->_start++, tmp._start++, nav++;                       
                                }                                 
                        }
                  return (position);
                };

                iterator erase(iterator first, iterator last)
                {
                //    if (first != last)
                //    {
                //         iterator tmp = last;
                //         while (first != last && last--)
                                
                //    }     

                //   return (position);                                                                                              
                };
                void swap(Vector &x)
                {
                    Vector tmp(x);
                        
                } 
        };
}
#endif