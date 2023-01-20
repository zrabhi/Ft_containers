/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:27:50 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/20 01:44:10 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AvlTree.hpp"

int main()
{

    /// @brief  Inserting elements in Tree and printing them in traverse order.
    int Keys[4] = {50,40,30, 60};
    AvlTree tree;
    for(size_t i = 0; i < 4; i++)
    {
        tree.AddLeaf(Keys[i]);
    }   

    tree.PrintTree();
    std:: cout << "Printing the smallest number in the tree " << std::endl;
    std::cout << tree.FindSmallest() << std::endl;
    std:: cout << "Printing the oldest number in the tree " << std::endl;
    std::cout << tree.FindOldest() << std::endl;
    
    // tree.RemoveNode(100);
    tree.AddLeaf(10);  
    tree.PrintTree();

    std:: cout << " height of tree is " <<  tree.GetBalanceHeight()  << std:: endl;
    
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