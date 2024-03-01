/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:50:37 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/01 09:15:17 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("Pardon", 25, 5), _target("Pardon")
{}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & ob) : AForm(ob)
{
    *this = ob;
}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & ob)
{
    if (this != &ob)
    {
        this->_target = ob._target;
    }
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (!this->getSigne())
    {
        throw AForm::notSignedException();
    }
    std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
