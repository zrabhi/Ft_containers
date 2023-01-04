/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:22:32 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/04 19:59:10 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"


int main()
{
    ft::Vector<int>  myvec(4,100);
    std::cout<< "Myvec element value is "<< myvec[0] << std::endl;
    std::cout << "##########changing the value of the first elemts############ " << std::endl;
    myvec[0] = 99;
    std::cout<< "Myvec element value is "<< myvec[0] << std::endl;
    std::cout << "Printing the SZIE " << myvec.size() << std::endl;

    myvec.push_back(5);
    std::cout << "Printing the Cpacity " << myvec.capacity() << std::endl;
    std::cout << "adding new elements in the back " << std::endl;
    myvec.push_back(15);
    myvec.push_back(8);
    myvec.push_back(15);
    std::cout << "printing the addded element " << *(myvec.end() - 1) << std::endl;
    myvec.erase(myvec.end() - 2);
    std::cout << "Erasee  printing the addded element " << *(myvec.end() - 1) << std::endl;
    std::cout << "Printing the size " << myvec.size() << std::endl;
    std::cout << "Printing the Cpacity " << myvec.capacity() << std::endl;

    std::cout << "########Creating a new Vector ############" << std::endl;
    ft::Vector<int> myvec1(myvec);
    std::cout<< "Myvec1 element value is "<< myvec1[0] << std::endl;
    std::cout << "##########vearting an iterator ########" << std::endl;
    ft::RandomAccessIter<int> it(myvec.end() - 1);
    std::cout << "printing the value " << *it << std::endl;
}