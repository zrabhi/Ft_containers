/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:04:04 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/11 18:33:08 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP



// #include "iterator_map_traits.hpp"
#include "../iterator/iteretor_traits.hpp"
namespace ft
{
    template <class T, class Node>
    class BidirectionalAccessIter : public ft::iterator<std::bidirectional_iterator_tag, T>
     {
         
        public:
            typedef T                                                                                                                    _type;
            typedef Node                                                                                                                 node;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::value_type                       value_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::Distance                         difference_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::pointer                          pointer;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::reference                        reference;
            typedef typename    ft::iterator_traits<ft::iterator<std::bidirectional_iterator_tag, T> >::iterator_category                iterator_category;
            typedef typename    ft::BidirectionalAccessIter<T, node>                                                                     __return_type;
        protected: 
            node             *__ptr;
        public:
          
            
            BidirectionalAccessIter(node *_n) :  __ptr(_n)
            {
            };

            BidirectionalAccessIter() : __ptr(nullptr)
            {};
            
            BidirectionalAccessIter(const __return_type& obj) 
            {
                *this = obj;
            };

            ~BidirectionalAccessIter()
            {
                
            }

            __return_type  operator++()
            {
                if (__ptr->__right)
                {
                    __ptr = __min(__ptr->__right);
                    return (*this);
                }
                __ptr = __upper(__ptr);
                return ( *this);
            } 
            
            __return_type operator++(int)
            {
                __return_type __tmp = *this;
                operator++();
                return __tmp;
            }

            __return_type operator--()
            {
               if (__ptr->__left)
                {
                    __ptr = __max(__ptr->__left);
                    return (*this);
                }
                __ptr = upper(__ptr);
                return ( *this);
            }

            __return_type operator--(int)
            {
                __return_type __tmp = *this;
                operator--();
                return __tmp;
            }
            
            __return_type &operator=(__return_type const  &pr)
            {
                if (*this == pr)
                    return (*this);
                __ptr    = pr.__ptr;
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
            
            bool operator==(const __return_type& pr) const
            {
                
                return (__ptr == pr.__ptr);
            } 

            bool operator!=(const __return_type& pr) const
            {
    
                return (__ptr != pr.__ptr);
            }
        
        private:

            node* __min(node *__node)
		    { 
			    node* current = __node;
                if (__node) 
                {
			        while (current->__left != NULL) 
			    	    current = current->__left;
                }
			    return current;
		    }

            node* __upper(node* __ptr)
		    {
                while (!__ptr->isLeft()) 
                    __ptr = __ptr->__parent;
                __ptr = __ptr->__parent;
               return (__ptr);
		    }
            
            node*  upper(node* __ptr)
		    {
                while (!__ptr->isRight()) 
                    __ptr = __ptr->__parent;
                __ptr = __ptr->__parent;
               return (__ptr);
		    }
          
            node* __max(node *__node)
		    {
			    node* current = __node;
    
			    while (current->__right)
			    	current = current->__right;
			    return current;
		    }

};    
}

# endif