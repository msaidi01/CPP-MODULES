/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:50:59 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/24 16:47:17 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <ostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
	private:
	std::string const name;
	int grade;
	public:
	class GradeTooLowException : public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		const char* what() const throw();
	};
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat &ob);
	Bureaucrat& operator=(Bureaucrat &ob); 
	~Bureaucrat();
	
	std::string getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();
	void signForm(Form &ob);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& a);

#endif
