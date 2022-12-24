/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:08:35 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/24 17:55:58 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector.hpp
# define vector.hpp

#include <iostream>
#include <sstream>
#include <algorithm>
# include <vector>
namespace ft
{   
    template <class T, class Allocator = std::allocator<T> >
    class Vector {
            public:
                typedef T                                            value_type;
                typedef Allocator                                    allocator_type
                typedef typename  allocatore_type::reference         reference;
                typedef typename  allocator_type::const_referncer    const_reference;
                typedef typename  implementation-defined             iterator;  
                typedef typename  implementation-defined             const_iterator; 
                typedef typename  allocator_type::pointer            pointer;
                typedef typename  allocator_type::const_pointer      const_pointer;
                Vector(){}; 
                Vector()
                    


};

}
#endif