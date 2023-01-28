/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:04:04 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/28 22:44:24 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP



#include "iterator_map_traits.hpp"
namespace ft 
{
    template <typename T>
    class BidirectionalAccessIter : public ft::iterator<std::bidirectional_iterator_tag, T>
    {
        public:
            typedef T                                                                                                           Iterator;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::value_type              value_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::Distance                difference_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::pointer                 pointer;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::reference               reference;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::iterator_category       iterator_category;
        protected:
            pointer __ptr;
        public:
            BidirectionalAccessIter() : __ptr(nullptr)
            {};
            
            BidirectionalAccessIter(const BidirectionalAccessIter<T>& obj) : __ptr(obj.__ptr)
            {}

            reference   operator*() const
            {
                return (*__ptr);
            }
    
    };    
}




#endif