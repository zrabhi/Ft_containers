/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enable_if.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zrabhi <zrabhi@student.1337.ma >           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:24:59 by zrabhi            #+#    #+#             */
/*   Updated: 2023/01/12 00:31:30 by zrabhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ENABLE_IF_HPP
# define FT_ENABLE_IF_HPP

namespace ft{

    template<bool Cond, class T = void>
    struct enable_if{
        
    };
    
    template<class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
}
#endif