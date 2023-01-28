/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:09:03 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/28 23:26:44 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <map>
# include <utility>
# include "iterator_map.hpp"
# include "../utils/ft_utility.hpp"
# include "../AvlTree/AvlTree.hpp"



/// @todo change std::less and std::pair with my implementation

namespace ft
{
template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
 class map {
    
    public:
            typedef             T                                                     mapped_type;
            typedef             Key                                                   key_type;
            typedef             Compare                                               key_compare;
            typedef             Allocator                                             allocator_type;
            typedef             std::size_t                                           size_type; 
            typedef             ft::pair<const key_type, mapped_type>                 value_type;
            typedef             ft::pair<const key_type, mapped_type>                 const_value_type;  
            typedef typename    allocator_type::reference                             reference;
            typedef typename    allocator_type::const_reference                       const_reference;
            typedef typename    allocator_type::pointer                               pointer;
            typedef typename    allocator_type::const_pointer                         const_pointer;
            typedef typename    ft::BidirectionalAccessIter<value_type>               iterator;
            typedef typename    ft::BidirectionalAccessIter<const_value_type>         const_iterator;
            // typedef typename  ft::BidirectionalAccessIterRev<value_type>              reverse_iterator;
            // typedef typename  ft::BidirectionalAccessIterRev<const_value_type>        const_reverse_iterator;
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
        typedef typename    ft::AvlTree<value_type, value_compare, key_type, mapped_type>         AVL;
    private:
        AVL             __tree;
        size_type       __size;
        allocator_type  __alloc;
    public:
               explicit map (const key_compare& comp = key_compare(),
                const allocator_type& __alloc = allocator_type()) : __tree(value_compare(comp)), __size(0)
                {};
                void    printer()
                {
                    __tree.PrintTree();
                } ;
                // //   std::pair<iterator, bool> @To remember;
               void     insert(const value_type& val)
               {
                    __tree.AddLeaf(val);
                    __size++;
               };

               //-----allocatore getter
               allocator_type get_allocator() const
               {
                    return (__alloc);
               };

               //// Empty 
               bool empty() const
               {
                    return (__tree.empty());
               };

               size_type  max_size() const
               {
                    return (__alloc.max_size());
               };

               size_type    size() const
               {
                    return (__size);
               };  

               size_type    erase(const key_type& k)
               {
                    __tree.DeleteWithKey(k);
                    return (__size--, 1);
               }
               
               void    clear()
               {
                    
               }

               mapped_type& operator[] (const key_type& k)
               {
                    return ( __tree.findVal(k));
               }

               size_type count (const key_type& k) 
               {
                    return __tree.count(k);
               }
            
    };
}


#endif