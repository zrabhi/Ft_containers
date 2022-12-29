/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:09:51 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/29 19:45:42 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VCETOR_HPP
#define ITEARTOR_VECTOR_HPP

#include "iteretor_traits.hpp"
#include <iterator>

//---normal_iterator
namespace ft
{
    template<typename T>
    class RandomAccessIter : public ft::iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef T                                                                                                     Iterator;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T>>::value_type         value_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T>>::difference_type    Distance;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T>>::pointer            pointer;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T>>::reference          reference;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T>>::iterator_category  iterator_category;
       
        protected :
            Iterator    _ptr;
        public:
        //------Default constructor
            RandomAccessIter(poiner _ptr ) : _ptr(ptr){};
            //------Copy constrcutor
            RandomAccessIter(RandomAccessIter<T> &obj) : _ptr(obj._ptr){};
            //------opreators
            //------(++_ptr)
            RandomAccessIter& operator++() const
            {
                return (++_ptr, *this);    
            }  
            //----(_ptr++)      
            RandomAccessIter& operator++(int) const
            {
                RandomAccessIter tmp = *this;
                return (++_ptr, tmp);
            }
            //----(_ptr--);
            RandomAccessIter& operator--() const
            {
                return(--_ptr, *this);           
            }
            //---(--_ptr)
            RandomAccessIter operator--(int) const
            {
                RandomAccessIter tmp = *this ;
                return (--_ptr, tmp);
            }
            reference operator*() const
            {
                return (*_ptr);
            }
            //----Difference
            RandomAccessIter& operator-(difference_type n) const
            {
                return (this->_ptr - n);
            }
            RandomAccessIter& operator+(difference_type n) const
            {
                return (this->_ptr + n);
            }
            RandomAccessIter& operator+=(difference_type n) const
            {
                return (this_ptr +=n, *this );
            }
            RandomAccessIter& operator-=(difference_type n) const
            {
                return (this->_ptr -= n, *this);
            }
            reference operator[](difference_type n)
            {
                return (this->_ptr[n])
            }
            //----compar--operators
            bool  operator==(const RandomAccessIter& iter) const
                {
                    return (_ptr == iter1._ptr);
                }
            bool operator>( const RandomAccessIter& iter) const
                {
                    return (_ptr > iter._ptr);     
                }
            bool operator<(const RandomAccessIter& iter) const
                {
                    return (_ptr < iter._ptr);
                }
            bool operator <=(const RandomAccessIter& iter) const
                {
                    return (!(_ptr > iter._ptr));
                }
            bool operator >=(const RandomAccessIter& iter ) const
            {
                return (!(_ptr < iter._ptr));
            }
    };
}


#endif