/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:27:28 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/23 16:16:57 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template < typename T >
class Array
{
    private:
    T *elements;
    unsigned int size;
    public:
    Array();
    Array(unsigned int n);
    Array(Array &ob);
    Array& operator=(Array &ob);
    ~Array();
    T& operator[](int index);
    
};



#endif