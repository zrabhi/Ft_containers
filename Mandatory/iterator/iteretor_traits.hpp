/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteretor_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:25:14 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/29 15:14:53 by zakaria          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP

///  --random....access
namespace ft
{
        template <class Category, class T, class Distance = std::ptrdiff_t,
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
        typedef typename Iterator::iterator_category     iterator_category ;      
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
    template<class T>
    struct iterator_traits<const T*>
    {
        typedef const T                                     value_type;
        typedef const *T                                    pointer;
        typedef const T&                                    reference;
        typedef typename std::random_access_iterator_tag    iterator_category;
        typedef typename std::ptrdiff_t                     difference_type;
    } ;
}

#endif