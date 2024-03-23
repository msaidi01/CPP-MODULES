/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:21:03 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/22 23:52:58 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


template <typename T >
T& min(T &x, T &y)
{
    return (x < y ? x : y);
}


template <typename T >
T& max(T &x, T &y)
{
    return (x > y ? x : y);
}


template <typename T >
void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

#endif
