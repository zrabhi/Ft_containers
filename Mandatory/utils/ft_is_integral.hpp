/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_integral.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:06:48 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/12 00:50:15 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_INTEGRAL_HPP
# define FT_IS_INTEGRAL_HPP
#include <type_traits>
#include <iostream>


namespace ft
{ 


//    trying to implement true_type and false type struct 
    struct false_type
    {
        const static bool value = false;
    } ;
    struct true_type
    {
        const static bool value = true;
    };
    
    template <class T, class U>
    struct is_same : public ft::false_type 
    {
        // true_type.value = true;
    };
    template <class _T>
    struct is_same<_T, _T> : public ft::true_type
    {
        // true_type.value = true;
    };
    template <class T, bool _v = false>
    struct integral_constant {
        static const bool value = _v;
    };
    template <class T>
    struct is_integral : ft::integral_constant<T, ft::is_same<int, T>::value 
        || ft::is_same<bool, T>::value || ft::is_same<char, T>::value
        || ft::is_same<char16_t, T>::value || ft::is_same<char32_t, T>::value 
        || ft::is_same<wchar_t, T>::value || ft::is_same<signed char, T>::value 
        || ft::is_same<signed int, T>::value ||ft::is_same<short int, T>::value
        || ft::is_same<long int , T>::value || ft::is_same<long long int, T>::value 
        || ft::is_same<unsigned char, T>::value || ft::is_same<unsigned short int, T>::value 
        || ft::is_same<unsigned int, T>::value || ft::is_same<unsigned long int, T>::value 
        || ft::is_same<unsigned long long int, T>::value >
    {
    };

    // template <class T>
    // struct is_integral {
    //     static const bool value = false;
    // };

    // template <int>
    // struct ft_is_integral
    // {
    //     const static bool value = true;
    // };
    
    
    
};
#endif