/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:09:03 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/27 23:42:30 by zrabhi           ###   ########.fr       */
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
template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
 class map {
    
    public:
            typedef     Key                                               key_type;
            typedef     T                                                 mapped_type;
            typedef     ft::pair<const key_type, mapped_type>            value_type;
            typedef     Compare                                           key_compare;
            //---- Nested fucntion to campare elements;
            typedef             Allocator                       allocator_type;
            typedef             std::size_t                     size_type; 
            typedef typename    allocator_type::reference       reference;
            typedef typename    allocator_type::const_reference const_reference;
            typedef typename    allocator_type::pointer         pointer;
            typedef typename    allocator_type::const_pointer   const_pointer;
        /// nested class as a fucntion object
        class value_compare
        {
            typedef   value_type    first_argument_type;
            typedef   value_type    second_argument_type;   
            typedef   bool          result_type;
            protected:
                key_compare       comp;
            public:
                value_compare(key_compare _c) : comp(_c){}
                bool    operator()(const first_argument_type& __x, const second_argument_type& __y) const
                {
                        return comp(__x.first, __y.first);
                }
            friend class map;
        };
        typedef typename    ft::AvlTree<value_type, value_compare>         AVL;
        AVL             __tree;
        allocator_type  _alloc;
        
        public:
               explicit map (const key_compare& comp = key_compare(),
                const allocator_type& _alloc = allocator_type()) : __tree(value_compare(comp))
                {}
                void    printer()
                {
                    __tree.PrintTree();
                } 
                // //   std::pair<iterator, bool> @To remember;
               void     insert(const value_type& val)
               {
                    __tree.AddLeaf(val);
               }

               //-----allocatore getter
               allocator_type get_allocator() const
               {
                    return (_alloc);
               }

               //// Empty 
               bool empty() const
               {
                    return (__tree.empty());
               }

               size_type  max_size() const
               {
                    return (_alloc.max_size());
               }
                    
                          
    };
}


#endif