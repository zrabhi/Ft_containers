/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zakaria <zakaria@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:09:51 by zrabhi            #+#    #+#             */
/*   Updated: 2022/12/29 16:06:51 by zakaria          ###   ########.fr       */
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
    class RandomAcessIter : public ft::iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef T                                                       Iterator;
            typedef typename    ft::iterator<T>::value_type                 value_type;
            typedef typename    ft::iterator<T>::difference_type           Distance;
            typedef typename    ft::iterator<T>::pointer                    pointer;
            typedef typename    ft::iterator<T>::reference                  reference;
            typedef typename    ft::iterator<T>::iterator_category          iterator_category;
        protected :
            Iterator    _ptr;
        //------Default constructor
        RandomAcessIter(poiner _ptr ) : _ptr(ptr){};
        //------Copy constrcutor
        RandomAcessIter(RandomAcessIter<T> &obj) : _ptr(obj._ptr){};
        //------opreators
        //------(++_ptr)
        RandomAcessIter& operator++() const
        {
            return (++_ptr, *this);    
        }  
        //----(_ptr++)      
        RandomAcessIter& operator++(int) const
        {
            RandomAcessIter tmp = *this;
            return (++_ptr, tmp);
        }
        //----(_ptr--);
        RandomAcessIter& operator--() const
        {
            return(--_ptr, *this);           
        }
        //---(--_ptr)
        RandomAcessIter operator--(int) const
        {
            RandomAcessIter tmp = *this ;
            return (--_ptr, tmp);
        }
        //----Difference
        RandomAcessIter& operator-(difference_type n) const
        {
            return (this->_ptr - n);
        }
        RandomAcessIter& operator+(difference_type n) const
        {
            return (this->_ptr + n);
        }
        RandomAcessIter& operator+=(difference_type n) const
        {
            return (this_ptr +=n, *this );
        }
        RandomAcessIter& operator-=(difference_type n) const
        {
            return (this->_ptr -= n, *this);
        }
        reference operator[](difference_type n)
        {
            return (this->_ptr[n])
        }
    };

}

#endif