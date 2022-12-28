/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:09:51 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/28 16:57:12 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITEARTOR_HPP
#include "iteretor_traits.hpp"
#include <iterator>


namespace ft
{
    template<typename T>
    class RandomAcessIter : public ft::iterator_traits<std::random_access_iterator_tag, T>
    {
        public:
            typedef T                                                       Iterator;
            typedef typename    ft::iterator_traits<T>::value_type          value_type;
            typedef typename    ft::iterator_traits<T>::Distance            Distance;
            typedef typename    ft::iterator_traits<T>::pointer             pointer;
            typedef typename    ft::iterator_traits<T>::reference           reference;
            typedef typename    ft::iterator_traits<T::iterator_category    iterator_category;
        protected :
            Iterator    current;
        RandomAcessIter(){}
         
    };
}

#endif