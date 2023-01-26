/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:09:03 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/26 15:23:10 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <map>
# include <utility>
# include "../utils/ft_utility.hpp"
# include "../AvlTree/AvlTree.hpp"



/// @todo change std::less and std::pair with my implementation

namespace ft
{
template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T>> >
 class map {
    
    public:
            typedef     key                                     key_type;
            typedef     T                                       mapped_type;
            typedef     ft::pair<const key_type, mapped_type>   value_type;
            typedef     Compare                                 key_compare;
            //---- Nested fucntion to campare elements;
            typedef             Allocator                       allocator_type;
            typedef             std::size_t                     size_type; 
            typedef typename    allocator_type::reference       reference;
            typedef typename    allocator_type::const_reference const_reference;
            typedef typename    allocator_type::pointer         pointer;
            typedef typename    allocator_type::const_pointer   const_pointer;
            typedef typename    ft::AvlTree<value_type>         ___tree;
    private:
    };
}


#endif