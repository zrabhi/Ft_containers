/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:09:51 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/28 22:42:42 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_VECTOR_HPP
#define ITERATOR_VECTOR_HPP

#include "iteretor_traits.hpp"
#include <iterator>

//---normal_iterator
namespace ft
{ 
    template<typename T>
    class RandomAccessIter : public ft::iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef T                                                                                                       Iterator;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::value_type          value_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::Distance            difference_type;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::pointer             pointer;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::reference           reference;
            typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::iterator_category   iterator_category;
       
        protected :
            pointer    _ptr;
        public:
        //------Default constructor

            RandomAccessIter(): _ptr(nullptr)
            {}; 
          
            RandomAccessIter(pointer ptr ) : _ptr(ptr)
            {};

            RandomAccessIter(const RandomAccessIter<T> &obj) : _ptr(obj._ptr)
            {};
            
            
            RandomAccessIter& operator++() 
            {
                return (++_ptr, *this);    
            }  

            RandomAccessIter operator++(int) 
            {
                RandomAccessIter tmp(*this);
                return (++_ptr, tmp);
            }

            RandomAccessIter& operator--() 
            {
                return(--_ptr, *this);           
            }

            RandomAccessIter operator--(int) 
            {
                RandomAccessIter tmp(*this) ;
                return (--_ptr, tmp);
            }
            RandomAccessIter& operator=(RandomAccessIter obj)
            {
                if (*this != obj)
                {
                    this->_ptr =obj._ptr;
                }
                return ( *this);
            }
            reference operator*() const
            {
                return (*_ptr);
            }

            RandomAccessIter& operator-(difference_type n) 
            {
                return ((this->_ptr = this->_ptr - n), *this);
            }
            RandomAccessIter& operator+(difference_type n) 
            {
                return ((this->_ptr = this->_ptr + n), *this);
            }
        
            RandomAccessIter& operator+=(difference_type n) const
            {
                return (this->_ptr +=n, *this );
            }
            
            RandomAccessIter& operator-=(difference_type n) const
            {
                return (this->_ptr -= n, *this);
            }
            
            reference operator[](difference_type n)
            {
                return (this->_ptr[n]);
            }
    
            bool  operator==(const RandomAccessIter& iter) const
            {
                return (_ptr == iter._ptr);
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
            bool operator!=(const RandomAccessIter& iter) const
            {
                return (this->_ptr != iter._ptr);
            }
    };
    //----reverse__iterator---
        template<typename T>
        class RandomAccessIterRev : public ft::iterator<std::random_access_iterator_tag, T>
        {
                public:
                    typedef T                                                                                                      Iterator;
                    typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::value_type         value_type;
                    typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::Distance           difference_type;
                    typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::pointer            pointer;
                    typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::reference          reference;
                    typedef typename    ft::iterator_traits<ft::iterator<std::random_access_iterator_tag, T> >::iterator_category  iterator_category;
                protected:
                    pointer _ptr;
                public:
                    RandomAccessIterRev() : _ptr(nullptr)
                    {};
                
                    RandomAccessIterRev(pointer ptr) : _ptr(ptr)
                    {};
                
                    RandomAccessIterRev(const RandomAccessIterRev<T>& obj) : _ptr(obj._ptr)
                    {};
                
                    RandomAccessIterRev& operator++()
                    {
                        return (--_ptr, *this);    
                    }
                
                    RandomAccessIterRev& operator--()
                    {
                        return (++_ptr, *this);
                    }
                
                    RandomAccessIterRev operator--(int)
                    {
                        RandomAccessIterRev tmp(*this);
                        return (++_ptr, *this);
                    }
                
                    RandomAccessIterRev operator++(int)
                    {
                        RandomAccessIterRev tmp(*this);
                        return (--_ptr, *this);   
                    }
                    
                    RandomAccessIterRev& operator=(RandomAccessIterRev& obj)
                    {
                        return (this->_ptr = obj._ptr, *this);
                    }
                    
                    RandomAccessIterRev& operator+(difference_type n)
                    {
                        return (this->_ptr = this->_ptr - n, *this);
                    } 
                
                    RandomAccessIterRev& operator-(difference_type n)
                    {
                        return (this->_ptr = this->_ptr + n, *this);
                    }
                
                    RandomAccessIterRev& operator-=(difference_type n)
                    {
                        return (this->_ptr -=n, *this);
                    }
                
                    RandomAccessIterRev& operator+=(difference_type n)
                    {
                        return (this->_ptr += n, *this);
                    }
                    reference operator*()
                    {
                        return (*_ptr);
                    }
                    reference operator[](difference_type n)
                    {
                        return (this->_ptr[n]);
                    }
                    bool  operator==(const RandomAccessIterRev& iter) const
                    {
                        return (_ptr == iter._ptr);
                    }
            
                    bool operator>( const RandomAccessIterRev& iter) const
                    {
                        return (_ptr > iter._ptr);     
                    }
                
                    bool operator<(const RandomAccessIterRev& iter) const
                    {
                        return (_ptr < iter._ptr);
                    }
                
                    bool operator <=(const RandomAccessIterRev& iter) const
                    {
                        return (!(_ptr > iter._ptr));
                    }
            
                    bool operator >=(const RandomAccessIterRev& iter ) const
                    {
                        return (!(_ptr < iter._ptr));
                    }
        
                    bool operator!=(const RandomAccessIterRev& iter) const
                    {
                        return (this->_ptr != iter._ptr);
                    }
            //----member fucntions;                  
        };
}


#endif