/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:47:43 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/11 13:43:41 by zrabhi           ###   ########.fr       */
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
template<class T, class Compare, class key_type , class mapped_type , class Allocatore = std::allocator<T> >
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
        int          height;
            /// returns true is the parent right or left chlid matches this node;
            bool    isRight() 
            {
                if (this->__parent && this->__parent->__right == this)
                    return true;
                else 
                    return false;
            };
            bool    isLeft() 
            {
                if (this->__parent && this->__parent->__left && this->__parent->__left == this)
                    return true;
                else   
                    return false;
            }
        };
    private:
    typedef  typename allocator_type::template rebind<node>::other  node_pointer;
         
    int max(int a, int b)
    {
	    return (a > b)? a : b;
    }

    int height(node *N)
    {
	    if (N == NULL)
		    return 0;
	    return N->height;
    }
   
    node*    AddLeafPrivate(const value_type& key, node *_ptr)
    {
        if (!_ptr)
            return (creatleaf(key));
        if (___comp(key, _ptr->__key))
        {
            _ptr->__left = AddLeafPrivate(key, _ptr->__left);
            if ( _ptr->__left)
                _ptr->__left->__parent = _ptr; 
        }
        else if (___comp(_ptr->__key, key))
        {
            _ptr->__right = AddLeafPrivate(key, _ptr->__right);
            if ( _ptr->__right)
                 _ptr->__right->__parent = _ptr; 
        }
        else
            return _ptr;
        _ptr->height = 1 + max(height(_ptr->__left), height(_ptr->__right));
        return checklBalance(key, _ptr);
    }

    node    *checklBalance(value_type key, node* _ptr)
    {
        int height = getBalance(_ptr);
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
        for(int i = 0; i < space; i++)   std::cout << " ";
        std::cout << "\033[31m "<< root->__key.first << " \033[30m" <<  std::endl;
        PrintTreePrivate(root->__left, space);
    }
  
    int     FindSmallestPrivate(node* ptr, node *p) 
    {
        (void)p;
        if (ptr->__left)
            return (FindSmallestPrivate(ptr->__left));
        return (ptr->__key->first);
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
        {
            _ptr->__left = deleteNode(_ptr->__left, key);
            if ( _ptr->__left)
                _ptr->__left->__parent = _ptr;
        }
        else if (___comp(_ptr->__key, key)) 
        {
            _ptr->__right = deleteNode(_ptr->__right, key);
            if (_ptr->__right)
                _ptr->__right->__parent = _ptr;
        }
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
        y->__parent =  x;
        y->__left = T2;
        if (T2)
            T2->__parent = y;
        y->height = max(height(y->__left),
					height(y->__right)) + 1;
	    x->height = max(height(x->__left),
					height(x->__right)) + 1;
        return x;
  }

    node *  leftRotate(node * y)
    {
         node * x = y->__right;
        node * T2 = x->__left;
    
        x->__left= y;
        y->__parent =  x;
        y->__right = T2;
        if (T2)
            T2->__parent = y;
        y->height = max(height(y->__right),
					height(y->__left)) + 1;
	    x->height = max(height(x->__right),
					height(x->__left)) + 1;
        return x;
    }
    
    public:
        node            *root;
        node_pointer    _alloc;
        allocator_type  __val_alloc;
        node            *__last_element;
        node            *__last_elemt_left;
        value_compare   ___comp;
    
    public:
        AvlTree() : root(nullptr), ___comp(std::less<int>())
        {
            
        }
        AvlTree(const value_compare &_comp) : root(nullptr),  _alloc(node_pointer()), __val_alloc(allocator_type()), 
                                                        __last_element(nullptr),__last_elemt_left(nullptr), ___comp(_comp)
        {
        };
        
        int getBalance(node *N)
        {
	        if (N == NULL)
		        return 0;
	        return height(N->__left) - height(N->__right);
        }

        node*   creatleaf( const value_type& key)
        {
            node *New = _alloc.allocate(1);
            __val_alloc.construct(&New->__key, key);
            New->__left  = NULL;
            New->__right = NULL;
            New->__parent = NULL;
            New->height = 1;
            return (New);
        }
        
        bool    DeleteWithKey(_KEY key)
        {
            node * __tmp;
            
            __tmp = ReturnNode(key, root);
            if (__tmp && __tmp->__key.first != key)
                return false;
            root = deleteNode(root, __tmp->__key);
            if (!root)
                return true;
            root->__parent = __last_element;
            __last_element->__left = root;
            return true;
        }
       node  *AddLeaf(const value_type& key)
        {
            root = AddLeafPrivate(key, root);
            
            root->__parent = __last_element;
            __last_element->__left = root;
            return ReturnNode(key.first, root);
        }
        
        node    *insert(value_type key, node *__root)
        {
            __root = AddLeafPrivate(key, __root);
            __root->__parent = nullptr;
            return (__root);
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
        
        bool    empty() const
    {
        if (!root)
            return (true);
        return (false);
    }
        
        node*   ReturnNodePublic(_KEY key)
        {
            return (ReturnNode(key, root));         
        }

        node_pointer get_allocatore()
        {
            return (_alloc);
        }

        
        
        AvlTree &operator=(AvlTree  const  &pr)
        {
            // if (*this != pr)
            // {
                if (!empty())
                     clear_it(root);
                clone(pr.root);
                __last_element = pr.__last_element;
            // }
            return (*this);
        }
        
        
        void    PrintTree()
        {
            std::cout << "PRINTING TREEE\n";
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

        node*  returnEnd() 
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

        
        bool count(_KEY key)
        {
            return (checkKey(key, root));
        }

        int     CalculHieghtHeight(node *_ptr)
        {
            return (root == NULL ? -1 : (CalculHieght(_ptr->__left) - CalculHieght(_ptr->__right))); 
        }

        void    clear(node* _ptr, node* _last)    
        {
            if (!_ptr | _ptr == _last)
                return ;
            clear(_ptr->__right ,_last);
            clear(_ptr->__left,_last);
           __val_alloc.destroy(&_ptr->__key);
            _alloc.deallocate(_ptr, 1);
            _ptr = nullptr;
        }

        void    clear_it(node* _ptr)    
        {
            if (!_ptr || _ptr->__right == __last_element)
                return ;
            clear_it(_ptr->__right);
            clear_it(_ptr->__left);
            __val_alloc.destroy(&_ptr->__key);
            _alloc.deallocate(_ptr, 1);
            _ptr = nullptr;
        }
        
        ~AvlTree()
        {
            if (!empty() && root != nullptr)
              {
                clear_it(root);
                root  = nullptr;
              }
        }
        void clone( node *node)
        {
            if (!node)
                return ;
            clone(node->__left);
            if (node->__key.first)
                AddLeaf((node->__key));
            clone(node->__right);
        }

        

        node *getCopy(node* _ptr)
        {
            if (!_ptr )
                return  _ptr;
            _ptr->__left = getCopy(_ptr->__left);
            if (_ptr->__key.first)
                insert((_ptr->__key), _ptr);
            _ptr->__right = getCopy(_ptr->__right);
            return ( _ptr);
        }
       
        node* clone_root(node *_ptr)
        {

            if (!_ptr )
                return _ptr;
            _ptr->__left = clone_root(_ptr->__left);
            if (_ptr->__key.first)
                AddLeaf((_ptr->__key));
            _ptr->__right = clone_root(_ptr->__right);
            return (_ptr);
        }
    };
}

#endif