/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:22:32 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/12 12:35:35 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../utils/ft_defines.hpp"

#if STL
  #include <vector>
  namespace ft = std;
#else
  #include "vector.hpp"
#endif
    


void vector_tests()
    {
      {
       BLUE_COLOR;
        std::cout << "################################ ASSIGN MEMBER FUNCTION TEST################################\n\n";
        GREEN_COLOR;
        ft::vector<int> f;
        ft::vector<int> s;
        ft::vector<int> t;
    
        f.assign (1000,100);             
        ft::vector<int>::iterator _it;
        _it=f.begin()+1;
        s.assign (_it,f.end()-1); 
        int my[] = {1776,7,4};
        t.assign (my,my+3);  
        
        std::cout << "Size of first: " << int (f.size()) << '\n';
        std::cout << "Size of second: " << int (s.size()) << '\n';
        std::cout << "Size of third: " << int (t.size()) << '\n';
    }
 
    {
     BLUE_COLOR;
      std::cout << "################################ AT MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv (10);  
      for (unsigned i=0; i<myv.size(); i++)
        myv.at(i)=i;
      std::cout << "myv    contains:";
      for (unsigned i=0; i<myv.size(); i++)
       {  std::cout << ' ' << myv.at(i);
      std::cout << '\n';}
    
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ BACK MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv;
      myv.push_back(10);
      while (myv.back() != 0)
      {
        myv.push_back ( myv.back() -1 );
      }
      std::cout << "myv      contains:";
      for (unsigned i=0; i<myv.size() ; i++)
      {
        std::cout << ' ' << myv[i];
      std::cout << '\n';
      }
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ BEGIN MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv;
      for (int i=1; i<=5; i++) myv.push_back(i);
      
      std::cout << "myvector contains:";
      for (ft::vector<int>::iterator it = myv.begin() ; it != myv.end(); ++it)
          std::cout << ' ' << *it;
      std::cout << '\n';
    }
    
    {
      try {
        
       BLUE_COLOR;
        std::cout << "################################ OPERATOR[] MEMBER FUNCTION TEST################################\n\n";
        GREEN_COLOR;
        ft::vector<int> myv (10);  
        ft::vector<int>::size_type ss = myv.size();
        
        for (unsigned i=0; i<ss; i++) myv[i]=i;
        
        for (unsigned i=0; i<ss/2; i++)
        {
          int temp;
          temp = myv[ss-1-i];
          myv[ss-1-i]=myv[i];
          myv[i]=temp;
        }
        
        std::cout << "myv   contains:";
        for (unsigned i=0; i<ss; i++)
          std::cout << ' ' << myv[i];
        std::cout << '\n';
      } 
      catch (std::out_of_range e) 
      {
        std::cout << e.what();
      }
    }
    
    {
       BLUE_COLOR;
        std::cout << "################################ CLEAR MEMBER FUNCTION TEST################################\n\n";
        GREEN_COLOR;
        ft::vector<int> myv;
        myv.push_back (100);
        myv.push_back (200);
        myv.push_back (300);
        
        std::cout << "myv contains:";
        for (unsigned i=0; i<myv.size(); i++)
          std::cout << ' ' << myv[i];
        std::cout << '\n';
        
        myv.clear();
        myv.push_back (1101);
        myv.push_back (2202);
        
        std::cout << "myvector contains:";
        for (unsigned i=0; i<myv.size(); i++)
          std::cout << ' ' << myv[i];
        std::cout << '\n';
    }
    
    
    {
       BLUE_COLOR;
        std::cout << "################################ EMPTY MEMBER FUNCTION TEST################################\n\n";
        GREEN_COLOR;
        ft::vector<int> myv;
        int result (0);
        
        for (unsigned int i=1;i<=5;i++)
        {
            myv.push_back(i);
        }
        while (!myv.empty())
        {
           result += myv.back();
           myv.pop_back();
        }
        std::cout << "total: " << result << '\n';
    }
    
    {
       BLUE_COLOR;
        std::cout << "################################ END MEMBER FUNCTION TEST################################\n\n";
        GREEN_COLOR;
        ft::vector<int> myv;
        for (int i=1; i<=5; i++) myv.push_back(i);
      
        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myv.begin() ; it != myv.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ ERASE MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv;
     
      std::cout << "myv contains before erase :";
      for (int i=1; i<=10; i++) 
      {
        myv.push_back(i);
        std::cout << ' ' << myv[i -1];
      }
      std::cout << '\n';

      // erase the 6th element
      myv.erase (myv.begin()+5);

      // erase the first 3 elements:
      myv.erase (myv.begin(),myv.begin()+3);

      std::cout << "myv contains after erase:";
      for (unsigned i=0; i<myv.size(); ++i)
        std::cout << ' ' << myv[i];
      std::cout << '\n';
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ FRONT MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv;

      myv.push_back(78);
      myv.push_back(16);
    
      // now front equals 78, and back 16
    
      myv.front() -= myv.back();
      std::cout << "myvector.front() is now " << myv.front() << '\n';
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ FRONT MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv;
      int * t;
      unsigned int j;
    
      t = myv.get_allocator().allocate(5);
    
      for (j=0; j<5; j++) myv.get_allocator().construct(&t[j],j);
    
      for (j=0; j<5; j++)  std::cout << ' ' << t[j];
      std::cout << '\n';
    
      for (j=0; j<5; j++) myv.get_allocator().destroy(&t[j]);
      myv.get_allocator().deallocate(t,5);
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ INSERT MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv (3,100);
      ft::vector<int>::iterator _it;
    
      _it = myv.begin();
      _it = myv.insert ( _it , 200 );
      myv.insert ( _it, 2, 300);
    
      _it = myv.begin();
    
      ft::vector<int> anothervec (2,400);
      myv.insert (_it+2,anothervec.begin(),anothervec.end());
    
      int myarr [] = { 501,502,503 };
      myv.insert (myv.begin(), myarr, myarr+3);
    
      std::cout << "myvector contains:";
      for (_it=myv.begin(); _it<myv.end(); _it++)
        std::cout << ' ' << *_it;
      std::cout << '\n';
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ MAX_SIZE  | SIZE | CAPACITY  MEMBER FUNCTIONs TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv;

      for (int i=0; i<100; i++) myv.push_back(i);
  
      std::cout << "size: " << myv.size() << "\n";
      std::cout << "capacity: " << myv.capacity() << "\n";
      std::cout << "max_size: " << myv.max_size() << "\n";
      
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ OPERATOR= MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> fo (3,0);
      ft::vector<int> ba (5,0);
    
      ba = fo;
      fo = ft::vector<int>();
    
      std::cout << "Size of foo: " << int(fo.size()) << '\n';
      std::cout << "Size of bar: " << int(ba.size()) << '\n';
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ POP_BACK MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv;
      int result (0);
      myv.push_back (100);
      myv.push_back (200);
      myv.push_back (300);
    
      while (!myv.empty())
      {
        result+=myv.back();
        myv.pop_back();
      }
      std::cout << "The elements of myv      add up to " << result << '\n';
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ RBEGIN MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv (5);  
    
      int j = 0;
    
      ft::vector<int>::reverse_iterator _rit = myv.rbegin();
      // (void)_rit;
      for (; _rit != myv.rend(); ++_rit)
      {
        *_rit = ++j;
      }
      std::cout << "myv     contains:";
      
      for (ft::vector<int>::iterator _it = myv.begin(); _it != myv.end(); ++_it)
      {
        std::cout << ' ' << *_it;
      }
      std::cout << '\n';
    }
    
     {
     BLUE_COLOR;
      std::cout << "################################ REND MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      
      ft::vector<int> myv (5);  

      ft::vector<int>::reverse_iterator _rit = myv.rbegin();
    
      int j=0;
      for (_rit = myv.rbegin(); _rit!= myv.rend(); ++_rit)
        *_rit = ++j;
    
      std::cout << "myvector contains:";
      for (ft::vector<int>::iterator _it = myv.begin(); _it != myv.end(); ++_it)
        std::cout << ' ' << *_it;
      std::cout << '\n';
    }
    
  
    {
     BLUE_COLOR;
      std::cout << "################################ RESIZE MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> myv;
        
      // set some initial content:
      for (int i=1;i<10;i++) myv.push_back(i);
      myv.resize(5);
      myv.resize(8,100);
      myv.resize(12);
            std::cout << "myvector contains:";
      for (size_t i=0; i<myv.size(); i++)
        std::cout << ' ' << myv[i];
      std::cout << '\n';
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ SIZE MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      ft::vector<int> myi;
      std::cout << "0. size: " << myi.size() << '\n';
    
      for (int i=0; i<10; i++) myi.push_back(i);
      std::cout << "1. size: " << myi.size() << '\n';
    
      myi.insert (myi.end(),10,100);
      std::cout << "2. size: " << myi.size() << '\n';
    
      myi.pop_back();
      std::cout << "3. size: " << myi.size() << '\n';
    }
    
    {
     BLUE_COLOR;
      std::cout << "################################ SWAP MEMBER FUNCTION TEST################################\n\n";
      GREEN_COLOR;
      ft::vector<int> fo (3,100);   
      ft::vector<int> ba (5,200);  
      
      fo.swap(ba);
      
      std::cout << "fo contains:";
      for (unsigned i=0; i<fo.size(); i++)
      {
        std::cout << ' ' << fo[i];
        std::cout << '\n';
      }
      std::cout << "bar contains:";
      for (unsigned i=0; i<ba.size(); i++)
      {
        std::cout << ' ' << ba[i ];
        std::cout << '\n';
      }
      std::cout << '\n';
    }
    
    
}

  // int main()
  // {
  //   vector_tests();
  //   // system("leaks Vector");
  // }