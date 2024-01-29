/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 02:27:56 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/26 04:26:45 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

class HumanA
{
    private:
    std::string name;
    Weapon &A;
    public:
    HumanA(std::string name,Weapon &arm);
    void attack();
};
