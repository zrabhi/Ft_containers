/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:09:03 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/17 15:06:33 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <map>
# include <utility>


/// @todo change std::less and std::pair with my implementation

namespace ft
{
template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T>> >
 class map {
    
    public:
            typedef std::pair<const Key, T>                     value_type;
            typedef     key                                     key_type;
            typedef     T                                       mapped_type;
            typedef    Compare                                  key_compare;
            //---- Nested fucntion to campare elements;
            typedef     Allocator                               allocator_type;
            typedef             std::size_t                     size_type; 
            typedef typename    allocator_type::reference       reference;
            typedef typename    allocator_type::const_reference const_reference;
            typedef typename    allocator_type::pointer         pointer;
            typedef typename    allocator_type::const_pointer   const_pointer;
    };


}


#endif