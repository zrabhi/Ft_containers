/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:47:43 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/01 06:50:45 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AvlTree_HPP
# define AvlTree_HPP

// #include "../utils/ft_algorithm.hpp"
#include <iostream>
#include <cstdlib>
#include <utility>
#include "../utils/ft_utility.hpp"

namespace ft {
template<class T, class Compare, class key_type, class mapped_type, class map, class Allocatore = std::allocator<T> >
class AvlTree 
{
    private :
        
        typedef             mapped_type                     _val;
        typedef             key_type                        _KEY; 
        typedef             T                               value_type;
        typedef             Compare                         value_compare;
        typedef             Allocatore                      allocator_type;
        typedef             std::size_t                     size_type; 
        typedef typename    allocator_type::reference       reference;
        typedef typename    allocator_type::const_reference const_reference;
        typedef typename    allocator_type::pointer         pointer;
        typedef typename    allocator_type::const_pointer   const_pointer;

       public:
        struct node
      {
        value_type  __key;
        node        *__left;
        node        *__parent;
        node        *__right;
      };
    private:
    typedef  typename allocator_type::template rebind<node>::other  node_pointer;
         
    node*    AddLeafPrivate(const value_type& key, node *_ptr)
    {
        if (!_ptr)
            return (creatleaf(key));
        if (___comp(key, _ptr->__key))
                _ptr->__left = AddLeafPrivate(key, _ptr->__left);
                // _ptr->__left->__parent = root;
        else if (___comp(_ptr->__key, key))
                _ptr->__right = AddLeafPrivate(key, _ptr->__right);
                // _ptr->__right->__parent = root;
        else
            return _ptr;
        return checklBalance(key, _ptr);
    }

    node    *checklBalance(value_type key, node* _ptr)
    {
        int height = CalculHieghtHeight(_ptr);
        if (height > 1 && ___comp(key, _ptr->__key))
                return rightRotate(_ptr);
 
        if (height < -1 && !___comp(key, _ptr->__key))
          return  leftRotate(_ptr);
        if (height > 1 && !___comp(key, _ptr->__key))
        {
          _ptr->__left = leftRotate(_ptr->__left);
          return rightRotate(_ptr);
        }
    
        if (height < -1 && ___comp(key, _ptr->__key))
        {
            _ptr->__right = rightRotate(_ptr->__right);
            return leftRotate(_ptr);
        }
        return _ptr;
    }    

    void    PrintTreePrivate(node * root, int space)
    {
        if (!root)
            return ; 
        space += 10;
        PrintTreePrivate(root->__right, space);
        std::cout << std::endl;
        for(int i = 0; i < space; i++)  std::cout << " ";
        std::cout << "\033[31m "<< root->__key.first << " \033[30m" <<  std::endl;
        PrintTreePrivate(root->__left, space);
    }
    
    void    PrintInOrderPrivate(node *ptr)
    {
        if (root)
        {
            if (ptr->__left)
                PrintInOrderPrivate(ptr->__left);
            std::cout << ptr->__key->second << " "; 
            if (ptr->__right)
                PrintInOrderPrivate(ptr->__right);
        }
        else
            std::cout << "Tree is empty!" << std::endl;     
    }
  
    int     FindSmallestPrivate(node* ptr, node *p) // same ass subtree function
    {
        (void)p;
        if (ptr->__left)
            return (FindSmallestPrivate(ptr->__left));
        return (ptr->__key->first);
    }

    node     *FindOldestPrivate(node *ptr, node *__match)
    {
        node *__tmp = ptr;
        while (__tmp)
        {
            std::cout << "im hererr " << std::endl;
                if (__tmp->__left)
                {
                    if (__tmp->__left->__key.first == __match->__key.first)
                            break ;
                    if (___comp(__tmp->__left->__key, __match->__key))
                        __tmp = __tmp->__left;
                }
                if (__tmp->__right)
                {
                    if (__tmp->__right->__key.first == __match->__key.first)
                        break ;
                    if (___comp(__match->__key, __tmp->__right->__key))
                        __tmp = __tmp->__right;
                }
        }
        return (__tmp);
    }

    bool    empty()
    {
        if (!root)
            return (true);
        return (false);
    }
    value_type     smallestInSubTree(node *_ptr)
    {    
        if (_ptr->__left)
            return (smallestInSubTree(_ptr->__left));
        return (_ptr->__key);
    }
    
