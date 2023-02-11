/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 23:09:03 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/11 14:04:14 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <memory>
# include "iterator_map.hpp"
# include "../iterator/reverse_iterator.hpp"
# include "../utils/ft_algorithm.hpp"

# include "../utils/ft_utility.hpp"
# include "../AvlTree/AvlTree.hpp"

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
          typedef typename    ft::AvlTree<value_type, value_compare, key_type, mapped_type>                                  AVL;
          typedef typename    ft::AvlTree<value_type, value_compare, key_type, mapped_type>::node                            __node;
          typedef typename    ft::BidirectionalAccessIter<value_type,  __node>                                               iterator;
          typedef typename    ft::BidirectionalAccessIter<const_value_type, __node>                                          const_iterator;
          typedef typename    ft::reverse_iterator<iterator>                                                                 reverse_iterator;    
          typedef typename    ft::reverse_iterator<const_iterator>                                                           const_reverse_iterator;
          typedef typename    ft::map<Key, T, Compare, Allocator>                                                            __class_type;
          typedef typename    allocator_type::template rebind<AVL>::other                                                    __tree_allocatore;
          friend              class ft::BidirectionalAccessIter<value_type,  __node>;
          friend              class ft::reverse_iterator<iterator>;

    private:
        AVL               __tree;
        value_compare     __comp;
        size_type         __size;
        __tree_allocatore __alloc_tree;
        allocator_type    __alloc;
        __node            *__last;

    public:
               explicit map (const allocator_type& alloc = allocator_type()) : __tree(value_compare(key_compare())), __comp(value_compare(key_compare())), __size(0), __alloc(alloc), __last(nullptr)
               {
                    __last  =  __tree.creatleaf(value_type());
                    __tree.__last_element = __last;
               };
             
               
               void    printer()
               {
                    __tree.PrintTree();
               };
               
               ~map()
               {
                    __alloc.destroy(&__last->__key);
                    __tree.get_allocatore().deallocate(__last, 1);
               }
               

               template <class InputIterator>
               map (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : __tree(value_compare(key_compare())), __size(0), __alloc(alloc), __comp(value_compare(key_compare())), __last(nullptr)
               {
                    if (first == last)
                         return ;
                    while (first != last)
                    {
                         __tree.AddLeaf(*first);
                         __size++;
                         first++;
                    }
                    __tree.AddLeaf(*last);
               }
	
               map (const map& x) : __tree(value_compare(key_compare())), __comp(value_compare(key_compare()))
               {
                    *this = x;
               }

               // // Hint position
              iterator insert (iterator position, const value_type& val)
               {
                    (void)position;
                    return (insert(val).first);
               }

               ft::pair<iterator, bool>  insert(const value_type& val)
               {
                    __node* __tmp = __tree.ReturnNode(val.first, __tree.root);
                    if (__tmp && __tmp->__key.first == val.first)
                         return (ft::make_pair<iterator, bool>(iterator(__tmp), false));       
                    __size++;
                    return (ft::make_pair<iterator, bool>(iterator(__tree.AddLeaf(val)), true));
                    
               };
               
               mapped_type& operator[] (const key_type& k)
               {
			     return insert(ft::make_pair(k, mapped_type())).first->second;
               }
               
               template <class InputIterator>
               void insert (InputIterator first, InputIterator last)
               {
                    for (;first != last; first++)
                    {
                         insert(*first);
                    }
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
                    if (!__tree.DeleteWithKey(k))
                         return (0);
                    return (__size--, 1);
               }
               
               void erase (iterator first, iterator last)
               {
                    if (first == last)
                         return ;
                    while (first != last)
                    {
                         iterator tmp(first);
                         ++first;
                         erase(tmp);
                    }
               }
                    
               void erase(iterator position)
               {
                    if (!__tree.DeleteWithKey(position->first))
                         return ;
                    __size--;                
               }

               void swap (map& x)
               {
                    ft::swap(*this, x);
               }
               
               void    clear()
               {
                    if (__tree.root != nullptr)
                    {
                        erase(begin(), end());
                       __tree.root = nullptr;                     
                    }
               }


               map& operator= (const map &x)
               {  
                    if (*this != x)
                    {
                         clear();
                         if (x.__tree.root != nullptr)
                              insert(x.begin(), x.end());
                         __alloc.destroy(&__last->__key);
                         __alloc.construct(&__last->__key, x.__last->__key);
                         __size = x.__size;
                    }
                   return (*this);
               }

               size_type count (const key_type& k) 
               {
                    return __tree.count(k);
               }

               iterator begin()
               {
                    if (__tree.root == nullptr)
                         return  iterator(__last);
                    return  iterator(__tree.returnBegin());
               }

               const_iterator begin() const 
               {
                    if (__tree.root == nullptr)
                         return  iterator(__last);
                    return const_iterator(__tree.returnBegin());
               }

               const_iterator end() const 
               {
                    
                    return (const_iterator(__last) );
               }
               
               iterator end()
               {
                   
                    return ( iterator(__last) );
               }

               
               const_reverse_iterator rbegin() const
               {
                    return const_reverse_iterator(iterator(__last));
               }

               const_reverse_iterator rend() const
               {
                    return const_reverse_iterator(iterator(__tree.returnBegin()));
               }

               reverse_iterator rbegin() 
               {
                    return   reverse_iterator(iterator(__last));
               }
               
               reverse_iterator rend()
               {
                    return reverse_iterator(iterator(__tree.returnBegin()));
               }

            
               iterator find (const key_type& k)
               {
                    return iterator(__tree.ReturnNode(k, __tree.root));     
               }

               const_iterator find (const key_type& k) const
               {
                    return const_iterator(__tree.ReturnNode(k, __tree.root));
               }

               iterator lower_bound (const key_type& k)
               {
                    iterator __beging = begin();
                    iterator __end    = end();
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

    template <typename Key, typename T, typename Compare>
	bool operator==(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <typename Key, typename T, typename Compare>
	bool operator!=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(lhs == rhs);
	}

	template <typename Key, typename T, typename Compare>
	bool operator<(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <typename Key, typename T, typename Compare>
	bool operator>=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(lhs < rhs);
	}

	template <typename Key, typename T, typename Compare>
	bool operator>(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return rhs < lhs;
	}

	template <typename Key, typename T, typename Compare>
	bool operator<=(const map<Key, T, Compare> &lhs, const map<Key, T, Compare> &rhs)
	{
		return !(lhs > rhs);
     }
}



#endif