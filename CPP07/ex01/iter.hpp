/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 01:43:40 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/23 02:22:32 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP


template < typename T, typename U >
void    iter(T arr[], int length, void (*func)(U))
{
   for (int i = 0; i < length; i++)
		func(arr[i]);
}


#endif