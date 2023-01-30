#include "map.hpp"


int main()
{
    ft::map<std::string, int> p;
    ft::map<std::string, int> tt(p);

    // ft::pair<std::string, int> x("xaaaax", 5);
    // x.first  = "xaaaa";
    // x.second = 5;
    ft::pair<std::string, int> y;
    y.first = "a";
    y.second = 9;
    ft::pair<std::string, int> z;
    z.first = "b";
    z.second = 3;
    ft::pair<std::string, int> i;
    // i["iiiii"] = 10;
    i.first = "c";
    i.second = 10;
    // p.insert(x);
    p.insert(y);
    p.insert(z);
    p.insert(i);
    std::cout << "Printing treee " << std::endl;
    p.printer();
    std::cout <<"\n\n" << std::endl;
    std::cout << "size of the map is "  << p.size() << std::endl;
    std::cout << std::boolalpha << p.count("iiiii") << std::endl;
    ft::map<std::string, int>::reverse_iterator it;
    it = p.rend();
    // ++it;
    std::cout << "value is " << it->first << std::endl;
    // p.erase(p.begin());
    // p.printer();

    ft::map<std::string, int>::reverse_iterator __it;
    __it = p.rbegin();
    if (it != __it)
        std::cout << "its trueee" << std::endl;
    else
        std::cout << "its falsee" << std::endl;
    std::cout << "the returned node is :" << __it->first << std::endl;
    // if (p == tt)
    //     std::cout << "they are equal" << std::endl;
    p.clear();
    tt.printer();


    // p.printer();
    // system("leaks a.out");
}
