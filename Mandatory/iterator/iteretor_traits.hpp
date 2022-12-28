/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteretor_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 10:25:14 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/28 10:29:36 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP


namespace ft
{
    template<class Iterator>
    struct iterator_traits
    {
        typedef typename Iterator::diferrence_type      Distance
        typedef typename Iterator::value_type           value_type;
        typedef typename Iterator::pointer              pointer;
        typedef typename Iterator::reference            reference;
        typedef typename Iterator::iterator_categorty            
    };
    
}

#endif