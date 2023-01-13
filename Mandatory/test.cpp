#include <iostream>
#include <vector>
#include <string>
#include "vector/vector.hpp"
#include <sstream>
#include "utils/ft_is_integral.hpp"
///---
 //----   test file


template <typename T>

typename std::enable_if<std::is_arithmetic<T>::value, T>::type
foo(T t)
{
  std::cout << "Arithmetic type " << std::endl;
  return t;
}

void foo(int i)
{
  std::cout << "ITS no arithemitic type " << std::endl;
}

// int _main()
// {
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
    // ft::Vector<int> foo (3,100);   // three ints with a value of 100
    // ft::Vector<int> bar (5,200);   // five ints with a value of 200

    // foo.swap(bar);

    // std::cout << "foo contains:";
    // for (unsigned i=0; i<foo.size(); i++)
    //   std::cout << ' ' << foo[i];
    // std::cout << '\n';

    // std::cout << "bar contains:";
    // for (unsigned i=0; i<bar.size(); i++)
    //   std::cout << ' ' << bar[i];
    // std::cout << '\n';

  ///////////RESERVE FUNCTION TESTTT
      //   ft::Vector<int>::size_type sz;
      //   ft::Vector<int> foo;
      //   sz = foo.capacity();
      //   std::cout << "Makinf foo grow:\n";

      //   for (int i = 0; i < 100; ++i){
      //     foo.push_back(i);
      //     if (sz != foo.capacity())
      //     {
      //       sz = foo.capacity();
      //       std::cout << " capacity changed: " << sz << '\n';
      //     }
      //   }
      //   ft::Vector<int> bar;
      //   sz = bar.capacity();
      //   std::cout << "sz of bar is " << sz << std::endl;
      //   bar.reserve(100);   // this is the only difference with foo above
      //   std::cout << "Bar capacity : " << bar.capacity() << std::endl;
      //   std::cout << "making bar grow:\n";
      //   for (int i = 0; i < 100; ++i) {
      //     bar.push_back(i);
      //     if (sz!=bar.capacity()) {
      //       sz = bar.capacity();
      //       std::cout << "capacity changed: " << sz << '\n';
      //     }
      //   }
      // return 0;
    
    //////RESIZE FUNCTION TEST
    //   std::vector<int> myvector;

    //   for (int i = 1; i < 10; i++) myvector.push_back(i);

    // myvector.resize(5);
    // myvector.resize(8, 100);
    // std:: cout << "My vector size : " << myvector.capacity() << '\n';
    // myvector.resize(18);
    //  for (int i=0;i<myvector.size();i++)
    // std::cout << ' ' << myvector[i];
    // std::cout << '\n';
    // return 0;

    ///////ASSIGN FUCNTION TEST
//   ft::Vector<int> first;
//   ft::Vector<int> second;
//   ft::Vector<int> third;

//   first.assign(3,55);           // 7 ints with a value of 100
//   first.assign (7,100);
//   first.assign(16, 16);
//   first.push_back(1);

//   // std::vector<int>::iterator it;
//   ft::RandomAccessIter<int> it;
//   it = first.begin()+1;

//   // second.assign (it,first.end()-1); // the 5 central values of first

//   int myints[] = {1776,7,4};
//   // third.assign (myints,myints+3);   // assigning from array.
// for (int i = 0; i < first.size(); i++)
//         std::cout << first[i] << std::endl;
//   std::cout << "Size of first: " << int (first.size()) << "  capacity  :" << first.capacity() << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   std::cout << "Size of third: " << int (third.size()) << '\n';
//   return 0;

  ///---------Insert fucntion test
  
  // std::cout << "#########STD TEST##############" << '\n';
  // ft::Vector<int> myvec(5, 100);
  // for(size_t i = 0 ; i < myvec.size(); i++) std::cout << "value of vec is :" << myvec[i] << std::endl;
  // // std::cout << "vector size is " << myvec.size() << std::endl;
  // // std::vector<int>::iterator it = myvec.insert(myvec.end() - 1, 7, 3);
  // ft::RandomAccessIter<int> it = myvec.insert(myvec.end() - 1, 7, 3);
  // std::cout << " value of iterator is : " << *it << std::endl;
  // std::cout << "vector CAPACITY is " << myvec.capacity() << std::endl;
  // std::cout << "########AFTER INSERT" << '\n';
  // std::cout << "vector size is " << myvec.size()<< std::endl;
  // for (size_t i = 0 ; i < myvec.size(); i++) std::cout << "value of vec is :" << myvec[i] << std::endl;
  // return (0);


  ///////// SFINAE TESTS
  // int i;

  // i = 0;
  // std::cout << std::boolalpha;
  // std::cout << (bool)ft::is_integral<int >::value << std::endl;
  // // SHOW(ft::is_integral<int>::value);
  // // ft::Vector<int> tt;
  // // i = 5;
  // // foo(5);
  // return 0;
  // ft::Vector<int> first;                                // empty vector of ints
  // ft::Vector<int> second (5,100);                       // four ints with value 100
  // ft::Vector<int> third (second.begin(),second.end());  // iterating through second
  // for(size_t i = 0; i < third.size(); i++)
  // {
  //   std::cout << "third value is :" << third[i] << std::endl; 
  // }
  
  // ft::Vector<int> fourth(third);                       // a copy of third

  // // the iterator constructor can also be used to construct from arrays:
  // int myints[] = {16,2,77,29};
  // std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  // std::cout << "The contents of fifth are:";
  // for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
  //   std::cout << ' ' << *it;
  // std::cout << '\n';

  // return 0;

