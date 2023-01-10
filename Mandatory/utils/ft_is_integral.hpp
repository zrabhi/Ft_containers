/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integral.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:06:48 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/10 19:31:48 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <type_traits>
#include <iostream>

namespace ft
{
    template< class T>
    struct is_integral : std::integral_constant
    {
        std::is_same<T, bool>::value ||
        std::is_same<T, char>::value||
        std::is_same<T, char16_t>::value ||
        std::is_same<T, char32_t>::value ||
        std::is_same<T, wchar_t>::value ||
        std::is_same<T, signed char>::value ||
        std::is_same<T, signed int>::value  ||
        std::is_same<T, short int>::value ||
        std::is_same<T, int>::value ||
        std::is_same<T, long int>::value ||
        std::is_same<T, long long int>::value ||
        std::is_same<T, unsigned char>::value ||
        std::is_same<T, unsigned short int>::value ||
        std::is_same<T, unsigned int>::value ||
        std::is_same<T, unsigned long int>::value ||       
        std::is_same<T, unsigned long long int>::value
    };
        


}