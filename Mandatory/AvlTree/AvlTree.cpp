/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:27:50 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/21 20:55:46 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AvlTree.hpp"

int main()
{

    /// @brief  Inserting elements in Tree and printing them in traverse order.
    // int Keys[4] = {10,40,30};
    AvlTree tree;
    // for(size_t i = 0; i < 3; i++)
    // {
    //     tree.AddLeaf(Keys[i]);
    // }   

    // tree.PrintTree();
    // std:: cout << "Printing the smallest number in the tree " << std::endl;
    // std::cout << tree.FindSmallest() << std::endl;
    // std:: cout << "Printing the oldest number in the tree " << std::endl;
    // std::cout << tree.FindOldest() << std::endl;
    tree.AddLeaf(10);
    tree.AddLeaf(20); 
    tree.AddLeaf(5) ;
    tree.PrintTree();
    // tree.RemoveNode(10);
    tree.AddLeaf(30);
     tree.PrintTree();
    tree.AddLeaf(40);
    //  tree.PrintTree();
    tree.AddLeaf(50);
    tree.AddLeaf(60);
    tree.AddLeaf(720);
    tree.AddLeaf(760);
     tree.AddLeaf(770);
    // // tree.AddLeaf(25);
    tree.PrintTree();

    tree.PrintInOrder();

    // std:: cout << " height of tree is " <<  tree.GetBalanceHeight()  << std:: endl;
    
//     tree.RemoveNode(52);
//     std::cout << "aftre removing " << std::endl;
//     tree.PrintTree();
//      tree.RemoveNode(14);
//     std::cout << "aftre removing " << std::endl;
//     tree.PrintTree();
//      tree.RemoveNode(2);
//     std::cout << "aftre removing " << std::endl;
//     tree.PrintTree();
//     tree.RemoveNode(76);
//     std::cout << "aftre removing " << std::endl;
//     tree.PrintTree();
}