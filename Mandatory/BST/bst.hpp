/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:35:46 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/17 22:31:35 by zrabhi           ###   ########.fr       */
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
    node *root;
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
        
        void  PrintInOrder()
        {
            PrintInOrderPrivate(root);
        }
        
        ~BST()
        {
            
        }
};

#endif