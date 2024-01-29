/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 03:08:42 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/26 04:28:55 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
    std::string name;
    Weapon *weapon;
    public:
    HumanB(std::string name);
    void setWeapon(Weapon &arm);
    std::string getWeapon();
    void attack();
};
