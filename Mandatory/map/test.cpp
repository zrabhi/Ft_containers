/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:30:24 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/02 11:15:41 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "map.hpp"
# include "../utils/ft_defines.hpp"

void map_tests()
{

  {
    
    red();
    std::cout << "################################ BEGIN MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    ft::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;
  
    // show content:
    for (ft::map<char,int>::iterator it=mymap.begin(); it != mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
  }


  
}


int main()
{
    map_tests();
}
