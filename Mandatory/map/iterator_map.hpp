/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:04:04 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/03 10:10:02 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP



#include "iterator_map_traits.hpp"
namespace ft
{
    template <class T, class Compare, class Node, class AvlTree, class value_compare>
    class BidirectionalAccessIter : public ft::iterator<std::bidirectional_iterator_tag, T>
     {
         
        public:
            typedef Node                                                                                                                node;
            typedef AvlTree                                                                                                             tree;
            typedef Compare                                                                                                             key_compare;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::value_type                      value_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::Distance                         difference_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::pointer                          pointer;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::reference                        reference;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::iterator_category                iterator_category;
            typedef typename    ft::BidirectionalAccessIter<T, Compare, node, tree, value_compare>                                       __return_type;
        
        protected:
            tree    __tree;    
            node    *__ptr;
        public:
        
           // // to be removed
            BidirectionalAccessIter(node *_n, node *__root,  const key_compare& comp = key_compare()) :  __tree(value_compare(comp)),__ptr(_n)
            {
                __tree.root = __root;
            };
            BidirectionalAccessIter(const key_compare& comp = key_compare()) : __tree(value_compare(comp)), __ptr(nullptr)
            
            
            {};
            
            BidirectionalAccessIter(const BidirectionalAccessIter<T, Compare, Node, AvlTree, value_compare>& obj) :  __tree(obj.__tree), __ptr(obj.__ptr)
            {};


            __return_type  operator++()
            {
                if (__ptr == __tree.__last_element)
                {
                    __ptr = __tree.__last_element->__right;
                    return (*this);
                }
                __ptr = __tree.forward(__ptr);
                return (*this);
            }
            
            __return_type operator++(int)
            {
                __return_type __tmp = *this;
                operator++();
                return __tmp;
            }

            __return_type operator--()
            {
                if (__ptr == __tree.__last_element)
                {
                    __ptr = __tree.__last_element->__right;
                    return (*this);
                }
                __ptr = __tree.backward(__ptr);
                return *this;
            }

            __return_type operator--(int)
            {
                 __return_type __tmp = *this;
                operator--();
                return __tmp;
            }
            __return_type &operator=(__return_type const  &pr)
            {
                __tree  = pr.__tree;
                
                __ptr = pr.__ptr;
                return *this;    
            }
            
            reference   operator*() const
            {
                return (__ptr->__key);
            }

            pointer     operator->() const
            {
                return &__ptr->__key;
            }
            
            bool operator==(const BidirectionalAccessIter& pr) const
            {
                
                return (__ptr == pr.__ptr);
            } 

            bool operator!=(const BidirectionalAccessIter& pr) const
            {
                return (__ptr != pr.__ptr);
            }
    };    


     template <class T, class Compare, class Node, class AvlTree, class value_compare>
    class BidirectionalAccessRevIter : public ft::iterator<std::bidirectional_iterator_tag, T>
     {
         
        public:
            typedef Node                                                                                                                node;
            typedef AvlTree                                                                                                             tree;
            typedef Compare                                                                                                             key_compare;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::value_type                      value_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::Distance                         difference_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::pointer                          pointer;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::reference                        reference;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::iterator_category                iterator_category;
            typedef typename    ft::BidirectionalAccessRevIter<T, Compare, node, tree, value_compare>                                    __return_type;
        protected:
            tree    __tree;    
            node    *__ptr;
        public:
        
           // // to be removed
            BidirectionalAccessRevIter(node *_n, node *__root,  const key_compare& comp = key_compare()) : __ptr(_n), __tree(value_compare(comp))
            {
                __tree.root = __root;
            };
            BidirectionalAccessRevIter(const key_compare& comp = key_compare()) : __ptr(nullptr), __tree(value_compare(comp))
            
            
            {};
            
            BidirectionalAccessRevIter(const BidirectionalAccessIter<T, Compare, Node, AvlTree, value_compare>& obj) : __ptr(obj.__ptr), __tree(obj.__tree)
            {}
            __return_type  operator++()
            {
                __ptr = __tree.backward(__ptr);
                return *this;
            }
            
            __return_type operator++(int)
            {
                __return_type __tmp = *this;
                operator++();
                return __tmp;
            }

            __return_type operator--()
            {
                __ptr = __tree.forward(__ptr);
                return (*this);
            }

            __return_type operator--(int)
            {
                __return_type __tmp = *this;
                operator--();
                return __tmp;
                
            }
            __return_type &operator=(_BidirectionalAccessRevIter& const  &pr)
               {
                   __tree  = pr.__tree;
                   __ptr = pr.__ptr;
                   return *this;    
            }
            
            reference   operator*() const
            {
                return (__ptr->__key);
            }

            pointer     operator->() const
            {
                return &__ptr->__key;
            }
            
            bool operator==(const BidirectionalAccessRevIter& pr) const
            {
                return (__ptr == pr.__ptr);
            } 

            bool operator!=(const BidirectionalAccessRevIter& pr) const
            {
                return (__ptr != pr.__ptr);
            }
    };    

}





#endif