/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:49:14 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/12 12:26:10 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>       
# include "../utils/ft_defines.hpp"
#if STL
  # include <stack>  
  namespace ft = std;
#else
  # include "stack.hpp"
#endif

void    stack_tests()
{
  {
    BLUE_COLOR;
    std::cout << "################################ EMPTY MEMBER FUNCTION TEST################################\n\n";
    GREEN_COLOR;
    
    ft::stack<int> mys;
    int result (0);
    
    for (int i=1;i<=10;i++) mys.push(i);
    
    while (!mys.empty())
    {
       result+= mys.top();
       mys.pop();
    }
     std::cout << "total: " << result << '\n';
    
  }
  
  {
    BLUE_COLOR;
    std::cout << "################################ POP MEMBER FUNCTION TEST################################\n\n";
    GREEN_COLOR;
    
    ft::stack<int> mys;

    for (int i=0; i<5; ++i) mys.push(i);
  
    std::cout << "Popping out elements...";
    while (!mys.empty())
    {
       std::cout << ' ' << mys.top();
       mys.pop();
    }
    std::cout << '\n';
  }

  {
    BLUE_COLOR;
    std::cout << "################################ PUSH MEMBER FUNCTION TEST################################\n\n";
    GREEN_COLOR;
    
   ft::stack<int> mys;

    for (int i=0; i<5; ++i) mys.push(i);
  
    std::cout << "Popping out elements...";
    while (!mys.empty())
    {
       std::cout << ' ' << mys.top();
       mys.pop();
    }
    std::cout << '\n';    
  }


  {

    BLUE_COLOR;
    std::cout << "################################ SIZE  MEMBER FUNCTION TEST################################\n\n";
    GREEN_COLOR;
   
    ft::stack<int> my;
    std::cout << "0. size: " << my.size() << '\n';

    for (int i=0; i<5; i++) my.push(i);
    std::cout << "1. size: " << my.size() << '\n';

    my.pop();
    std::cout << "2. size: " << my.size() << '\n';
  }

  {
    BLUE_COLOR;
    std::cout << "################################ TOP MEMBER FUNCTION TEST################################\n\n";
    GREEN_COLOR;
   
    ft::stack<int> mys;

    mys.push(10);
    mys.push(20);
    
  
    mys.top() -= 5;
  
    std::cout << "mys.top()   is now " << mys.top() << '\n';
  }
  
}



// int main ()
// {
//   stack_tests();
//   // system("leaks Stack");
// }


