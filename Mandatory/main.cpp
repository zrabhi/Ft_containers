/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:23:32 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/12 12:31:50 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "utils/ft_defines.hpp"

int main()
{
    RED_COLOR;
    std::cout << "############################VECTOR TESTS############################\n\n" << std::endl;
    vector_tests();
    RED_COLOR;
    std::cout << "############################STACK TESTS############################\n\n" << std::endl;
    stack_tests();
    RED_COLOR;
    std::cout << "############################MAP TESTS############################\n\n" << std::endl;
    map_tests();
}