/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:47:43 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/22 02:48:53 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AvlTree_HPP
# define AvlTree_HPP

#include <iostream>
#include <cstdlib>

class AvlTree
{
    private :
        struct node {
            int key;
            node *left;
            node *right;
        };    
   node*    AddLeafPrivate(int key, node *_ptr)
    {
        if (!_ptr)
            return (creatleaf(key));
        else if (key < _ptr->key)
                _ptr->left = AddLeafPrivate(key, _ptr->left);
        else if (key >_ptr->key )
                _ptr->right = AddLeafPrivate(key, _ptr->right);
        else
            return _ptr;
        
        return checklBalance(key, _ptr);
    }

    node     *checklBalance(int key, node* _ptr)
    {
        int height = CalculHieghtHeight(_ptr);
        if (height > 1 && key < _ptr->left->key)
                return rightRotate(_ptr);

        if (height < -1 && key > _ptr->right->key)
          return  leftRotate(_ptr);
        if (height > 1 && key > _ptr->left->key)
        {
          _ptr->left = leftRotate(_ptr->left);
          return rightRotate(_ptr);
        }
    
        if (height < -1 && key < _ptr->right->key)
        {
            _ptr->right = rightRotate(_ptr->right);
            return leftRotate(_ptr);
        }
        return _ptr;
    }    

    void    PrintTreePrivate(node * root, int space)
    {
        if (!root)
            return;
        space += 10;
        PrintTreePrivate(root->right, space);
        std::cout << std::endl;
        for(size_t i = 0; i < space; i++)  std::cout << " ";
        std::cout << root->key << std::endl;
        PrintTreePrivate(root->left, space);
    }
    
    void    PrintInOrderPrivate(node *ptr)
    {
        if (root)
        {
            if (ptr->left)
                PrintInOrderPrivate(ptr->left);
            std::cout << ptr->key << " "; 
            if (ptr->right)
                PrintInOrderPrivate(ptr->right);
        }
        else
            std::cout << "Tree is empty!" << std::endl;     
    }
  
    int    FindSmallestPrivate(node* ptr)
    {
        if (!root)
           return ( std::cout << "Tree is Empty!" << std::endl, -1);
        else
        {
            if (ptr->left)
                return (FindSmallestPrivate(ptr->left));
            return (ptr->key);
        }
    }

    int FindOldestPrivate(node *ptr)
    {
        if (!root)
            return ( std::cout << "Tree is Empty!" << std::endl, -1);
        else
        {
            if (ptr->right)
                return (FindOldestPrivate(ptr->right));
            return (ptr->key);
        }
    }
    
    node *SmallestInSubTree(node *_ptr)
    {
        node *curr = _ptr;
        while (curr->left)
            curr = curr->left;
        return (curr);
    }
    
    node* deleteNode(node* _ptr, int key)
    {
        if (_ptr == NULL)
            return _ptr;
        if ( key < _ptr->key )
            _ptr->left = deleteNode(_ptr->left, key);
        else if( key > _ptr->key )
            _ptr->right = deleteNode(_ptr->right, key);
        else
        {
            if ((_ptr->left == NULL) || (_ptr->right == NULL) )
            {
                node* temp;
                if (_ptr->left)
                    temp = _ptr->left;
                else
                    temp = _ptr->right;
            if (temp == NULL)
            {
                temp = _ptr;
                _ptr = NULL;
            }
            else 
                *_ptr = *temp; 
            delete temp;
        }
        else
        {
            node* temp = SmallestInSubTree(_ptr->right);
            _ptr->key = temp->key;
            _ptr->right = deleteNode(_ptr->right,
                                     temp->key);
        }
    }
    return _ptr;
}

    int CalculHieght(node *_node)
    {
        if (!_node)
            return (-1);
        else{
           int _lheight = CalculHieght(_node->left);
           int _rheight = CalculHieght(_node->right);
        return ( _lheight > _rheight ? _lheight + 1: _rheight + 1);
        }
    }   
    
  node * rightRotate(node * y)
  {
    node * x = y->left;
    node * T2 = x->right;

    x->right= y;
    y->left = T2;
    return x;
  }

    node * leftRotate(node * x)
  {
    node * y = x->right;
    node * T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
  }
    
    node *root;
    public:
        AvlTree() : root(NULL)
        {
        }
        
        node* creatleaf(int key)
        {
            node* New = new node;
            New->key = key;
            New->left = NULL;
            New->right = NULL;
            return (New);
        }
        
        void    AddLeaf(int key)
        {
           root =  AddLeafPrivate(key, root);
        }
        
        node* ReturnNode(int key, node *Ptr)
        {
            if (Ptr)
            {
                if (Ptr->key == key)
                    return (Ptr);
                if (key > Ptr->key)
                    return ReturnNode(key, Ptr->right);
                else
                    return (ReturnNode(key, Ptr->left));
            } 
            return (NULL);  
        }

        void    PrintTree()
        {
           PrintTreePrivate(root, 0);
        }
        
        void  PrintInOrder()
        {
            PrintInOrderPrivate(root);
        }

        int   FindSmallest()
        {
            return (FindSmallestPrivate(root));
        }

        int   FindOldest()
        {
            return (FindOldestPrivate(root));
        }
        
        void RemoveNode(int key)
        {
            root = deleteNode(root, key);
        }
        
        int    CalculHieghtHeight(node *_ptr)
        {
            return (root == NULL ? -1 : (CalculHieght(_ptr->left) - CalculHieght(_ptr->right))); 
        }    
        
        ~AvlTree()
        {
            
        }
};

#endif