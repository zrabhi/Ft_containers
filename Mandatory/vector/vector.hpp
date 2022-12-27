/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:08:35 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/27 12:50:34 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <sstream>
#include <algorithm>
# include <vector>
namespace ft
{   
    template <class T, class Allocator = std::allocator<T> >
    class Vector {
            public:
                typedef T                                             value_type;
                typedef Allocator                                     allocator_type
                typedef typename  allocator_type::size_type           size_type;
                typedef typename  allocatore_type::reference          reference;
                typedef typename  allocator_type::const_referncer     const_reference;
                typedef typename  allocator_type::const_pointer       const_pointer;
                typedef typename  allocator_type::pointer             pointer;
                typedef typename  __vector_iterator<pointer>          iterator;  
                typedef typename  __vector_iterator<const_iterator>   const_iterator;
                typedef typename  ft::reverse_iterator<const_pointer> reverse_iterator;
                typedef typename  ft::reverse_iterator<const_pointer> const_reverse_iterator
                typedef typename  allocator_type::difference_type     difference_type;
                
                // Vector(){}; 
                //--Default constructor------
                explicit Vector(const allocator_type& alloc = allocator_type()){
                    
                }
                //--Fill constructor-------
                explicit Vector(size_type n, const value_type& val = value_type(),
                         const allocator_type& alloc = allocator_type())
                {

                }
                //------range constructor----
                template <class InputIterator>
                        Vector(InputIterator first, InputIterator last,
                             const_allocator_type& alloc = allocator_type());
                        {
                                        
                        }
                Vector(const vector &x);
        private:
                T*              _vector;       
                size_type       size;
                pointer        _begin;
                pointer        _end;
                
                
                
};

}
#endif