/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:10:30 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/01 09:25:13 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <string>
#include <ostream>

AForm::AForm() : _name("zdiad"), _signe(false), _gradeToSigne(10), _gradeToExecute(10)
{}

AForm::AForm(std::string name, int gradeToSigne, int gradeToExecute): _name(name), _signe(false), _gradeToSigne(gradeToSigne),  _gradeToExecute(gradeToExecute)
{
    if (this->_gradeToExecute > 150 || this->_gradeToSigne > 150)
        throw GradeTooLowException();
    else if (this->_gradeToExecute < 1 || this->_gradeToSigne < 1)
        throw GradeTooHighException();
}

AForm::AForm(AForm const &ob): _name(ob._name), _gradeToSigne(ob._gradeToSigne), _gradeToExecute(ob._gradeToExecute)
{
    *this = ob;
}

AForm& AForm::operator=(AForm const &ob)
{
    if (this != &ob)
    {
        this->_signe = ob._signe;
    }
    return *this;
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigne() const
{
    return this->_signe;    
}

int AForm::getGradeToSigne() const
{
    return this->_gradeToSigne;
}

int AForm::getGradeToExecute() const
{
    return this->_gradeToExecute;    
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}
const char* AForm::notSignedException::what() const throw()
{
    return "AForm not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& a)
{
    os << a.getName() << ", grade to signe: "<< a.getGradeToSigne() << ", grade to execute: " \
    << a.getGradeToSigne() << ", signe: ", a.getSigne();
    
    return os;
}

void AForm::beSigned(Bureaucrat const &ob)
{
    if (ob.getGrade() <= this->_gradeToSigne)
        this->_signe = true;
    else
        throw GradeTooLowException();
}
