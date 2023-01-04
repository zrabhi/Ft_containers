#include <iostream>
#include <vector>
///---
 //----   test file
 int main()
 {
    std::vector<int> myvvt;
    // myvvt.push_back(42);

   for (int i = 1; i < 10; i++)
    {
         std::cout << "size : " << myvvt.size() << std::endl;
         std::cout << "capacity :" << myvvt.capacity() << std::endl;
        myvvt.push_back(i)
    }
    myvvt.assign(50, 42);
    std::cout << "size : " << myvvt.size() << std::endl;
    std::cout << "capacity :" << myvvt.capacity() << std::endl;
 }