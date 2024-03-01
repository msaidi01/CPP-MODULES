/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:00:46 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/01 09:15:34 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
class AForm;

class RobotomyRequestForm : public AForm
{
    private:
    std::string _target;
    public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &ob);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &ob);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};

#endif