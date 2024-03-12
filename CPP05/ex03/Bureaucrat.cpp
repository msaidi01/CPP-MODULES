/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:51:05 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/08 18:33:49 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <exception>
#include <string>
#include <iostream>

Bureaucrat::Bureaucrat(): name("amine")
{
	this->grade = 150;
}
Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
	if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade < 1){
		throw GradeTooHighException();
	}
	else {
		this->grade = grade;
	}
}
Bureaucrat::Bureaucrat(Bureaucrat &ob)
{
	*this = ob;
}
Bureaucrat& Bureaucrat::operator=(Bureaucrat &ob) 
{
	if (this != &ob)
    {
        this->grade = ob.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
	return this->name;
}
int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::incGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	this->grade--;
}
void Bureaucrat::decGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	this->grade++;
	
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a)
{
	os << a.getName() << ", bureaucrat grade " << a.getGrade() << ".";
	return os;
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too Low";	
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too High";	
}

void Bureaucrat::signForm(AForm &ob)
{
	try 
	{
		if (ob.getSigne() == true)
		{
			std::cout << this->getName() << " couldn't sign " << ob.getName() << " because it was already signed." << std::endl;
			return ;
		}
		ob.beSigned(*this);
		std::cout << this->getName() << " signed " << ob.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << ob.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (!form.getSigne() || this->getGrade() > form.getGradeToExecute())
	{
		std::cout << "cannot execute Form because his grade is too low or form is not signed !" << std::endl;
		return ;
	}
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}