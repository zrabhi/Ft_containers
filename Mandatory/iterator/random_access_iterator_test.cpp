/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator_test.cpp                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:42:12 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/30 16:29:53 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_vector.hpp"
#include <iostream>
#include <cassert>

int main()
{
    int array[] = {5,2,3,4,5};
    ft::RandomAccessIter<int> begin(array);
    ft::RandomAccessIter<int> end(begin);
    // begin++;
    // bool p = (*end && *(end +  2) == *begin +1); // ---true means they have the same value;
    
    std::cout << "#####################Testing '==' operator########################" << std::endl;
    // std::cout << std::boolalpha << p << std::endl;
    begin = begin + 2;
    begin = begin + 2;
    std::cout << "end value  "<< *end << std::endl;
    
    end = begin;
    std::cout << "begin value " << *begin << std::endl;
    ft::RandomAccessIter<char> str;
    *str = 'c';
    std::cout << str[0] << std::endl;
}