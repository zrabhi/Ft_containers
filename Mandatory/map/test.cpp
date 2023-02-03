/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:30:24 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/03 10:09:08 by zrabhi           ###   ########.fr       */
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
    std::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;
  
    // show content:
    for (std::map<char,int>::iterator it=mymap.begin(); it != mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
    std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";

    ft::map<char,int> mym;

    mym['b'] = 100;
    mym['a'] = 200;
    mym['c'] = 300;
  //// show content:
    // mym.printer();
    // show content:
    for (ft::map<char,int>::iterator _it=mym.begin(); _it != mym.end(); ++_it)
      std::cout << _it->first << " => " << _it->second << '\n';
  }

  {  
    red();
    std::cout << "################################ CLEAR MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::map<char,int> mymap;

    mymap['x']=100;
    mymap['y']=200;
    mymap['z']=300;
  
    std::cout << "mymap contains:\n";
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
  
    mymap.clear();
    mymap['a']=1101;
    mymap['b']=2202;
  
    std::cout << "mymap contains:\n";
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
    std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
    ft::map<char,int> mym;

    mym['x']=100;
    mym['y']=200;
    mym['z']=300;
  
    std::cout << "mymap contains:\n";
    for (ft::map<char,int>::iterator _it=mym.begin(); _it!=mym.end(); ++_it)
      std::cout << _it->first << " => " << _it->second << '\n';
    //// show content:
    // mym.printer();
    mym.clear();
    mym['a']=1101;
    mym['b']=2202;
    //// show content:
    // mym.printer();
    std::cout << "mymap contains:\n";
    for (ft::map<char,int>::iterator _it=mym.begin(); _it!=mym.end(); ++_it)
      std::cout << _it->first << " => " << _it->second << '\n';
  }

  {  
    red();
    std::cout << "################################ COUNT MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::map<char,int> mymap;
    char c;
  
    mymap ['a']=101;
    mymap ['c']=202;
    mymap ['f']=303;
  
    for (c='a'; c<'h'; c++)
    {
      std::cout << c;
      if (mymap.count(c)>0)
        std::cout << " is an element of mymap.\n";
      else 
        std::cout << " is not an element of mymap.\n";
    }
    std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
    ft::map<char,int> mym;
    char ca;
  
    mym ['a']=101;
    mym ['c']=202;
    mym ['f']=303;
    //// show content:
    // mym.printer();
    for (ca='a'; ca<'h'; ca++)
    {
      std::cout << ca;
      if (mymap.count(ca)>0)
        std::cout << " is an element of mymap.\n";
      else 
        std::cout << " is not an element of mymap.\n";
    }
  }

  {
    red();
    std::cout << "################################ EMPTY MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
  
    while (!mymap.empty())
    {
      std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
      mymap.erase(mymap.begin());
    }
    std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
    ft::map<char,int> mym;

    mym['a']=10;
    mym['b']=20;
    mym['c']=30;
    //// show content:
    // mym.printer();
    while (!mym.empty())
    {
      std::cout << mym.begin()->first << " => " << mym.begin()->second << '\n';
      mym.erase(mym.begin());
    }
    
  }

  {

    red();
    std::cout << "################################ END MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
    std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";

    ft::map<char,int> mym;

    mym['b'] = 100;
    mym['a'] = 200;
    mym['c'] = 300;
  
    //// show content:
    // mym.printer();
  
    for (ft::map<char,int>::iterator _it=mym.begin(); _it!=mym.end(); ++_it)
      std::cout << _it->first << " => " << _it->second << '\n';
  }
  
  {
    red();
    std::cout << "################################ EQUAL_RANGE || LOWER_BOUND || UPPER_BOUND  MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
  
    std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');
  
    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';
  
    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
    std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
    ft::map<char,int> _mymap;

    _mymap['a']=10;
    _mymap['b']=20;
   _mymap['c']=30;
    
    /// // show_content
    // // _mymap.printer();
    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> _ret;
    _ret = _mymap.equal_range('b');
  
    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << _ret.first->second << '\n';
  
    std::cout << "upper bound points to: ";
    std::cout << _ret.second->first << " => " << _ret.second->second << '\n';
    
  }

  {
    red();
    std::cout << "################################ ERASE MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::map<char,int> mymap;
    std::map<char,int>::iterator it;
  
    // insert some values:
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;
  
    it=mymap.find('b');
    mymap.erase (it);                   // erasing by iterator
  
    mymap.erase ('c');                  // erasing by key
  
    it=mymap.find ('e');
    mymap.erase ( it, mymap.end() );    // erasing by range
  
    for (it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
    std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
    ft::map<char,int> _mymap;
    ft::map<char,int>::iterator _it;
  
    // insert some values:
    _mymap['a']=10;
    _mymap['b']=20;
    _mymap['c']=30;
    _mymap['d']=40;
    _mymap['e']=50;
    _mymap['f']=60;
    // // show_content
    // // _mymap.printer();
    _it=_mymap.find('b');
    _mymap.erase (_it);                   // erasing by iterator
  
    _mymap.erase ('c');                  // erasing by key
  
    _it= _mymap.find ('e');
    _mymap.erase(_it, _mymap.end());    // erasing by range
  
    for (_it=_mymap.begin(); _it!=_mymap.end(); ++_it)
      std::cout << _it->first << " => " << _it->second << '\n';
    
  }

  {
    red();
    std::cout << "################################ FIND MEMBER FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    std::map<char,int> mymap;
    std::map<char,int>::iterator it;
  
    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;
  
    it = mymap.find('b');
    if (it != mymap.end())
      mymap.erase (it);
  
    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << mymap.find('a')->second << '\n';
    std::cout << "c => " << mymap.find('c')->second << '\n';
    std::cout << "d => " << mymap.find('d')->second << '\n';
    std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
    ft::map<char,int> _mymap;
    ft::map<char,int>::iterator _it;
  
    _mymap['a']=50;
    _mymap['b']=100;
    _mymap['c']=150;
    _mymap['d']=200;
  
   // // show_content
    // // _mymap.printer();
    _it = _mymap.find('b');
    if (_it != _mymap.end())
      _mymap.erase (_it);
   // // show_content
    // // _mymap.printer();
    // print content:
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << _mymap.find('a')->second << '\n';
    std::cout << "c => " << _mymap.find('c')->second << '\n';
    std::cout << "d => " << _mymap.find('d')->second << '\n';
  }

  {
    // red();
    // std::cout << "################################ GET_ALLOCATOR MEMBER FUNCTION TEST################################\n\n";
    // green();
    // std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    // int psize;
    // std::map<char,int> mymap;
    // std::pair<const char,int>* p;

    // // allocate an array of 5 elements using mymap's allocator:
    // p = mymap.get_allocator().allocate(5);

    // // assign some values to array
    // psize = sizeof(std::map<char,int>::value_type)*5;

    // std::cout << "The allocated array has a size of " << psize << " bytes.\n";

    // mymap.get_allocator().deallocate(p,5);

  }
  {
  //   red();
  //   std::cout << "################################ INSERT MEMBER FUNCTION TEST################################\n\n";
  //   green();
  //   std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
  //   ft::map<char,int> mymap;

  // // first insert function version (single parameter):
  //     mymap.insert ( ft::pair<char,int>('a',100) );
  //     mymap.insert ( ft::pair<char,int>('z',200) );
    
  //     ft::pair<ft::map<char,int>::iterator,bool> ret;
  //     ret = mymap.insert ( ft::pair<char,int>('z',500) );
  //     if (ret.second==false) {
  //       std::cout << "element 'z' already existed";
  //       std::cout << " with a value of " << ret.first->second << '\n';
  //     }
  //     // second insert function version (with hint position):
  //     ft::map<char,int>::iterator it = mymap.begin();
  //     mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
  //     mymap.insert (it, ft::pair<char,int>('c',400));  // n
  //     ft::map<char,int> anothermap;
  //     anothermap.insert(mymap.begin(),mymap.find('c'));

  // // showing contents:
  //   std::cout << "mymap contains:\n";
  //   for (it=mymap.begin(); it!=mymap.end(); ++it)
  //     std::cout << it->first << " => " << it->second << '\n';
  
  //   std::cout << "anothermap contains:\n";
  //   for (it=anothermap.begin(); it!=anothermap.end(); ++it)
  //     std::cout << it->first << " => " << it->second << '\n';
  //   mymap.printer();
  }
  {
    red();
    std::cout << "################################ MAX_SIZE FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
    int i;
    std::map<int,int> mymap;

    if (mymap.max_size()> 1000)
    { 
     for (i=0; i<1000; i++) mymap[i]=0;
     std::cout << "The map contains 1000 elements.\n";
    }
    else
      std::cout << "The map could not hold 1000 elements.\n";

      std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
    ft::map<int,int> _mymap;

    if (_mymap.max_size()> 1000)
    { 
     for (int i=0; i<1000; i++) _mymap[i]=0;
     std::cout << "The map contains 1000 elements.\n";
    }
    else
      std::cout << "The map could not hold 1000 elements.\n";
  }

  {
    red();
    std::cout << "################################ OPERATOR[] FUNCTION TEST################################\n\n";
    green();
    std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";

    std::map<char,std::string> mymap;

    mymap['a']="an element";
    mymap['b']="another element";
    mymap['c']=mymap['b'];
  
    std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    std::cout << "mymap['d'] is " << mymap['d'] << '\n';
  
    std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
    std::map<char,std::string> _mymap;

   _mymap['a']="an element";
   _mymap['b']="another element";
   _mymap['c']=_mymap['b'];
  
    std::cout << "_mymap['a'] is " << _mymap['a'] << '\n';
    std::cout << "_mymap['b'] is " << _mymap['b'] << '\n';
    std::cout << "_mymap['c'] is " << _mymap['c'] << '\n';
    std::cout << "_mymap['d'] is " << _mymap['d'] << '\n';
  }

  // {
  //   red();
  //   std::cout << "################################ OPERATOR = FUNCTION TEST################################\n\n";
  //   green();
  //   std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
  //   std::map<char,int> first;
  //   std::map<char,int> second;
  
  //   first['x']=8;
  //   first['y']=16;
  //   first['z']=32;
  
  //   second=first;                // second now contains 3 ints
  //   first=std::map<char,int>();  // and first is now empty
  
  //   std::cout << "Size of first: " << first.size() << '\n';
  //   std::cout << "Size of second: " << second.size() << '\n';
  //   std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
  //   ft::map<char,int> _first;
  //   ft::map<char,int> _second;
  
  //   _first['x']=8;
  //   _first['y']=16;
  //   _first['z']=32;
  // // 
  //   _second = _first;                // second now contains 3 ints
  //   // _first = ft::map<char,int>();  // and first is now empty
  
  //   std::cout << "Size of first: " << _first.size() << '\n';
  //   std::cout << "Size of second: " <<_second.size() << '\n';

  // }
  // {
  //   red();
  //   std::cout << "################################ OPERATOR = FUNCTION TEST################################\n\n";
  //   green();
  //   std::cout <<              " ###################  STD=======>>>>    ####################  \n\n";
  //   std::map<char,int> mymap;

  //   mymap['x'] = 100;
  //   mymap['y'] = 200;
  //   mymap['z'] = 300;
  
  //   // show content:
  //   std::map<char,int>::reverse_iterator rit;
  //   for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
  //     std::cout << rit->first << " => " << rit->second << '\n';
  //   std::cout <<              " \n\n###################  FT=======>>>>    ####################  \n\n";
  //   ft::map<char,int> _mymap;

  //   _mymap['x'] = 100;
  //   _mymap['y'] = 200;
  //   _mymap['z'] = 300;
  
  //   // show content:
  //   std::map<char,int>::reverse_iterator _rit;
  //   for (_rit=_mymap.rbegin(); _rit!=_mymap.rend(); ++_rit)
  //     std::cout << _rit->first << " => " << _rit->second << '\n';


  // }
  
}


int main()
{
    map_tests();
    // system("leaks Map");
}
