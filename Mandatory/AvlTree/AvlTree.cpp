/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AvlTree.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 22:27:50 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/11 17:41:58 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// #include "AvlTree.hpp"
// #include "../map/map.hpp"
// // int main()
// {

//     /// @brief  Inserting elements in Tree and printing them in traverse order.
//     // int Keys[4] = {10,40,30};
//     ft::pair<char, int> p;
//     p.first = 'x';
//     p.second = 100;
//     ft::AvlTree<ft::pair<char, int>, std::less<ft::pair<char, int>  > > tree;
//     // for(size_t i = 0; i < 3; i++)
//     // {
//     //     tree.AddLeaf(Keys[i]);
//     // }   

//     // tree.PrintTree();
//     // std:: cout << "Printing the smallest number in the tree " << std::endl;
//     // // std::cout << tree.FindSmallest() << std::endl;
//     // std:: cout << "Printing the oldest number in the tree " << std::endl;
//     // // std::cout << tree.FindOldest() << std::endl;
//     tree.AddLeaf(10);
//     tree.AddLeaf(20); 
//     tree.AddLeaf(5) ;
//     tree.PrintTree();
//     // tree.RemoveNode(10);
//     tree.AddLeaf(30);
//     // std::cout << "printing tree\n" << std::endl;
//     tree.PrintTree();
//     tree.AddLeaf(40);
//     // std::cout << "printing tree\n" << std::endl;
//     tree.PrintTree();
//     tree.AddLeaf(50);
//     tree.AddLeaf(60);
//     tree.AddLeaf(720);
//     tree.AddLeaf(760);
//     //  tree.AddLeaf(770);
//     // // tree.AddLeaf(25);
//     // std::cout << "printing tree\n" << std::endl;
//     tree.PrintTree();

//     tree.RemoveNode(30);
//     // tree.RemoveNode(40);
//     // tree.RemoveNode(720);
//     // std::cout << "printing tree\n" << std::endl;
//     tree.PrintTree();

//     tree.PrintInOrder();

//     // std:: cout << " height of tree is " <<  tree.GetBalanceHeight()  << std:: endl;
    
// //     tree.RemoveNode(52);
// //     // std::cout << "aftre removing " << std::endl;
// //     tree.PrintTree();
// //      tree.RemoveNode(14);
// //     // std::cout << "aftre removing " << std::endl;
// //     tree.PrintTree();
// //      tree.RemoveNode(2);
// //     // std::cout << "aftre removing " << std::endl;
// //     tree.PrintTree();
// //     tree.RemoveNode(76);
// //     // std::cout << "aftre removing " << std::endl;
// //     tree.PrintTree();
// }


// C++ program to insert a node in AVL tree
// #include <iostream>

// // Driver Code
// int main()
// {
// 	Node *root = NULL;
	
// 	/* Constructing tree given in
// 	the above figure */
//     for (int i  = 0; i < 100000; i++)
//     {
//         root = insert(root, i);
//     }
// 	// root = insert(root, 10);
// 	// root = insert(root, 20);
// 	// root = insert(root, 30);
// 	// root = insert(root, 40);
// 	// root = insert(root, 50);
// 	// root = insert(root, 25);
	
// 	/* The constructed AVL Tree would be
// 				30
	// 		/ \
	// 		20 40
	// 		/ \ \
	// 	10 25 50
	// */
	// cout << "Preorder traversal of the "
	// 		"constructed AVL tree is \n";
	// preOrder(root);
	
	// return 0;
// }

// This code is contributed by
// rathbhupendra

// int main()
// {
//     ft::pair<char , int> pair;
    
//     ft::AvlTree<ft::pair<int , int>, ft::map<int, int>::value_compare, int, int > tree;
//     std::map<char, int> mymap;
//     // char c = 'a';
//     for (int i = 0; i < 1000000; i++)
//         mymap.insert(std::pair<char , int>(i, i));
//         // tree.AddLeaf(ft::pair<int, int>(i, i));
    
//     // tree.PrintTree();
//     return 0;
// }

// void PrintTree(Node *root, int space)
// {

//     if (!root)
//             return ; 
//     space += 10;
//     PrintTree(root->right, space);
//     // std::cout << std::endl;
//     for(int i = 0; i < space; i++)  // std::cout << " ";
//     // std::cout << "\033[31m "<< root->key << " \033[30m" <<  std::endl;
//     PrintTree(root->left, space);


// }

// int main()
// {
//     Node *root = NULL;
//     // std::map<int , int> map;
//     // char c = 'a';
//     // for (int i = 0; i < 5; i++) {
//     //     map.insert(std::make_pair<int, int>(c++, i));
//     // }
//     // for (std::map<int,int>::reverse_iterator rev_it = map.rbegin(); rev_it != map.rend(); rev_it++)
//     //     // std::cout << (char)rev_it->first << std::endl;
// //     // _main();
// //     // system("leaks a.out");
// 	// root = insert(root, 0);
// 	// root = insert(root, 1);
// 	// root = insert(root, 3);
// 	// root = insert(root, 4);
// 	// root = insert(root, 5);
//     // PrintTree(root, 0);
// 	// root = insert(root, 25);
// }