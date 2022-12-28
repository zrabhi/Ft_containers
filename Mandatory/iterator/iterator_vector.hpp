/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:09:51 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/28 11:10:53 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITEARTOR_HPP

#include <iterator>
namespace ft
{
    template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
  };

    template<class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::diferrence_type       Distance
        typedef typename Iterator::value_type            value_type;
        typedef typename Iterator::pointer               pointer;
        typedef typename Iterator::reference             reference;
        typedef typename Iterator::iterator_categorty    iterator_categorty ;      
    };
    template<class T> 
    struct iterator_traits<T*>
    {
        typedef T                                           value_type;
        typedef *T                                          pointer;
        typedef T&                                          reference;
        typedef  typename std::random_access_iterator_tag   iterator_category;   
        typedef  typename std::ptrdiff_t                    difference_type;
    };
        

}



#endif