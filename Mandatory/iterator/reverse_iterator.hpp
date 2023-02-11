/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:29:30 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/11 18:29:16 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef   REVERSE_ITERATOR_HPP
# define  REVERSE_ITERATOR_HPP
//  # include "iteretor_traits.hpp"
namespace ft
{
 template <class T>
    class reverse_iterator : public ft::iterator<typename  ft::iterator_traits<T>::iterator_category  , T>
     {
         
        public:
            typedef T                                                                                      iterator_type;
            typedef typename    ft::iterator_traits<iterator_type>::value_type                             value_type;
            typedef typename    ft::iterator_traits<iterator_type>::Distance                               difference_type;
            typedef typename    ft::iterator_traits<iterator_type>::pointer                                pointer;
            typedef typename    ft::iterator_traits<iterator_type>::reference                              reference;
            typedef typename    ft::iterator_traits<iterator_type>::iterator_category                      iterator_category;
            typedef typename    ft::reverse_iterator<iterator_type>                                        __return_type;
        protected:
            iterator_type Iter;
        public:
        
            reverse_iterator() : Iter()
            {};
            
            explicit reverse_iterator(iterator_type iterator) : Iter(iterator)  
            {};
            
            template <class Iter>
            reverse_iterator(const reverse_iterator<Iter>& obj) 
            {
                *this = obj;
            };
           
            __return_type&  operator++()
            {
                --Iter;
                return *this;
            };
            
            __return_type operator++(int)
            {
                Iter--;
                return (*this);
            };

            __return_type& operator--()
            {
               ++Iter;
                return (*this);
            };

            __return_type operator--(int)
            {
                Iter++;
                return (*this);
            };
            
            __return_type& operator=(__return_type const &pr)
            {
                Iter = pr.base();
                return (*this);   
            };
            
            reference   operator*() const
            {
                iterator_type __tmp;
                __tmp = Iter;
                --__tmp;
                return (*__tmp);
            };

            pointer     operator->() const
            {
                iterator_type __tmp;
                __tmp = Iter;
                --__tmp;
                return (__tmp.operator->());
            };
            
            pointer     operator->() 
            {
                iterator_type __tmp;
                __tmp = Iter;
                --__tmp;
                return (__tmp.operator->());
            };

            __return_type&	operator+=(difference_type n )
            { 
                Iter -= n; 
                return (*this) ; 
            };

            __return_type& operator-= (difference_type n)
            {
                Iter += n; 
                return (*this) ;
            };
            
            reference operator[] (difference_type n) const
            {
                Iter += n;
                return (*this);    
            };

            iterator_type base() const
            {
                return (Iter);
            };
            
            bool operator==(const __return_type& pr) const
            {
                return (Iter == pr.Iter);
            } ;

            bool operator!=(const __return_type& pr) const
            {
                return (this->Iter != pr.Iter);
            };
    };

    template <class Iterator>  
    typename reverse_iterator<Iterator>::difference_type operator- (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);
    
    
    template <class Iterator> 
    reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it);

    template <class Iterator> 
    bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs);

    template <class Iterator>
    bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    
    
   template <class Iterator>
    bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    
   template <class Iterator>
    bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    
   template <class Iterator>
    bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    
   template <class Iterator>
    bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }

}

#endif