    node   *deleteNode(node *_ptr, value_type key)
    {
        if (_ptr == NULL)
            return NULL;
        if (___comp(key, _ptr->__key)) 
            _ptr->__left = deleteNode(_ptr->__left, key);
        else if (___comp(_ptr->__key, key)) 
            _ptr->__right = deleteNode(_ptr->__right, key);
    else 
    {
        if (_ptr->__left == NULL)
        {
            node * temp = _ptr->__right;
            __val_alloc.destroy(&_ptr->__key);
            _alloc.deallocate(_ptr, 1);
            return temp;
        } 
        else if (_ptr->__right == NULL)
        {
            node * temp = _ptr->__left;
            __val_alloc.destroy(&_ptr->__key);
            _alloc.deallocate(_ptr, 1);
            return temp;
        }
        else 
        {
            value_type smallest = smallestInSubTree(_ptr->__right);
            __val_alloc.construct(&_ptr->__key, smallest);
            _ptr->__right = deleteNode(_ptr->__right, smallest);
        }
    }
    
    return balanceAfterDeletion(_ptr, key);
    }

    node*   balanceAfterDeletion(node *_ptr, value_type key)
    {
        (void)key;
        int balance = CalculHieghtHeight(_ptr);

        if (balance == 2 && CalculHieghtHeight(_ptr->__left) >= 0)
            return rightRotate(_ptr);
        else if (balance == 2 && CalculHieghtHeight(_ptr->__left) == -1)
        {
            _ptr->__left = leftRotate(_ptr->__left);
            return rightRotate(_ptr);
        }   
        else if (balance == -2 && CalculHieghtHeight(_ptr->__right) <= 0)
            return leftRotate(_ptr);
        else if (balance == -1 && CalculHieghtHeight(_ptr->__right) == 1)
        {
            _ptr->__right = rightRotate(_ptr->__right);
            return leftRotate(_ptr);
        } 
        return _ptr;
    }
    
    int     CalculHieght(node *_node)
    {
        if (!_node)
            return (-1);
        else
        {
            int _lheight = CalculHieght(_node->__left);
            int _rheight = CalculHieght(_node->__right);
            return ( _lheight > _rheight ? _lheight + 1: _rheight + 1);
        }
    }   
    
    node *  rightRotate(node * y)
  {
        node * x = y->__left;
        node * T2 = x->__right;
    
        x->__right= y;
        y->__left = T2;
        return x;
  }

    node *  leftRotate(node * x)
   {
        node * y = x->__right;
        node * T2 = y->__left;
    
        y->__left = x;
        x->__right = T2;
    
        return y;
   }
    public:
        node            *root;
        node_pointer    _alloc;
        allocator_type  __val_alloc;
        value_compare   ___comp;
    
    public:
        
        AvlTree(const value_compare &_comp) : root(nullptr),  _alloc(node_pointer()), __val_alloc(allocator_type()),  ___comp(_comp)
        {
        }

        // AvlTree(const AvlTree& x)
        // {

        //     this->___comp = x.___comp;
        // }
        
        node*   creatleaf( const value_type& key)
        {
            node *New = _alloc.allocate(1);
            __val_alloc.construct(&New->__key, key);
            New->__left  = NULL;
            New->__right = NULL;
            New->__parent = NULL;
            return (New);
        }
        
        void    AddLeaf(const value_type& key)
        {
           root = AddLeafPrivate(key, root);
        }
        
        
        node*   ReturnNode(_KEY key, node *Ptr)
        {
            node *__tmp = Ptr;
            while (__tmp&& __tmp->__key.first != key)
            {
                 if (key > __tmp->__key.first)
                        __tmp = __tmp->__right;
                else if (key < __tmp->__key.first)
                        __tmp = __tmp->__left;
            } 
            return (__tmp);
        }
        
        node*   ReturnNodePublic(_KEY key)
        {
            return (ReturnNode(key, root));         
        }

        void    DeleteWithKey(_KEY key)
        {
            node * __tmp;
            __tmp = ReturnNode(key, root);
            if (!__tmp)
                std::cout << "im heree\n";
            root = deleteNode(root, __tmp->__key);
        }
        
        void    PrintTree()
        {
           PrintTreePrivate(root, 0);
        }
        
        mapped_type&   findVal(const _KEY key)
        {
            node *__tmp;
            __tmp = ReturnNode(key, root);
            return (__tmp->__key.second);
        }
    
