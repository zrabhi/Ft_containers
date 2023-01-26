/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:47:43 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/26 15:25:48 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AvlTree_HPP
# define AvlTree_HPP

#include <iostream>
#include <cstdlib>


namespace ft {
template<class T, class Allocatore = std::allocator<T> >
class AvlTree 
{
    private :
        typedef              T                              value_type;
        typedef             Allocatore                      allocator_type;
        typedef             std::size_t                     size_type; 
        typedef typename    allocator_type::reference       reference;
        typedef typename    allocator_type::const_reference const_reference;
        typedef typename    allocator_type::pointer         pointer;
        typedef typename    allocator_type::const_pointer   const_pointer;
      struct node
      {
        value_type   __key;
        node        *__left;
        node        *__right;
      };
       
    typedef  typename allocator_type::template rebind<node>::other  node_pointer;
         
    node*    AddLeafPrivate(value_type key, node *_ptr)
    {
        if (!_ptr)
            return (creatleaf(key));
        else if (key < _ptr->__key->second)
                _ptr->__left = AddLeafPrivate(key, _ptr->__left);
        else if (key >_ptr->__key->second )
                _ptr->__right = AddLeafPrivate(key, _ptr->__right);
        else
            return _ptr;
        return checklBalance(key, _ptr);
    }

    node    *checklBalance(value_type key, node* _ptr)
    {
        int height = CalculHieghtHeight(_ptr);
        if (height > 1 && key < _ptr->__left->__key->second)
                return rightRotate(_ptr);

        if (height < -1 && key > _ptr->__right->__key->second)
          return  leftRotate(_ptr);
        if (height > 1 && key > _ptr->__left->__key->second)
        {
          _ptr->__left = leftRotate(_ptr->__left);
          return rightRotate(_ptr);
        }
    
        if (height < -1 && key < _ptr->__right->__key->second)
        {
            _ptr->__right = rightRotate(_ptr->__right);
            return leftRotate(_ptr);
        }
        return _ptr;
    }    

    void    PrintTreePrivate(node * root, int space)
    {
        if (!root)
            return;
        space += 10;
        PrintTreePrivate(root->__right, space);
        std::cout << std::endl;
        for(size_t i = 0; i < space; i++)  std::cout << " ";
        std::cout << root->__key->second << std::endl;
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
  
    int     FindSmallestPrivate(node* ptr) // same ass subtree function
    {
        if (ptr->__left)
            return (FindSmallestPrivate(ptr->__left));
        return (ptr->__key->second);
    }

    int     FindOldestPrivate(node *ptr)
    {
        if (!root)
            return ( std::cout << "Tree is Empty!" << std::endl, -1);
        else
        {
            if (ptr->__right)
                return (FindOldestPrivate(ptr->__right));
            return (ptr->__key->second);
        }
    }
    bool    empty()
    {
        if (!root)
            return (true);
        return (false);
    }
    int     smallestInSubTree(node *_ptr)
    {    
        if (_ptr->__left)
            return (smallestInSubTree(_ptr->__left));
        return (_ptr->__key->second);
    }
    
    node   *deleteNode(node *_ptr, value_type key)
    {
        if (_ptr == NULL)
            return NULL;
    else if (key < _ptr->__key->second) 
      _ptr->__left = deleteNode(_ptr->__left, key);
    else if (key > _ptr->__key->second) {
      _ptr->__right = deleteNode(_ptr->__right, key);
    }
    else
    {
        if (_ptr->__left == NULL)
        {
            node * temp = _ptr->__right;
            _alloc.deallocate(_ptr, 1);
            return temp;
        } 
        else if (_ptr->__right == NULL)
        {
            node * temp = _ptr->__left;
            _alloc.deallocate(_ptr, 1);
            return temp;
        }
        else 
        {
            int smallest = smallestInSubTree(_ptr->__right);
            _ptr->__key->second = smallest;
            _ptr->__right = deleteNode(_ptr->__right, smallest);
        }
    }
    return balanceAfterDeletion(_ptr, key);
    }
    
    node*   balanceAfterDeletion(node *_ptr, value_type key)
    {
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
    
    node          *root;
    node_pointer _alloc;
    public:
        
        AvlTree() : root(NULL)
        {
        }
        
        node*   creatleaf(value_type key)
        {


            node *New = _alloc.allocate(1);
            New->__key->second = key;
            New->__left = NULL;
            New->__right = NULL;
            return (New);
        }
        
        void    AddLeaf(value_type key)
        {
           root = AddLeafPrivate(key, root);
        }
        
        node*   ReturnNode(value_type key, node *Ptr)
        {
            if (Ptr)
            {
                if (Ptr->__key->second == key)
                    return (Ptr);
                if (key > Ptr->__key->second)
                    return ReturnNode(key, Ptr->__right);
                else
                    return (ReturnNode(key, Ptr->__left));
            } 
            return (NULL);  
        }

        void    PrintTree()
        {
           PrintTreePrivate(root, 0);
        }
        
        void    PrintInOrder()
        {
            PrintInOrderPrivate(root);
        }

        int     FindSmallest()
        {
            return (FindSmallestPrivate(root));
        }

        int     FindOldest()
        {
            return (FindOldestPrivate(root));
        }
        
        void    RemoveNode(value_type key)
        {
            root = deleteNode(root, key);
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