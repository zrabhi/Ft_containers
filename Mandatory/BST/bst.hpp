/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:35:46 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/18 21:26:24 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

#include <iostream>
#include <cstdlib>

class BST
{
    private :
        struct node {
            int key;
            node *left;
            node *right;
        };    
    void    AddLeafPrivate(int key, node *_ptr)
    {
        if (!root)
            root = creatleaf(key);
        else if (key < _ptr->key)
        {
            if (_ptr->left)
                AddLeafPrivate(key, _ptr->left);
            else
                _ptr->left = creatleaf(key);
        }
        else if (key >_ptr->key )
        {
            if (_ptr->right)
                AddLeafPrivate(key, _ptr->right);
            else
                _ptr->right = creatleaf(key);
        } 
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
    node *root;
    public:
        BST() :root(NULL)
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
            AddLeafPrivate(key, root);
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

        ~BST()
        {
            
        }
};

#endif