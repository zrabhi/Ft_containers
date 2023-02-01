/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:24:12 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/01 01:17:29 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHM_HPP
# define FT_ALGORITHM_HPP

# include <utility>

namespace ft
{
    template  <class InputIterator1, class InputIterator2>
        bool equal(InputIterator1 first1, InputIterator1 last1, 
                                InputIterator2 first2)
        {
            while (first1 != last1)
            {
                if (!(*first1 == *first2))
                        return (false);
                ++first1;
                ++first2;    
            }
            return (true);            
        }
    template <class InputIterator1, class InputIterator2>
        bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
        {
            while (first1 != last1)
            {
                if (first2 == last2 || *first2 < *first1)
                    return (false);
                else if (*first1 < *first2)
                    return (true);
                ++first1;
                ++first2;
            }
            return (first2 != last2);
        }
    
    template <class InputIter>
    size_t difference(InputIter first, InputIter last)
    {
        return (last - first);
    }

    template <class T> void swap ( T& a, T& b )
    {
        T c(a);
        a = b; 
        b = c;
    }
}

template <typename T>
const T& min(const T& a, const T& b)
{
  return (a < b) ? a : b;
}

#endif
