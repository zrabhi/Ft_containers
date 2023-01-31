/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:04:04 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/31 04:39:40 by zakaria          ###   ########.fr       */
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
            BidirectionalAccessIter(node *_n, node *__root,  const key_compare& comp = key_compare()) : __ptr(_n), __tree(value_compare(comp))
            {
                __tree.root = __root;
            };
            BidirectionalAccessIter(const key_compare& comp = key_compare()) : __ptr(nullptr), __tree(value_compare(comp))
            
            
            {};
            
            BidirectionalAccessIter(const BidirectionalAccessIter<T, Compare, Node, AvlTree, value_compare>& obj) : __ptr(obj.__ptr), __tree(obj.__tree)
            {}


            __return_type  operator++()
            {

                
                // std::cout << __ptr->__parent->__key.first << std::endl;
                // __tree.PrintTree();
                __ptr = __tree.forward(__ptr);
                // std::cout << "im hereee " <<  std::endl;
                return (*this);
                // node *current = __ptr->__right;
                // while (current->__left)
                //     current = current->__left;
                // __ptr = current;
                // //----case most left node have a left child;
                // std::cout << "__ptr parent is " << __ptr->__parent->__key.first << std::endl;
                // if (__ptr->__right)
                // {
                //     __ptr = __ptr->__right;
                //     while (__ptr && __ptr->__left)
                //         __ptr = __ptr->__left;
                // }
                // else
                // {
                //     // while ()
                //     __ptr = __tree.FindOldest(__tree.root,__ptr);
                //     std::cout << "value oF oldest :" << __ptr->__key.first << std::endl;
                
                // }
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
                __ptr = __tree.backward(__ptr);
                return *this;
            }

            __return_type operator--(int);
            __return_type &operator=(__return_type const  &pr)
            {
                __tree  = pr.__tree;
                
                std::cout << "operator " << pr.__tree.root->__key.first << std::endl;
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
            __return_type  operator++(void);
            
            __return_type operator++(int);

            __return_type operator--();

            __return_type operator--(int);
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