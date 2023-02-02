/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:22:32 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/02 08:35:31 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "../utils/ft_defines.hpp"
using namespace std;


    


void vector_tests() 
       {
    {
        red();
        std::cout << "################################ ASSIGN MEMBER FUNCTION TEST################################\n\n";
        green();
        std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
        std::vector<int> first;
        std::vector<int> second;
        std::vector<int> third;
    
        first.assign (7,100);             
        
        std::vector<int>::iterator it;
        it=first.begin()+1;
        
        second.assign (it,first.end()-1); 
        
        int myints[] = {1776,7,4};
        third.assign (myints,myints+3);  
        
        std::cout << "Size of first: " << int (first.size()) << '\n';
        std::cout << "Size of second: " << int (second.size()) << '\n';
        std::cout << "Size of third: " << int (third.size()) << '\n';

        std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";

        ft::vector<int> f;
        ft::vector<int> s;
        ft::vector<int> t;
    
        f.assign (7,100);             
        
        ft::vector<int>::iterator _it;
        _it=f.begin()+1;
        
        s.assign (_it,f.end()-1); 
        
        int my[] = {1776,7,4};
        t.assign (my,my+3);  
        
        std::cout << "Size of first: " << int (f.size()) << '\n';
        std::cout << "Size of second: " << int (s.size()) << '\n';
        std::cout << "Size of third: " << int (t.size()) << '\n';

        
    }
        reset();
    
    
    {
        red();
        std::cout << "################################ AT MEMBER FUNCTION TEST################################\n\n";
        green();
        std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
        std::vector<int> myvector (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myvector.size(); i++)
          myvector.at(i)=i;

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector.at(i);
        std::cout << '\n';

        std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
        ft::vector<int> myv (10);   // 10 zero-initialized ints

        // assign some values:
        for (unsigned i=0; i<myv.size(); i++)
          myv.at(i)=i;

        std::cout << "myv    contains:";
        for (unsigned i=0; i<myv.size(); i++)
          std::cout << ' ' << myv.at(i);
        std::cout << '\n';
      
    }
    
    {
        red();
        std::cout << "################################ BACK MEMBER FUNCTION TEST################################\n\n";
        green();
        std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
        std::vector<int> myvector;

        myvector.push_back(10);

        while (myvector.back() != 0)
        {
          myvector.push_back ( myvector.back() -1 );
        }

        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size() ; i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';

        std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";

        std::vector<int> myv;
        myv.push_back(10);

        while (myv.back() != 0)
        {
          myv.push_back ( myv.back() -1 );
        }

        std::cout << "myv      contains:";
        for (unsigned i=0; i<myv.size() ; i++)
          std::cout << ' ' << myv[i];
        std::cout << '\n';
    }
    
    {
        red();
        std::cout << "################################ BEGIN MEMBER FUNCTION TEST################################\n\n";
        green();
        std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
        std::vector<int> myvector;
        for (int i=1; i<=5; i++) myvector.push_back(i);
        
        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
         std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
        ft::vector<int> myv;
        for (int i=1; i<=5; i++) myv.push_back(i);
        
        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myv.begin() ; it != myv.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';
    }
    
    {
      try {
        
        red();
        std::cout << "################################ OPERATOR[] MEMBER FUNCTION TEST################################\n\n";
        green();
        std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";

        std::vector<int> myvector (10);   // 10 zero-initialized elements

        std::vector<int>::size_type sz = myvector.size();
        
        // assign some values:
        for (unsigned i=0; i<sz; i++) myvector[i]=i;
        
        // reverse vector using operator[]:
        for (unsigned i=0; i<sz/2; i++)
        {
          int temp;
          temp = myvector[sz-1-i];
          myvector[sz-1-i]=myvector[i];
          myvector[i]=temp;
        }
        
        std::cout << "myvector contains:";
        for (unsigned i=0; i<sz; i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';

        std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";      

        ft::vector<int> myv (10);   // 10 zero-initialized elements

        ft::vector<int>::size_type ss = myv.size();
        
        // assign some values:
        for (unsigned i=0; i<ss; i++) myv[i]=i;
        
        // reverse vector using operator[]:
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
        cout << e.what();
      }
    }
    
    {
        red();
        std::cout << "################################ CLEAR MEMBER FUNCTION TEST################################\n\n";
        green();
        std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
        std::vector<int> myvector;
        myvector.push_back (100);
        myvector.push_back (200);
        myvector.push_back (300);
        
        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
        
        myvector.clear();
        myvector.push_back (1101);
        myvector.push_back (2202);
        
        std::cout << "myvector contains:";
        for (unsigned i=0; i<myvector.size(); i++)
          std::cout << ' ' << myvector[i];
        std::cout << '\n';
        std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n"; 
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
        red();
        std::cout << "################################ EMPTY MEMBER FUNCTION TEST################################\n\n";
        green();
        std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
        std::vector<int> myvector;
        int sum (0);
        
        for (int i=1;i<=5;i++) myvector.push_back(i);
        
        while (!myvector.empty())
        {
           sum += myvector.back();
           myvector.pop_back();
        }
        
        std::cout << "total: " << sum << '\n';
        std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n"; 
        ft::vector<int> myv;
        int result (0);
        
        for (unsigned int i=1;i<=5;i++)
        {
            myv.push_back(i);
            std::cout << "in while  : " << myv[i - 1] << "\n" ;
        }
        while (!myv.empty())
        {
           result += myv.back();
           myv.pop_back();
        }
        std::cout << "total: " << result << '\n';
    }
    
    {
        red();
        std::cout << "################################ END MEMBER FUNCTION TEST################################\n\n";
        green();
        std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
        std::vector<int> myvector;
        for (int i=1; i<=5; i++) myvector.push_back(i);
      
        std::cout << "myvector contains:";
        for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
        ft::vector<int> myv;
        for (int i=1; i<=5; i++) myv.push_back(i);
      
        std::cout << "myvector contains:";
        for (ft::vector<int>::iterator it = myv.begin() ; it != myv.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';
    }
    
    {
      red();
      std::cout << "################################ ERASE MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> myvector;

      // set some values (from 1 to 10)
      std::cout << "myvector contains before erase :";
      for (int i=1; i<=10; i++) 
      {
        myvector.push_back(i);
        std::cout << ' ' << myvector[i -1];
      }
      std::cout << '\n';

      // erase the 6th element
      myvector.erase (myvector.begin()+5);

      // erase the first 3 elements:
      myvector.erase (myvector.begin(),myvector.begin()+3);

      std::cout << "myvector contains after erase:";
      for (unsigned i=0; i<myvector.size(); ++i)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
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
      red();
      std::cout << "################################ FRONT MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> myvector;

      myvector.push_back(78);
      myvector.push_back(16);
    
      // now front equals 78, and back 16
    
      myvector.front() -= myvector.back();
    
      std::cout << "myvector.front() is now " << myvector.front() << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      std::vector<int> myv;

      myv.push_back(78);
      myv.push_back(16);
    
      // now front equals 78, and back 16
    
      myv.front() -= myv.back();
      std::cout << "myvector.front() is now " << myvector.front() << '\n';
    }
    
    {
      red();
      std::cout << "################################ FRONT MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> myvector;
      int * p;
      unsigned int i;
    
      // allocate an array with space for 5 elements using vector's allocator:
      p = myvector.get_allocator().allocate(5);
    
      // construct values in-place on the array:
      for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
    
      std::cout << "The allocated array contains:";
      for (i=0; i<5; i++) std::cout << ' ' << p[i];
      std::cout << '\n';
    
      // destroy and deallocate:
      for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
      myvector.get_allocator().deallocate(p,5);
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      ft::vector<int> myv;
      int * t;
      unsigned int j;
    
      // allocate an array with space for 5 elements using vector's allocator:
      t = myv.get_allocator().allocate(5);
    
      // construct values in-place on the array:
      for (j=0; j<5; j++) myv.get_allocator().construct(&p[j],j);
    
      std::cout << "The allocated array contains:";
      for (j=0; j<5; j++) std::cout << ' ' << p[j];
      std::cout << '\n';
    
      // destroy and deallocate:
      for (j=0; j<5; j++) myv.get_allocator().destroy(&p[j]);
      myv.get_allocator().deallocate(p,5);
    }
    
    {
      red();
      std::cout << "################################ INSERT MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> myvector (3,100);
      std::vector<int>::iterator it;
    
      it = myvector.begin();
      it = myvector.insert ( it , 200 );
    
      myvector.insert (it,2,300);
    
      // "it" no longer valid, get a new one:
      it = myvector.begin();
    
      std::vector<int> anothervector (2,400);
      myvector.insert (it+2,anothervector.begin(),anothervector.end());
    
      int myarray [] = { 501,502,503 };
      myvector.insert (myvector.begin(), myarray, myarray+3);
    
      std::cout << "myvector contains:";
      for (it=myvector.begin(); it<myvector.end(); it++)
        std::cout << ' ' << *it;
      std::cout << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      ft::vector<int> myv (3,100);
      ft::vector<int>::iterator _it;
    
      _it = myv.begin();
      _it = myv.insert ( _it , 200 );
      myv.insert ( _it, 2, 300);
    
      // "it" no longer valid, get a new one:
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
      red();
      std::cout << "################################ MAX_SIZE  | SIZE | CAPACITY  MEMBER FUNCTIONs TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> myvector;

      for (int i=0; i<100; i++) myvector.push_back(i);
  
      std::cout << "size: " << myvector.size() << "\n";
      std::cout << "capacity: " << myvector.capacity() << "\n";
      std::cout << "max_size: " << myvector.max_size() << "\n";
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      ft::vector<int> myv;

      for (int i=0; i<100; i++) myv.push_back(i);
  
      std::cout << "size: " << myv.size() << "\n";
      std::cout << "capacity: " << myv.capacity() << "\n";
      std::cout << "max_size: " << myv.max_size() << "\n";
      
    }
    
    {
      red();
      std::cout << "################################ OPERATOR= MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> foo (3,0);
      std::vector<int> bar (5,0);
    
      bar = foo;
      foo = std::vector<int>();
    
      std::cout << "Size of foo: " << int(foo.size()) << '\n';
      std::cout << "Size of bar: " << int(bar.size()) << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      ft::vector<int> fo (3,0);
      ft::vector<int> ba (5,0);
    
      ba = fo;
      fo = ft::vector<int>();
    
      std::cout << "Size of foo: " << int(fo.size()) << '\n';
      std::cout << "Size of bar: " << int(ba.size()) << '\n';
    }
    
    {
      red();
      std::cout << "################################ POP_BACK MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> myvector;
      int sum (0);
      myvector.push_back (100);
      myvector.push_back (200);
      myvector.push_back (300);
    
      while (!myvector.empty())
      {
        sum+=myvector.back();
        myvector.pop_back();
      }
    
      std::cout << "The elements of myvector add up to " << sum << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
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
      std::cout << "The elements of myv      add up to " << sum << '\n';
    }
    
   
    
    {
      red();
      std::cout << "################################ RBEGIN MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> myvector (5);  // 5 default-constructed ints
    
      int i = 0;
    
      std::vector<int>::reverse_iterator rit = myvector.rbegin();
      for (; rit!= myvector.rend(); ++rit)
        *rit = ++i;
    
      std::cout << "myvector contains:";
      for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      ft::vector<int> myv (5);  // 5 default-constructed ints
    
      int j = 0;
    
      ft::vector<int>::reverse_iterator _rit = myv.rbegin();
      // (void)_rit;
      for (; _rit != myv.rend(); ++_rit)
      {
        std::cout << "loop\n";
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
      red();
      std::cout << "################################ REND MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> myvector (5);  // 5 default-constructed ints

      std::vector<int>::reverse_iterator rit = myvector.rbegin();
    
      int i=0;
      for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
        *rit = ++i;
    
      std::cout << "myvector contains:";
      for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
      std::cout << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      ft::vector<int> myv (5);  // 5 default-constructed ints

      ft::vector<int>::reverse_iterator _rit = myv.rbegin();
    
      int j=0;
      for (_rit = myv.rbegin(); _rit!= myv.rend(); ++_rit)
        *_rit = ++j;
    
      std::cout << "myvector contains:";
      for (ft::vector<int>::iterator _it = myv.begin(); _it != myv.end(); ++_it)
        std::cout << ' ' << *_it;
      std::cout << '\n';
    }
    
    //// bug need to be fixed to be remembered----------
    {
      red();
      std::cout << "################################ RESERVE MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
         std::vector<int>::size_type sz;

        std::vector<int> foo;
        sz = foo.capacity();
        std::cout << "making foo grow:\n";
        for (int i=0; i<100; ++i) 
        {
          foo.push_back(i);
          if (sz!=foo.capacity()) {
            sz = foo.capacity();
            std::cout << "capacity changed: " << sz << '\n';
          }
        }
      
        std::vector<int> bar;
        sz = bar.capacity();
        bar.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i=0; i<100; ++i) 
        {
          bar.push_back(i);
          if (sz!=bar.capacity()) {
            sz = bar.capacity();
            std::cout << "capacity changed: " << sz << '\n';
          }
        }
        std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
        ft::vector<int>::size_type s;

        ft::vector<int> fo;
        s = fo.capacity();
        std::cout << "making fo grow:\n";
        for (int i=0; i<100; ++i) 
        {
          fo.push_back(i);
          if (s!=fo.capacity()) {
            s = fo.capacity();
            std::cout << "capacity changed: " << s << '\n';
          }
        }
      
        ft::vector<int> ba;
        s = ba.capacity();
        ba.reserve(100);   // this is the only difference with foo above
        std::cout << "making bar grow:\n";
        for (int i=0; i<100; ++i) 
        {
          ba.push_back(i);
          if (s!=ba.capacity()) {
            s = ba.capacity();
            std::cout << "capacity changed: " << s << '\n';
          }
        }
    }
    
    ////--*--to be   remember
    {
      red();
      std::cout << "################################ RESIZE MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
       std::vector<int> myvector;
        
      // set some initial content:
      for (size_t i=1;i<10;i++) myvector.push_back(i);
            myvector.resize(5);
      // myvector.resize(8,100);
      myvector.resize(12);
            std::cout << "myvector contains:";
      for (size_t i=0; i<myvector.size(); i++)
        std::cout << ' ' << myvector[i];
      std::cout << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      ft::vector<int> myv;
        
      // set some initial content:
      for (int i=1;i<10;i++) myv.push_back(i);
      myvector.resize(5);
      // myv.resize(8,100);
      myv.resize(12);
            std::cout << "myvector contains:";
      for (size_t i=0; i<myv.size(); i++)
        std::cout << ' ' << myv[i];
      std::cout << '\n';
    
    }
    
    {
      red();
      std::cout << "################################ SIZE MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> myints;
      std::cout << "0. size: " << myints.size() << '\n';
    
      for (int i=0; i<10; i++) myints.push_back(i);
      std::cout << "1. size: " << myints.size() << '\n';
    
      myints.insert (myints.end(),10,100);
      std::cout << "2. size: " << myints.size() << '\n';
    
      myints.pop_back();
      std::cout << "3. size: " << myints.size() << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
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
      red();
      std::cout << "################################ SWAP MEMBER FUNCTION TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> foo (3,100);   // three ints with a value of 100
      std::vector<int> bar (5,200);   // five ints with a value of 200
      
      foo.swap(bar);
      
      std::cout << "foo contains:";
      for (unsigned i=0; i<foo.size(); i++)
        std::cout << ' ' << foo[i];
      std::cout << '\n';
      
      std::cout << "bar contains:";
      for (unsigned i=0; i<bar.size(); i++)
      std::cout << ' ' << bar[i];
      std::cout << '\n';
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      ft::vector<int> fo (3,100);   // three ints with a value of 100
      ft::vector<int> ba (5,200);   // five ints with a value of 200
      
      fo.swap(ba);
      
      std::cout << "fo contains:";
      for (unsigned i=0; i<fo.size(); i++)
        std::cout << ' ' << fo[i];
      std::cout << '\n';
      
      std::cout << "bar contains:";
      for (unsigned i=0; i<ba.size(); i++)
      std::cout << ' ' << ba[i];
      std::cout << '\n';
      
    }
    
    {
      red();
      std::cout << "################################ FUNCTION TEMPLATE : RELATIONAL OPERATORS  TEST################################\n\n";
      green();
      std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
      std::vector<int> foo (3,300);   // three ints with a value of 100
      std::vector<int> bar (3,200);   // two ints with a value of 200
    
      if (foo==bar) 
        std::cout << "foo and bar are equal\n";
      if (foo!=bar) 
        std::cout << "foo and bar are not equal\n";
      if (foo< bar) 
        std::cout << "foo is less than bar\n";
      if (foo> bar) 
        std::cout << "foo is greater than bar\n";
      if (foo<=bar) 
        std::cout << "foo is less than or equal to bar\n";
      if (foo>=bar) 
        std::cout << "foo is greater than or equal to bar\n";
      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
      ft::vector<int> fo (3,300);   // three ints with a value of 100
      ft::vector<int> ba (3,200);   // two ints with a value of 200
    
      if (fo==ba) 
        std::cout << "foo and bar are equal\n";
      if (fo !=ba) 
        std::cout << "foo and bar are not equal\n";
      if (fo< ba) 
        std::cout << "foo is less than bar\n";
      if (fo > ba) 
        std::cout << "foo is greater than bar\n";
      if (fo <= ba) 
        std::cout << "foo is less than or equal to bar\n";
      if (fo >= ba) 
        std::cout << "foo is greater than or equal to bar\n";
    
    }
    
    {
        red();
        std::cout << "################################ FUNCTION TEMPLATE : SWAP FUNCTION  TEST ################################\n\n";
        green();
        std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    
        std::vector<int> foo (3,100);   // three ints with a value of 100
        std::vector<int> bar (5,200);   // five ints with a value of 200

        foo.swap(bar);

        std::cout << "foo contains:";
        for (std::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
          std::cout << ' ' << *it;
        std::cout << '\n';

        std::cout << "bar contains:";
        for (std::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
        std::cout << ' ' << *it;
        std::cout << '\n';
        std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
        ft::vector<int> fo (3,100);   // three ints with a value of 100
        ft::vector<int> ba (5,200);   // five ints with a value of 200

        fo.swap(ba);

        std::cout << "foo contains:";
        for (ft::vector<int>::iterator _it = fo.begin(); _it!=fo.end(); ++_it)
          std::cout << ' ' << *_it;
        std::cout << '\n';

        std::cout << "bar contains:";
        for (ft::vector<int>::iterator __it = ba.begin(); __it!=ba.end(); ++__it)
        std::cout << ' ' << *__it;
        std::cout << '\n';

    }
}
int main()
{
    vector_tests();
    system("leaks Map");
}