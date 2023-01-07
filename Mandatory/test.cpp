#include <iostream>
#include <vector>
#include "vector/vector.hpp"
///---
 //----   test file
 int main()
  {
    ///////////ERASE FUNCTION TEST

                      //     ft::Vector<int> myvector;

                //     for(int i = 1; i <= 10; i++) myvector.push_back(i);

                //     myvector.erase(myvector.begin() + 5);

                //   ft::RandomAccessIter<int> it = myvector.erase(myvector.begin(), myvector.begin());
                // //  std::vector<int>::iterator it = myvector.erase(myvector.begin(), myvector.begin() + 3);
                //  std::cout << "Iterator value is : " << *it << std::endl;
                // for (unsigned i=0; i<myvector.size(); ++i)
                //       std::cout << ' ' << myvector[i];
                //     std::cout << '\n';

                        //     ft::Vector<int> myvvt;
                        //     myvvt.push_back(42);
                        //     myvvt.push_back(55);
                        //     myvvt.push_back(42);

                        //  // std::cout << "max_size is : " << myvvt.max_size() << std::endl;
                        // //  std::cout << "capacity is : " << myvvt.capacity() << std::endl;
                        // //  myvvt.erase(myvvt.end() -1);
                        // //  myvvt.erase(myvvt.end());
                        // // std::vector<int>::iterator it = myvvt.erase(myvvt.end() - 3);
                        //  ft::RandomAccessIter<int> it = myvvt.erase(myvvt.end() - 3);
                        // std:: cout << "Iterator value is " << *it << std::endl;
                        //  for (int i = 0; i < myvvt.size(); i++)
                        //   {
                        //     //    std::cout << "size : " << myvvt.size() << std::endl;
                        //     //    std::cout << "capacity :" << myvvt.capacity() << std::endl;
                        //     //   myvvt.push_back(i)
                        //     std::cout << "value is : " << myvvt[i] << std::endl;
                        //  }
                        //  std::cout << "size is : " << myvvt.size() << std::endl;

                          // std::vector<int> myvv;
                          //   myvv.push_back(42);
                          //   myvv.push_back(55);
                          //   myvv.push_back(42);

                        //  std::cout << "max_size is : " << myvvt.max_size() << std::endl;
                        //  std::cout << "capacity is : " << myvvt.capacity() << std::endl;
                        //  myvvt.erase(myvvt.end() -1);
                        //  myvvt.erase(myvvt.end());
                        // std::vector<int>::iterator it = myvv.erase(myvvt.end() - 2);
                        // std::vector<int>::iterator it = myvv.erase(myvv.end() - 2);
                        // std:: cout << "Iterator value is " << *it << std::endl;
                        //  for (int i = 0; i < myvv.size(); i++)
                        //   {
                        //     //    std::cout << "size : " << myvvt.size() << std::endl;
                        //     //    std::cout << "capacity :" << myvvt.capacity() << std::endl;
                        //     //   myvvt.push_back(i)
                        //     std::cout << "value is : " << myvv[i] << std::endl;
                        //  }
                        //  std::cout << "size is : " << myvv.size() << std::endl;

                        // myvvt.push_back(55);
                        // myvvt.push_back(42);
                        // myvvt.push_back(55);
                          // myvvt.push_back(42);
                        // myvvt.push_back(55);
                        //  std::cout << "capacity is : " << myvvt.capacity() << std::endl;

                        // myvvt.clear();
                        // std::cout << myvvt.size() << " " << myvvt.capacity() << std::endl;
                        //   myvvt.assign(50, 42);
                        //   std::cout << "size : " << myvvt.size() << std::endl;
                        //   std::cout << "capacity :" << myvvt.capacity() << std::endl;
      
  ///////// SWAP FUCNTION TEST
    ft::Vector<int> foo (3,100);   // three ints with a value of 100
    ft::Vector<int> bar (5,200);   // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
      std::cout << ' ' << foo[i];
    std::cout << '\n';

    std::cout << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
      std::cout << ' ' << bar[i];
    std::cout << '\n';

    return 0;
 }