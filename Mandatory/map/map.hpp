/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:09:03 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/02 08:07:41 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include <map>
# include <utility>
# include "iterator_map.hpp"
# include "../utils/ft_algorithm.hpp"

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
          typedef typename    ft::map<Key, T, Compare>                              __map;
          
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
          typedef typename    ft::AvlTree<value_type, value_compare, key_type, mapped_type, __map>                    AVL;
          typedef typename    ft::AvlTree<value_type, value_compare, key_type, mapped_type, __map>::node              __node;
          typedef typename    ft::BidirectionalAccessIter<value_type, key_compare, __node, AVL, value_compare>                iterator;
          typedef typename    ft::BidirectionalAccessIter<const_value_type, key_compare, __node, AVL, value_compare>              const_iterator;
          typedef typename    ft::BidirectionalAccessRevIter<value_type, key_compare, __node, AVL, value_compare>                 reverse_iterator;          
          typedef typename    ft::BidirectionalAccessRevIter<const_value_type, key_compare, __node, AVL, value_compare>                const_reverse_iterator;
          typedef typename    ft::map<Key, T, Compare, Allocator>                                                                       __class_type;
          friend class ft::BidirectionalAccessIter<value_type, key_compare, __node, AVL, value_compare>;
          friend class ft::BidirectionalAccessRevIter<value_type, key_compare, __node, AVL, value_compare>;
          
    private:
        AVL               __tree;
        value_compare     __comp;
        size_type         __size;
        allocator_type    __alloc;
    public:  
               explicit map (const key_compare& comp = key_compare(),
               const allocator_type& alloc = allocator_type()) : __tree(value_compare(comp)), __comp(value_compare(comp)), __size(0), __alloc(alloc)
               {
                    
               };
                //// to be removed later------
               void    printer()
               {
                    __tree.PrintTree();
               };
               ~map();
               

               template <class InputIterator>
               map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : __tree(value_compare(comp)), __size(0), __alloc(alloc)
               {
                    if (first == last)
                         return ;
                    while (first != last)
                    {
                         __tree.AddLeaf(*first);
                         first++;
                    }
                    __tree.AddLeaf(*last);
               }
	
               map (const map& x, const key_compare& comp = key_compare()) : __tree(comp), __comp(comp)
               {
                    clear();
                    insert(x.begin(), x.end());
                    this->__size = x.size();
               }

               //    std::pair<iterator, bool> @To remember;
               ft::pair<iterator, bool>  insert(const value_type& val)
               {
                   __node* __tmp = __tree.ReturnNode(val.first, __tree.root);
                    if (__tmp)
                          return (ft::make_pair<iterator, bool>(iterator(__tmp, __tree.root), false));
                    __tree.AddLeaf(val);
                    __size++;
                    return (ft::make_pair<iterator, bool>(iterator(__tmp, __tree.root), true));
               };
               
               iterator insert (iterator position, const value_type& val);

               template <class InputIterator>
               void insert (InputIterator first, InputIterator last)
               {
                    if (first == last)
                         return ;
                    for (;first != last; first++)
                    {
                         insert(*first);
                    }
                    insert(*last);
               }
               
               allocator_type get_allocator() const
               {
                    return (__alloc);
               };

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
               
               void erase (iterator first, iterator last)
               {
                    if (first == last)
                         return ;  
                    for(; last != first; last--)
                    {
                         __tree.DeleteWithKey(last->first);
                         __size--;
                    }
                    __tree.DeleteWithKey(last->first);
                    __size--;

               }
                    
               void erase(iterator position)
               {
                    __tree.DeleteWithKey(position->first);
                    __size--;                
               }

               void swap (map& x)
               {
                    ft::swap(*this, x);
               }
               
               //// bug in this function and leaks 
               void    clear()
               {
                    if (__tree.root)
                        {     
                              erase(begin(), end());
                              __tree.clearTree(__tree.root);
                              __tree.root = nullptr;
                        }
                        
               }

               mapped_type& operator[] (const key_type& k)
               {
                    return ( __tree.findVal(k));
               }

               map& operator= (map const &x)
               {
                    clear();
                    insert(x.begin(), x.end());               
                    __size = x.size();
                    return (*this);
               }

               size_type count (const key_type& k) 
               {
                    return __tree.count(k);
               }

               iterator begin()
               {
                    return  iterator(__tree.returnBegin(), __tree.root);
               }

               const_iterator begin() const 
               {
                    return const_iterator(__tree.returnBegin(), __tree.root);
               }

               const_iterator end() const 
               {
                    return const_iterator(__tree.returnEnd(), __tree.root);
               }
               
               iterator end()
               {
                    return iterator(__tree.returnEnd(), __tree.root);
               }

               reverse_iterator rbegin()
               {
                    return   reverse_iterator(__tree.returnEnd(), __tree.root);
               }
               
               const_reverse_iterator rbegin() const
               {
                    return const_reverse_iterator(__tree.returnEnd(), __tree.root);
               }

               const_reverse_iterator rend() const
               {
                    return const_reverse_iterator(__tree.returnEnd(), __tree.root);
               }

               reverse_iterator rend()
               {
                    return reverse_iterator(__tree.returnBegin(),__tree.root);
               }

            
               iterator find (const key_type& k)
               {
                    return iterator(__tree.ReturnNodePublic(k), __tree.root);     
               }

               const_iterator find (const key_type& k) const
               {
                    return iterator(__tree.ReturnNodePublic(k), __tree.root);
               }

               iterator lower_bound (const key_type& k)
               {
                    iterator __beging = begin();
                    iterator __end = end();
                    for (; __beging != __end; __beging++)
                    {
                         if (k <= __beging->first)
                              break;     
                    }
                    return (__beging);
               }
               
               const_iterator lower_bound (const key_type& k) const
               {
                    const_iterator __beging = begin();
                    const_iterator __end = end();
                    for (; __beging != __end; __beging++)
                    {
                         if (k <= __beging->first)
                              break;     
                    }
                    return (__beging);
               }

               iterator upper_bound(const key_type& k)
               {
                    iterator __beging = begin();
                    iterator __end = end();
                    for (; __beging != __end; __beging++)
                    {
                         if (k <  __beging->first)
                              break;     
                    }
                    return (__beging);
               }
                
               const_iterator upper_bound(const key_type& k) const
               {
                    const_iterator __beging = begin();
                    const_iterator __end = end();
                    for (; __beging != __end; __beging++)
                    {
                         if (k < __beging->first)
                              break;     
                    }
                    return (__beging);
               }
               
               pair<const_iterator,const_iterator> equal_range (const key_type& k) const
               {
                    return ft::make_pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
               }

               pair<iterator,iterator>   equal_range (const key_type& k)
               {
                    return ft::make_pair<iterator,iterator>(lower_bound(k), upper_bound(k));
               }
               
    };

    template <class Key, class T, class Compare, class Alloc>  
    bool operator == (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs )
    {
         return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    
     template <class Key, class T, class Compare, class Alloc>  
     bool operator!= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
     { 
          std::cout << lhs.size() << " ; " << rhs.size() << std::endl;
         if (lhs.size() != rhs.size())
               return (true);
          return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
     }

     template <class Key, class T, class Compare, class Alloc>  
     bool operator<  (const ft::map<Key,T,Compare,Alloc>& lhs,  const ft::map<Key,T,Compare,Alloc>& rhs)
     {
          return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
     }

     template <class Key, class T, class Compare, class Alloc>  
     bool operator<= ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
     {
          return !(lhs > rhs);
     }

     template <class Key, class T, class Compare, class Alloc>  
     bool operator>  ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
     {
          return lhs < rhs;
     }

     template <class Key, class T, class Compare, class Alloc>  
     bool operator>= ( const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
     {
      return !(lhs < rhs);
     }
}



#endif