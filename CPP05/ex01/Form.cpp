/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:10:30 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/24 19:10:51 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <string>
#include <ostream>

Form::Form() : _name("zdiad"), _signe(false), _gradeToSigne(10), _gradeToExecute(10)
{}

Form::Form(std::string name, int gradeToSigne, int gradeToExecute): _name(name), _signe(false), _gradeToSigne(gradeToSigne),  _gradeToExecute(gradeToExecute)
{
    if (this->_gradeToExecute > 150 || this->_gradeToSigne > 150)
        throw GradeTooLowException();
    else if (this->_gradeToExecute < 1 || this->_gradeToSigne < 1)
        throw GradeTooHighException();
}

Form::Form(Form &ob): _name(ob._name), _gradeToSigne(ob._gradeToSigne), _gradeToExecute(ob._gradeToExecute)
{
    *this = ob;
}

Form& Form::operator=(Form &ob)
{
    if (this != &ob)
    {
        this->_signe = ob._signe;
    }
    return *this;
}

Form::~Form()
{}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::getSigne() const
{
    return this->_signe;    
}

int Form::getGradeToSigne() const
{
    return this->_gradeToSigne;
}

int Form::getGradeToExecute() const
{
    return this->_gradeToExecute;    
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

std::ostream& operator<<(std::ostream& os, const Form& a)
{
    os << a.getName() << ", grade to signe: "<< a.getGradeToSigne() << ", grade to execute: " \
    << a.getGradeToSigne() << ", signe: ", a.getSigne();
    
    return os;
}

void Form::beSigned(Bureaucrat &ob)
{
    if (ob.getGrade() <= this->_gradeToSigne)
        this->_signe = true;
    else
        throw GradeTooLowException();
}
