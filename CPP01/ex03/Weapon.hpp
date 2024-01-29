/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 00:30:56 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/26 03:29:42 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
class Weapon 
{
    private:
    std::string type;
    public:
    Weapon(std::string type);
    const std::string &getType();
    void setType(std::string type);
};
#endif