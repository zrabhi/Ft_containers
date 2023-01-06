#include <iostream>
#include <vector>
#include "vector/vector.hpp"
///---
 //----   test file
 int main()
 {
   ft::Vector<int> myvvt(100, 100);
    myvvt.push_back(42);
   myvvt.push_back(55);

   // std::cout << "size is : " << myvvt.size() << std::endl;
   // std::cout << "max_size is : " << myvvt.max_size() << std::endl;
   std::cout << "capacity is : " << myvvt.capacity() << std::endl;
   for (int i = 0; i < myvvt.size(); i++)
    {
      //    std::cout << "size : " << myvvt.size() << std::endl;
      //    std::cout << "capacity :" << myvvt.capacity() << std::endl;
      //   myvvt.push_back(i)
      std::cout << "value is : " << myvvt[i] << std::endl;
   }
  // myvvt.push_back(42);
  // myvvt.push_back(55);
  // myvvt.push_back(42);
  // myvvt.push_back(55);
    // myvvt.push_back(42);
   // myvvt.push_back(55);
   std::cout << "capacity is : " << myvvt.capacity() << std::endl;

   // myvvt.clear();
   // std::cout << myvvt.size() << " " << myvvt.capacity() << std::endl;
   //   myvvt.assign(50, 42);
   //   std::cout << "size : " << myvvt.size() << std::endl;
   //   std::cout << "capacity :" << myvvt.capacity() << std::endl;
 }