        void    PrintInOrder()
        {
            PrintInOrderPrivate(root);
        }

        int     FindSmallest()
        {
            return (FindSmallestPrivate(root));
        }

        node      *FindOldest(node* __root, node *__match)
        {
            return (FindOldestPrivate(__root, __match));
        }
        
        void    clearTree(node *_ptr)
        {
            // if (!_ptr)
            //     return ;
            if ((_ptr)->__right)
                clearTree(_ptr->__right);
            else if ((_ptr)->__left)
                clearTree(_ptr->__left);
            else
            {
                    __val_alloc.destroy(&_ptr->__key);
                    _alloc.deallocate(_ptr, 1); 
            }
        }
        void    RemoveNode(value_type key)
        {
            root = __delete(key, root);
        }
        
        node*   returnBegin()const
        {
            node *__ptr = root;
            while (__ptr && __ptr->__left)
                __ptr = __ptr->__left;
            return (__ptr);
        }

        node*  returnEnd() const
        {
            node *__ptr = root;
            while (__ptr && __ptr->__right)
                    __ptr = __ptr->__right;
            return (__ptr);
        }


        bool  checkKey( _KEY key, node* _ptr)
        {
            node *__tmp = _ptr;
            while (__tmp && __tmp->__key.first != key)
            {
                if (key > __tmp->__key.first)
                    __tmp = __tmp->__right;
                else if (key < __tmp->__key.first)
                    __tmp = __tmp->__left;
            } 
            if (__tmp && __tmp->__key.first == key)
                return (true);
            return (false);
        }

        
        node* min(node *__node)
		{
			node* current = __node;

			while (current->__left != NULL) {
				current = current->__left;
			}

			return current;
		}

		node* max(node *__node)
		{
			node* current = __node;

			while (current->__right) {
				current = current->__right;
			}
			return current;
		}

        node* upper(value_type key, node* __root)
		{
			node *current = __root;
			node* last_valid = NULL;
			while (current)
            {
				if (key.first == current->__key.first)
                {
					if (current->__right) {
						return min(current->__right);
					}
					break ;
				}
				if (___comp(key , current->__key))
                {
					last_valid = current;
					current = current->__left;
				} 
                else 
					current = current->__right;
			}
			return (last_valid);
		}

        node* lower(value_type key, node* __root)
		{
			node *current = __root;
			node* last_valid = NULL;
			while (current)
            {
				if (key.first == current->__key.first)
                {
					if (current->__left) {
						return max(current->__left);
					}
					break ;
				}
				if (___comp(key , current->__key))
                {
					current = current->__left;
				} 
                
                else 
                {
					last_valid = current;
					current = current->__right;
                    
                }
			}
			return (last_valid);
		}


        
        node*   forward(node* __ptr)
        {
            if (__ptr->__right)
                return ( min(__ptr->__right));
            return upper(__ptr->__key, root);
        }

        node* backward(node* __ptr)
        {
            if (__ptr->__left)
                return max(__ptr->__left);
            return lower(__ptr->__key, root);            
        }

        

        node* lower_bound(_KEY key, node* __root)
		{
			node *current = __root;
            if (!root->__left)
                std::cout << " in min " <<  __root->__left << std::endl;
			node* last_valid = NULL;
			while (current)
            {
				if (key == current->__key.first)
                {
					if (current->__left) {
						return max(current->__left);
					}
					break ;
				}
				if (key < current->__key.first)
                {
					current = current->__left;
				} 
                else 
                {
					last_valid = current;
					current = current->__right;
                }
            }
			return (last_valid);
		}

        
        node *upper_bound(_KEY key,node* __root)
        {
            node *current = __root;
            if (!root->__left)
                std::cout << " in min " <<  __root->__left << std::endl;
			node* last_valid = NULL;
			while (current)
            {
				if (key == current->__key.first)
                {
					if (current->__right) {
						return min(current->__right);
					}
					break ;
				}
				if (key < current->__key.first)
                {
					last_valid = current;
					current = current->__left;
				} 
                
                else 
					current = current->__right;
			}
			return (last_valid);
		}
            
        
        bool count(_KEY key)
        {
            return (checkKey(key, root));
        }

        int     CalculHieghtHeight(node *_ptr)
        {
            return (root == NULL ? -1 : (CalculHieght(_ptr->__left) - CalculHieght(_ptr->__right))); 
        }    
        
        ~AvlTree()
        {
            
        }
};
}

#endif