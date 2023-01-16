/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:49:14 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/16 18:14:02 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.hpp"

#include <iostream>       // std::cout
#include <stack>          // std::stack
# include <deque>
# include <vector>
int main ()
{
  /// @brief size M.function test 
  
  // std::stack<int> myints;
  // std::cout << "0. size: " << myints.size() << '\n';

  // for (int i=0; i<5; i++) myints.push(i);
  // std::cout << "1. size: " << myints.size() << '\n';

  // myints.pop();
  // std::cout << "2. size: " << myints.size() << '\n';

  /// @brief  top M.function test

  // ft::stack<int> mystack;

  // mystack.push(10);
  // mystack.push(20);

  // mystack.top() -= 5;

  // std::cout << "mystack.top() is now " << mystack.top() << '\n';

/// @brief empty M.function test
//  ft::stack<int> mystack;
//   int sum (0);

//   for (int i=1;i<=10;i++) mystack.push(i);

//   while (!mystack.empty())
//   {
//      sum += mystack.top();
//      mystack.pop();
//   }

//   std::cout << "total: " << sum << '\n';

  // @brief pop M.function test
  
     std::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  std::cout << "Popping out elements...";
  while (!mystack.empty())
  {
    std::cout << ' ' << mystack.top();
    mystack.pop();
  }
  std::cout << '\n';
  return 0;
}

