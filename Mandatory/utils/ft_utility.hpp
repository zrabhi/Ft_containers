/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utility.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:54:08 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/25 18:27:35 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILITY_HPP
# define FT_UTILITY_HPP

namespace ft
{
    template<class T1, class T2>
    struct pair
    {
        // private:
            typedef T1  first_type;
            typedef T2  seconde_type;   
        first_type      first;
        seconde_type    second;
        public:
            
        //---default constructor
        pair() : first(), second(0)
        {}     
        template<class U, class V>
        pair(const pair<U,V>& pr)
        {
            if (*this != pr)
            {
                this->first  = pr.first;
                this->second = pr.second;
            }
        } 
        //----third constructor
        pair(const first_type& a, const seconde_type& b) :  first(a), second(b)
        {
        }
        // copy assignement 
        pair& operator = (const pair& pr)
        {
            if (*this != pr)
            {
                this->first = pr.first;
                this->second = pr.second;
            }
            return (*this);
        };

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