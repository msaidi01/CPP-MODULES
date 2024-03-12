/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:07:06 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/11 18:07:10 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>

struct Data
{
    std::string randomStr;
    int index;
};

class Serializer
{
    private:
    Serializer();
    Serializer(Serializer const &src);
    Serializer &operator=(Serializer const &src);
    ~Serializer();
    public:
    static Data* deserialize(uintptr_t raw);
    static uintptr_t serialize(Data *ptr);

};


#endif