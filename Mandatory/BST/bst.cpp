/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:27:50 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/17 22:29:40 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "bst.hpp"

int main()
{

    /// @brief  Inserting elements in Tree and printing them in traverse order.
    int Keys[16] = {50,76,21,4,32,64,15,52,14,100,83,2,3,70,87,80};
    BST tree;
    for(size_t i = 0; i < 16; i++)
    {
        tree.AddLeaf(Keys[i]);
    }   

    tree.PrintInOrder();   
}