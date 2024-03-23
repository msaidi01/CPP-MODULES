/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:27:31 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/23 16:29:58 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    this->elements = new T();
    this->size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
    
}

template <typename T>
Array<T>::Array(Array<T> &ob)
{
    
}

template <typename T>
Array<T>::~Array()
{
    if (this->elements)
        delete[] this->elements;
}