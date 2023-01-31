/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:09:03 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/31 07:47:17 by zrabhi           ###   ########.fr       */
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
          
          friend class ft::BidirectionalAccessIter<value_type, key_compare, __node, AVL, value_compare>;
          friend class ft::BidirectionalAccessRevIter<value_type, key_compare, __node, AVL, value_compare>;
          
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

                template <class InputIterator>
               map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : __tree(value_compare(comp)), __size(0)
               {
                    while (first != last)
                    {
                         __tree.AddLeaf(*first);
                         first++;
                    }
                    __tree.AddLeaf(*last);
               }
	
               map (map& x) : __tree(x.__tree)
               {
                    // clear();
                    // iterator  first = x.begin();
                    // std::cout << "jksjdks " << first->second << std::endl; 
                    // iterator  last = x.end();
                    insert(x.begin(), x.end());
                    // while (first != last)
                    // {
                    //      std::cout << "im hereee\n";
                    //      __tree.AddLeaf(*first);
                    //      first++;
                    // }
                    // __tree.AddLeaf(*last);
                    this->__size = x.size();
                    // __tree = x.__tree;
                    // __size = x.__size;
               }

                // //   std::pair<iterator, bool> @To remember;
               void     insert(const value_type& val)
               {
                    __tree.AddLeaf(val);
                    __size++;
               };
               iterator insert (iterator position, const value_type& val);

               template <class InputIterator>
               void insert (InputIterator first, InputIterator last)
               {
                    while (first != last)
                    {
                         __tree.AddLeaf(*first);
                         first++;
                    }
                    __tree.AddLeaf(*last);
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
                    while (first != last)
                    {
                         __tree.DeleteWithKey(first->first);
                         first++;
                    }
                    __tree.DeleteWithKey(last->first);

               }
               
               void erase(iterator position)
               {
                    std::cout << position->second << "djshdjs" << std::endl; 
                    __tree.DeleteWithKey(position->first);                 
               }

               
               void    clear()
               {
                    __tree.clearTree(__tree.root);
                    __tree.root = nullptr;
               }

               mapped_type& operator[] (const key_type& k)
               {
                    return ( __tree.findVal(k));
               }

               map& operator= (const map& x)
               {
                    __tree = x.__tree;
                    __size = x.size;
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
                    return iterator(__tree.lower_bound(k,  __tree.root), __tree.root);
               }

               iterator upper_bound (const key_type& k)
               {
                    return iterator(__tree.upper_bound(k, __tree.root), __tree.root);
               }

               pair<const_iterator,const_iterator> equal_range (const key_type& k) const
               {
                    return ft::make_pair(lower_bound(k), upper_bound(k));
               }

               pair<iterator,iterator>   equal_range (const key_type& k)
               {

                    return ft::make_pair(lower_bound(k), upper_bound(k));
               }
               
    };

    template <class Key, class T, class Compare, class Alloc>  
    bool operator == (ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs )
    {
         return lhs != rhs;
    }
    
     template <class Key, class T, class Compare, class Alloc>  
     bool operator!= (ft::map<Key,T,Compare,Alloc>& lhs,  ft::map<Key,T,Compare,Alloc>& rhs)
     { 
          std:: cout << "size ____ : " << rhs.size() << " " << lhs.size() << std::endl;
         if (lhs.size() != rhs.size())
               return (true);
          return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
     }

     template <class Key, class T, class Compare, class Alloc>  
     bool operator<  ( ft::map<Key,T,Compare,Alloc>& lhs,  ft::map<Key,T,Compare,Alloc>& rhs )
     {
          return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
     }

     template <class Key, class T, class Compare, class Alloc>  
     bool operator<= ( ft::map<Key,T,Compare,Alloc>& lhs,  ft::map<Key,T,Compare,Alloc>& rhs )
     {
          return !(lhs > rhs);
     }

     template <class Key, class T, class Compare, class Alloc>  
     bool operator>  (  ft::map<Key,T,Compare,Alloc>& lhs,  map<Key,T,Compare,Alloc>& rhs )
     {
          return lhs < rhs;
     }

     template <class Key, class T, class Compare, class Alloc>  
     bool operator>= (  ft::map<Key,T,Compare,Alloc>& lhs,  ft::map<Key,T,Compare,Alloc>& rhs )
     {
      return !(lhs < rhs);
     }
}



#endif