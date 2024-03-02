/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:50:08 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/01 11:48:31 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"


class AForm;

class Intern
{
    public:
    Intern();
    Intern(Intern const &ob);
    Intern& operator=(Intern const &ob);

    ~Intern();
    
    AForm *makeShrubberyCreation(std::string target);
    AForm *makeRobotomyRequest(std::string target);
    AForm *makePresidentialPardon(std::string target);
    
    AForm *makeForm(std::string formName, std::string target);
};

#endif