#include "map.hpp"


int main()
{
    ft::map<std::string, int> p;

    ft::pair<std::string, int> x("xaaaax", 5);
    // x.first  = "xaaaa";
    // x.second = 5;
    ft::pair<std::string, int> y;
    y.first = "yaaa";
    y.second = 9;
    ft::pair<std::string, int> z;
    z.first = "zaaa";
    z.second = 3;
    ft::pair<std::string, int> i;
    // i["iiiii"] = 10;
    i.first = "iiiii";
    i.second = 10;
    p.insert(x);
    p.insert(y);
    p.insert(z);
    p.insert(i);
    std::cout << "Printing treee " << std::endl;
    p.printer();
    std::cout <<"\n\n" << std::endl;
    std::cout << "size of the map is "  << p.size() << std::endl;
   std::cout << std::boolalpha << p.count("iiiii") << std::endl;
    // p.printer();
}
