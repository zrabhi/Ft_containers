/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:08:35 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/01 19:03:09 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <sstream>
# include <algorithm>
# include <vector>
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
                typedef typename  allocator_type::const_referncer                  const_reference;
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
                                                _end_c(nullptr),
                                        {};
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
                                this->_end++;
                        }
                }
                //------range constructor----
                template <class InputIterator>
                        Vector(InputIterator first, InputIterator last,
                             const_allocator_type& alloc = allocator_type())
                {
                        first = this->_start;
                        last =  this->_end;
                        //---not done yet                   
                        
                
                
                }
                        
                Vector(const Vector &x)
                {
                        if (x != *this)
                        {
                             this->_alloc.clear();
                                x.
                                this->_aloc()
                        }
                };
                
                ~vector()
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
                            
};

}
#endif