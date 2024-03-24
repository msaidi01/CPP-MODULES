/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:27:28 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/24 02:50:03 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <limits>
#include <stdexcept>
template < typename T >
class Array
{
    private:
    T *elements;
    unsigned int Size;
    public:
    Array();
    Array(unsigned int n);
    Array(Array &ob);
    Array& operator=(Array &ob);
    ~Array();
    T& operator[](unsigned int index);
    unsigned int size();
};

template < typename T >
Array<T>::Array()
{
    elements = 0;
    Size = 0;
}

template < typename T >
Array<T>::Array(unsigned int n)
{
    if (n > std::numeric_limits<unsigned int>().max() || n < 0)
        throw std::out_of_range("Index out of range");
    elements = new T[n];
    Size = n;
}

template < typename T >
Array<T>::Array(Array &ob)
{
    if (this == &ob)
        return;
    Size = ob.Size;
    elements = new T[Size];
    for (unsigned int i = 0; i < Size; i++)
        elements[i] = ob.elements[i];
}

template < typename T >
Array<T>& Array<T>::operator=(Array &ob)
{
    if (elements)
        delete[] elements;
    elements = new T[ob.Size];
    Size = ob.Size;
    for (unsigned int i = 0; i < Size; i++)
        elements[i] = ob.elements[i];
    return *this;
}

template < typename T >
Array<T>::~Array()
{
    if (elements)
        delete[] elements;
}

template < typename T >
T& Array<T>::operator[](unsigned int index)
{
    if (index < 0 || index >= Size)
        throw std::out_of_range("Index out of range");
    return elements[index];
}

template < typename T >
unsigned int Array<T>::size()
{
    return Size;
}

#endif