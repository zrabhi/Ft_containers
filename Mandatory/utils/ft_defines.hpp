#ifndef FT_DEFINES_HPP
# define FT_DEFINES_HPP

# define BLUE "\e[0;34m"
# define RED "\e[0;31m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RESET "\e[0m"
# define BLUE_COLOR    std::cout << BLUE
# define GREEN_COLOR   std::cout << GREEN;
# define RED_COLOR     std::cout <<  RED;
// # define STACK "../stack/stack.hpp"
// # define VECTOR "../vector/vector.hpp"

#include <iostream>

void    vector_tests();
void    map_tests();
void    stack_tests();
#endif
