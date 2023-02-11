/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:36:52 by zrabhi            #+#    #+#             */
/*   Updated: 2023/02/11 15:56:05 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <deque>
# include <memory>
# include "../vector/vector.hpp"
# include "../utils/ft_enable_if.hpp"
# include "../utils/ft_is_integral.hpp"

namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack {
        
            public:
                typedef             T                   value_type;
                typedef             Container           container_type;
                typedef             std::size_t         size_type;
            
            protected:
                container_type c;
            public:
                explicit    stack (const container_type& ctnr = container_type()) : c(ctnr)
                {
                    
                }
                
            size_type size() const
            {
                return (c.size());    
            }
            
            void    push (const value_type& val)
            {
                c.insert(c.begin(), val);
            }
            
            void    pop()
            {
                c.erase(c.begin());
            }
            
            value_type& top()
            {
                return (*(c.begin()));
            }
            
            const value_type& top() const
            {
                return (*(c.begin()));
            }

            bool empty() const 
            {
                if (c.size())
                    return (false);
                return (true);    
            }
            
        friend bool operator== (const stack& lhs, const stack& rhs)
        {
              return (lhs.c == rhs.c) ;
        }
        
        friend bool operator!= (const stack& lhs, const stack& rhs)
        {
          return lhs.c != rhs.c;
        }
          
        friend bool operator<  (const stack& lhs, const stack& rhs)
        {
            return (lhs.c < rhs.c);
        }
          
        friend bool operator<= (const stack& lhs, const stack& rhs)
        {
              return (lhs <= rhs);
        }
        
        friend bool operator>  (const stack& lhs, const stack& rhs)
        {
            return (lhs.c > rhs.c);
        }
        
        friend bool operator>= (const stack& lhs, const stack& rhs)
        {
              return (lhs.c >= rhs.c);
        }
    };
}




#endif