//   ft::Vector<int> myvector (3,100);
//   ft::RandomAccessIter<int> it;

//   it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   // myvector.insert (it,2,300);

//   // "it" no longer valid, get a new one:
//   // it = myvector.begin();

//   // std::vector<int> anothervector (2,400);
//   // myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   // int myarray [] = { 501,502,503 };
//   // myvector.insert (myvector.begin(), myarray, myarray+3);

//   // std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;

// }

using namespace std;
  #include <bits/stdc++.h>
int _main()
{
  
    // Initialising the vector
//     ft::Vector<int> vector_name;
  
//     for(size_t i = 1 ; i < 6; i++) vector_name.push_back(i);
//     // Printing out the original vector
//     std::cout << "the size is :" << vector_name.size() << std::endl;
//     std::cout << "the Capacity is :" << vector_name.capacity() << std::endl;
//     cout << "Original vector :\n";
// for(size_t i = 0; i < vector_name.size(); i++) cout << vector_name[i] << " ";
//     cout << "\n";
  
//     // Inserting the value 100 at position 3(0-based
//     // indexing) in the vector
//     std::cout << "the size is :" << vector_name.size() << std::endl;
//     std::cout << "the Capacity is :" << vector_name.capacity() << std::endl;
//     vector_name.insert(vector_name.begin() + 3, 100);
//         std::cout << "the size is :" << vector_name.size() << std::endl;
//     std::cout << "the Capacity is :" << vector_name.capacity() << std::endl;
    
//     // Printing the modified vector
//     cout << "Vector after inserting 100 at position 3 :\n";
//     for(size_t i = 0; i < vector_name.size(); i++) cout << vector_name[i] << " ";
//     cout << "\n";
//     // Inserting the value 500 at position 1(0-based
//     // indexing) in the vector
//     vector_name.insert(vector_name.begin() + 1, 500);
  
//     std::cout << "the size is :" << vector_name.size() << std::endl;
//     std::cout << "the Capacity is :" << vector_name.capacity() << std::endl;
//     // Printing the modified vector
//     cout << "Vector after inserting 500 at position 1 :\n";
//    for(size_t i = 0; i < vector_name.size(); i++) cout << vector_name[i] << " ";
//     return 0;
// ft::Vector<int>vect;
    
   
//    vect.push_back(1);
//    vect.push_back(2);
//    vect.push_back(3);
//    vect.push_back(5);
//    std::cout <<"Capcityyyyy :" << vect.capacity() << std::endl;
//     // adding new value in the vector 
//     vect.insert(vect.begin()+3,4);
    
//     //printing values of the vector 
//     for(int i=0;i<vect.size();i++)
//     {
//         cout<<vect[i]<<" ";
//     }

//  ft::Vector<int> vect;
   
//     vect.push_back(1);
//     vect.push_back(2);
//     vect.push_back(3);
//     vect.push_back(5);
    
//     // adding new value in the vector 
//     vect.insert(vect.begin()+2,5,3);
    
//     //printing values of the vector 
//     for(int i=0;i<vect.size();i++)
//     {
//         cout<<vect[i]<<" ";
//     }
    
    ft::Vector<int>vect1;
    vect1.push_back(1);
    vect1.push_back(2);
    // vect1.push_back(3);
    // vect1.push_back(7);
    // vect1.push_back(8);
    // vect1.push_back(9);
    ft::Vector<int>vect2;
    vect2.push_back(4);
    vect2.push_back(5);
    vect2.push_back(6);
    
    // adding new value in the vector 
    // vect1.begin() + 3 represents the 4th index of vector1
    // vect2.begin() and vect2.end() represents the starting and ending position of vector2
    // vect1.insert(vect1.begin()+3,vect2.begin(),vect2.end() - 1);
    
    //printing values of the vector 
    for(int i=0;i<vect1.size();i++)
    {
        cout<<vect1[i]<<" ";
    }
    
    return 0;
    // std::vector<int> myvec(5,100);
    // myvec.reserve(7);
    // myvec.reserve(12);

    // std::cout << myvec.capacity() << "fafafa"<< std::endl;
}

int main()
{
  _main();
  // system("leaks a.out");
}