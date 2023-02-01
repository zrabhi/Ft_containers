#include "map.hpp"


int main()
{
    ft::map<std::string, int> p;

    ft::pair<std::string, int> x("e", 5);
    // x.first  = "xaaaa";
    // x.second = 5;
    ft::pair<std::string, int> y;
    y.first = "a";
    y.second = 10;
    ft::pair<std::string, int> z;
    z.first = "b";
    z.second = 20;
    ft::pair<std::string, int> i;
    // i["iiiii"] = 10;
    i.first = "c";
    i.second = 30;
    ft::pair<std::string, int> d("d", 66);
    p.insert(y);
    p.insert(z);
    p.insert(i);
    ft::map<std::string, int> tt(p);
    p.insert(d);
    p.insert(x);
    std::cout << "Printing TT tree\n\n";
    tt.insert(d);
    tt.printer();
    std::cout << "Printing  P treee " << std::endl;
    p.printer();
    tt.swap(p);
     std::cout << "Printing TT tree\n\n";
    // tt.insert(d);

    tt.printer();
    std::cout << "Printing  P treee " << std::endl;
    p.erase(p.begin(), p.end());
    p.printer();

    // std::cout <<"\n\n" << std::endl;
    // std::cout << "size of the map is "  << p.size() << std::endl;
    // std::cout << std::boolalpha << p.count("iiiii") << std::endl;
    // ft::map<std::string, int>::reverse_iterator it;
    // it = p.rend();
    // // ++it;
    // std::cout << "value is " << it->first << std::endl;
    // // p.erase(p.begin());

    // ft::map<std::string, int>::iterator __it;
    // __it = p.begin();

    // std::cout << "begin is " << __it->first <<std::endl;
    // ++__it;
    // std::cout << "the returned node is :" << __it->first << std::endl;
    // ++__it;
    //  std::cout << "the returned node is :" << __it->first << std::endl;
    // ++__it;
    // std::cout << "the returned node is :" << __it->first << std::endl;
    // p.printer();
    // if (it != __it)
    //     std::cout << "its trueee" << std::endl;
    // else
    // std::cout << "operator -----\n\n";
    // // --__it;
    // std::cout << "the returned node is :" << __it->first << std::endl;
    //  --__it;
    // std::cout << "the returned node is :" << __it->first << std::endl;
    // --__it;
    // std::cout << "the returned node is :" << __it->first << std::endl;
    // --__it;
    // std::cout << "the returned node is :" << __it->first << std::endl;


//     std::cout << "creating another object\n\n";
//     ft::map<std::string, int> __i;
//     __i.insert(p.begin(), p.end());
//     std::cout << "Printing treee " << std::endl;
//     __i.printer();
//     __i.erase(p.begin(), p.end());
//     __i.printer();
   
//     ft::pair<ft::map<std::string,int>::iterator, ft::map<std::string,int>::iterator> ret;
//     ret = p.equal_range("b");

//   std::cout << "lower bound points to: ";
//   std::cout << ret.first->first << " => " << ret.first->second << '\n';

//   std::cout << "upper bound points to: ";
//   std::cout << ret.second->first << " => " << ret.second->second << '\n';
//     tt.insert(d);
//     std::cout << "Testing swap fucntion \n\n\n";

//     p.erase("b");
//     std::cout << "printing TT Tree AFTERRR ERASE\n";
//     tt.printer();
//     // if (tt == p)
//     //     std::cout << "they are equal" << std::endl;
//     // tt.swap(p);
//     // std::cout << "printing TT Tree\n";
//     // tt.printer();
//     std::cout << "\nprinting P Tree\n";
//     p.printer();
//     p.clear();
//     std::cout << "\nprinting P Tree\n";
//     p.printer();
//     if (p == tt)
//     p.clear();
//     tt.printer();
    // system("leaks a.out");


//     // p.printer();
//     // system("leaks a.out");
}
