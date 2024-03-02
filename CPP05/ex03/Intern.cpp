/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 09:50:13 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/01 11:50:11 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <cstddef>
#include <iostream>

Intern::Intern()
{}

Intern::Intern(Intern const &ob)
{
    *this = ob;
}


Intern& Intern::operator=(Intern const &ob)
{
    if (this != &ob)
    {
        *this = ob;
    }
    return *this;
}

Intern::~Intern()
{
    
}

AForm *Intern::makeShrubberyCreation(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequest(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}


AForm *Intern::makeForm(std::string formName, std::string target)
{
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(Intern::*ptrForm[3])(std::string) = {&Intern::makeShrubberyCreation, &Intern::makeRobotomyRequest, &Intern::makePresidentialPardon};
    
    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            return (this->*ptrForm[i])(target);
        }
    }
    std::cout << "Form not found" << std::endl;
    return NULL;
}
