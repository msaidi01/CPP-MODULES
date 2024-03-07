/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:59:45 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/07 01:14:26 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include <cstdlib>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("robotForm", 72, 45), _target("robotForm")
{}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
    _target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ob) : AForm(ob)
{
    *this = ob;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &ob)
{
    if (this != &ob)
    {
        _target = ob._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > this->getGradeToSigne() || executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    if (!this->getSigne())
    {
        throw AForm::notSignedException();
    }
    std::cout << "VRRR ! VRRRR! VRR!" << std::endl;
    std::srand(std::time(NULL));
    unsigned int random = std::rand();
    if (random % 2 == 0)
        std::cout << this->_target << " has been robotomized successfully !" << std::endl;
    else
        std::cout << " Robotomy has failed!" << std::endl;
}
