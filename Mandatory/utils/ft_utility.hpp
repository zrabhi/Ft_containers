/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:54:08 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/27 23:44:35 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_HPP
# define FT_UTILITY_HPP


#include <iostream>

namespace ft
{
    template<class T1, class T2>
    struct pair
    {
        typedef T1      first_type;
        typedef T2      seconde_type; 
          
        first_type      first;
        seconde_type    second;
        
        pair(first_type const &__a, seconde_type const &__b) :  first(__a), second(__b)
        {}
        
        template <class _U1, class _U2>
        pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) 
        {}
        
        pair() : first(), second(0)
        {}     
        
        pair& operator=(pair const &pr)
        {
            if (*this != pr)
            {
                this->first  = pr.first;
                this->second = pr.second;
            }
            return (*this);
        };
    
        const first_type& getFirst() const
        {
            return (first);
        }

        const seconde_type& getSecond() const{
            return (second);
        }

};
   
    template <class T1, class T2>
bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
    return lhs.first==rhs.first && lhs.second==rhs.second;
    }
template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs==rhs);
    }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); 
    }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
    return !(rhs<lhs);
    }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (rhs < lhs);
    }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs<rhs); 
    }    

    //-----fucntion template make_pair
    template <class T1, class T2>
    pair<T1,T2> make_pair(T1 x, T2 y)
    {
        return (pair<T1,T2>(x,y));
    }
} // namespace ft


#endif