#ifndef FT_DEFINES_HPP
# define FT_DEFINES_HPP

#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[1;33m"
#define RESET "\e[0m"

void    blue()
{
    // std::cout << BLUE;
}

void    red()
{
    std::cout << RED;
}

void    green()
{
    std::cout << GREEN;
}

void yellow()
{
    // std::cout << YELLOW;
}

void    reset()
{
    std::cout << "\033[30m";
}

#endif
