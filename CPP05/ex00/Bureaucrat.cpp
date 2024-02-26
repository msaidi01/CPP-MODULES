/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:51:05 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/23 17:36:29 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
	this->grade--;
	if (this->grade < 1)
		throw GradeTooHighException();
}
void Bureaucrat::decGrade()
{
	this->grade++;
	if (this->grade > 150)
		throw GradeTooLowException();
	
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