/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 10:30:24 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/11 17:53:06 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <iostream>
# include "../utils/ft_defines.hpp"

#if STL
  #include <map>
  namespace ft = std;
#else
  #include "map.hpp"
#endif

void map_tests()
{
    // ft::map<int, int> mymap;
    
    // for(int i = 0 ; i < 10000000; i++)
    // {
    //    mymap.insert(ft::pair<int, int>(i, i));
    // }
  {  
    red();
    std::cout << "################################ CLEAR MEMBER FUNCTION TEST################################\n\n";
    green();
    ft::map<char,int> mymap;

    mymap['x']=100;
    mymap['y']=200;
    mymap['z']=300;
  
    std::cout << "mymap contains:\n";
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
  
    mymap.clear();
    mymap['a']=1101;
    mymap['b']=2202;
  
    std::cout << "mymap contains:\n";
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
  }

  {  
    red();
    std::cout << "################################ COUNT MEMBER FUNCTION TEST################################\n\n";
    green();
    ft::map<char,int> mymap;
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
  }

  {
    red();
    std::cout << "################################ EMPTY MEMBER FUNCTION TEST################################\n\n";
    green();
    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
  
    while (!mymap.empty())
    {
      std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
      mymap.erase(mymap.begin());
    }
  }


  {
    red();
    std::cout << "################################ END MEMBER FUNCTION TEST################################\n\n";
    green();
    ft::map<char,int> mymap;

    mymap['b'] = 100;
    mymap['a'] = 200;
    mymap['c'] = 300;

    // show content:
    
    for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
      std::cout << it->first << " => " << it->second << '\n';
  }
  
  {
    red();
    std::cout << "################################ EQUAL_RANGE || LOWER_BOUND || UPPER_BOUND  MEMBER FUNCTION TEST################################\n\n";
    green();
    ft::map<char,int> mymap;

    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
  
    ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    ret = mymap.equal_range('b');
  
    std::cout << "lower bound points to: ";
    std::cout << ret.first->first << " => " << ret.first->second << '\n';
  
    std::cout << "upper bound points to: ";
    std::cout << ret.second->first << " => " << ret.second->second << '\n';
    
  }

  {
    red();
    std::cout << "################################ ERASE MEMBER FUNCTION TEST################################\n\n";
    green();
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
    std::cout << "elements in mymap:" << '\n';
    std::cout << "a => " << _mymap.find('a')->second << '\n';
    std::cout << "c => " << _mymap.find('c')->second << '\n';
    std::cout << "d => " << _mymap.find('d')->second << '\n';
  }

  {
    red();
    std::cout << "################################ GET_ALLOCATOR MEMBER FUNCTION TEST################################\n\n";
    green();
    int psize;
    ft::map<char,int> mymap;
    ft::pair<const char,int>* p;

    // allocate an array of 5 elements using mymap's allocator:
    p = mymap.get_allocator().allocate(5);
    std::cout <<  " size of pair object is "<< sizeof(p) << "bytes\n";
    // assign some values to array
    psize = sizeof(ft::map<char,int>::value_type)*5;

    std::cout << "The allocated array has a size of " << psize << " bytes.\n";

    mymap.get_allocator().deallocate(p,5);

  }
  {
 
    red();
    std::cout << "################################ INSERT MEMBER FUNCTION TEST################################\n\n";
    green();
    ft::map<char,int> mymap;

  // first insert function version (single parameter):
  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('z',200) );

  ft::pair<ft::map<char,int>::iterator,bool> ret;
  ret = mymap.insert ( ft::pair<char,int>('z',500) );
  if (ret.second == false) {
    std::cout << "element 'z' already existed";
    // std::cout << "im hereee\n";
    std::cout << " with a value of " << ret.first->second << '\n';
    // std::cout << "im hereee\n";

  }

  // second insert function version (with hint position):
  ft::map<char,int>::iterator it = mymap.begin();
  mymap.insert (it, ft::pair<char,int>('b',300));  
  mymap.insert (it, ft::pair<char,int>('c',400));  

  ft::map<char,int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));
//  std::cout << "im hereee\n";

    //anothermap.printer();
    //mymap.printer();
//   // showing contents:
  std::cout << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  std::cout << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
  }
  

  {
    red();
    std::cout << "################################ OPERATOR[] FUNCTION TEST################################\n\n";
    green();

    
    ft::map<char,std::string> _mymap;

   _mymap['a']= "an element";
   _mymap['b']= "another element";
   _mymap['c']= _mymap['b'];
  
    std::cout << "_mymap['a'] is " << _mymap['a'] << '\n';
    std::cout << "_mymap['b'] is " << _mymap['b'] << '\n';
    std::cout << "_mymap['c'] is " << _mymap['c'] << '\n';
    std::cout << "_mymap['d'] is " << _mymap['d'] << '\n';

    std::cout << "mymap now contains " << _mymap.size() << " elements.\n";
  }
  
  {
    red();
    std::cout << "################################ OPERATOR =  || RRBEGIN  || REND  TEST################################\n\n";
    green();
    ft::map<char,int> first;
    ft::map<char,int> second;

    first['x']=8;
    first['y']=16;
    first['z']=32;

    second=first;                // second now contains 3 ints
    first=ft::map<char,int>();  // and first is now empty

    std::cout << "Size of first: " << first.size() << '\n';
  }

  {
      red();
      std::cout << "################################ RELATION OPERATORS TEST################################\n\n";
      green();
      ft::map<char,int> foo,bar;
      foo['a']=100;
      foo['b']=200;
      bar['a']=10;
      bar['z']=1000;
    
      // foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
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
  }
}
    
  
int main()
{
    map_tests();
}
