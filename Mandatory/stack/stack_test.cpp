/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:49:14 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/02 09:09:55 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

#include <iostream>       
#include <stack>          
# include <deque>
# include <vector>

void    stack_tests()
{
  {
    red();
    std::cout << "################################ EMPTY MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::stack<int> mystack;
    int sum (0);
    
    for (int i=1;i<=10;i++) mystack.push(i);
    
    while (!mystack.empty())
    {
       sum += mystack.top();
       mystack.pop();
    }
    
    std::cout << "total: " << sum << '\n';
    std::cout <<              " ###################  FT=======>>>>    ####################  \n\n";  
    
    ft::stack<int> mys;
    int result (0);
    
    for (int i=1;i<=10;i++) mys.push(i);
    
    while (!mys.empty())
    {
       result+= mys.top();
       mys.pop();
    }
     std::cout << "total: " << sum << '\n';
    
  }
  
  {
    red();
    std::cout << "################################ POP MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);
  
    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
       std::cout << ' ' << mystack.top();
       mystack.pop();
    }
    std::cout << '\n';
    std::cout <<              " ###################  FT=======>>>>    ####################  \n\n";
    std::stack<int> mys;

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
    red();
    std::cout << "################################ PUSH MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);
  
    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
       std::cout << ' ' << mystack.top();
       mystack.pop();
    }
    std::cout << '\n';
    std::cout <<              " ###################  FT=======>>>>    ####################  \n\n";
    std::stack<int> mys;

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

    red();
    std::cout << "################################ SIZE  MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
    std::cout <<              " ###################  FT=======>>>>    ####################  \n\n";
    ft::stack<int> my;
    std::cout << "0. size: " << my.size() << '\n';

    for (int i=0; i<5; i++) my.push(i);
    std::cout << "1. size: " << my.size() << '\n';

    my.pop();
    std::cout << "2. size: " << my.size() << '\n';
  }

  {
    red();
    std::cout << "################################ SIZE  MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";

    std::stack<int> mystack;

    mystack.push(10);
    mystack.push(20);
  
    mystack.top() -= 5;
  
    std::cout << "mystack.top() is now " << mystack.top() << '\n';

    std::cout <<              " ###################  FT=======>>>>    ####################  \n\n";
    ft::stack<int> mys;

    mys.push(10);
    mys.push(20);
    
  
    mys.top() -= 5;
  
    std::cout << "mys.top()   is now " << mys.top() << '\n';
  }
  
}



int main ()
{
  stack_tests();
  system("leaks Stack");
}


