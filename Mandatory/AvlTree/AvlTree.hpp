/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:47:43 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/21 23:00:35 by zrabhi           ###   ########.fr       */
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
        int height = GetBalanceHeight(_ptr);
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
    
    void RemoveNodePrivate(int key, node* ptr)
    {
        if (root)
        {
            if (root->key == key)
                RemoveRootMatch();
            else 
            {
                if (key < ptr->key && ptr->left)
                {
                    ptr->left->key == key ? RemoveMatch(ptr, ptr->left, true) : RemoveNodePrivate(key, ptr->left);
                    return ;
                }
                else if (key > ptr->key && ptr->right)
                {
                    ptr->right->key == key ? RemoveMatch(ptr, ptr->right, false) : RemoveNodePrivate(key, ptr->right);
                    return ;
                }
            }
        }
        std::cout << "Tree is empty " << std::endl;
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
    
  node * rightRotate(node * y) {
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
        AvlTree() :root(NULL)
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
            RemoveNodePrivate(key, root);
        }
        
        void RemoveRootMatch()
        {
            if (root)
            {
                node *delPtr =  root;
                int rootKey = root->key;
                int smallestInRightSubtree;

                // case of 1 : 0 children
                if (!root->left && !root->right) 
                {
                    root = NULL;
                    delete delPtr;
                }
                // case 2 : 1 child (right child)
                
                if (!root->left && root->right)
                {
                    root = root->right;
                    delPtr->right = NULL;
                    delete delPtr;
                    std:: cout <<  "Removing old root && new root is right child of the old root " << std:: endl;
                    return ;
                }
                 
                // case 2 : 1 chhild (left child)
                if (root->left && !root->right)
                {
                    root = root->left;
                    delPtr->left = NULL;
                    delete delPtr;
                    std:: cout <<  "Removing old root && new root is left child of the old root " << std:: endl;
                    return ;
                }

                //case 3 : both childs exist
                if (root->left && root->right)
                {
                    smallestInRightSubtree = FindSmallestPrivate(root->right);
                    RemoveNodePrivate(smallestInRightSubtree, root);
                    root->key = smallestInRightSubtree;
                    std:: cout << "the root key containing key " << root->key << std::endl;
                    return ;
                }
            }
            std::cout << "tree is defenitly Empty ! " << std::endl;
        }
       
        void RemoveMatch(node *parent, node *match, bool _N)
        {
            if (root)
            {
                node *delPtr;
                int matchKey = match->key;
                int smallestInRightSubtree;
                if (!match->left && !match->right)
                {
                    delPtr = match;
                    _N == true ? parent->left = NULL : parent->right = NULL;
                    delete delPtr;
                    std::cout << "case 0: the node removed " << std::endl;
                    return ; 
                }
                
                if (!match->left && match->right)
                {
                    _N == true ? parent->left = match->right : parent->right = match->right;
                    match->right = NULL;
                    delPtr = match;
                    delete delPtr; 
                    std::cout << "case 1cdsfsd" << std::endl;
                    return ;   
                }
                
                if (match->left && !match->right)
                {
                    _N == true ? parent->left = match->left : parent->right = match->left;
                    match->left = NULL;
                    delPtr = match;
                    delete match;
                    std::cout << "case1"<< std::endl;
                    return ;
                }
                
                if (match->left && match->right)
                {
                    smallestInRightSubtree =FindOldestPrivate(match->right);
                    RemoveNodePrivate(smallestInRightSubtree, match);
                    match->key = smallestInRightSubtree;
                    std::cout << "case3"<< std::endl;
                    return ;
                }
            }
            std::cout << "tree is empty ! did nothing !" << std::endl;
        } 

        int    GetBalanceHeight(node *_ptr)
        {
            return (root == NULL ? -1 : (CalculHieght(_ptr->left) - CalculHieght(_ptr->right))); 
        }    
        
        
        ~AvlTree()
        {
            
        }
};

#endif