/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 13:50:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/02/25 15:26:37 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>
#include <iostream>

int main()
{
    Bureaucrat b("amine", 1);
    Form f;
    
    std::cout << f << std::endl;
    std::cout << "-------------------------" << std::endl;
    try
    {
        Form d("certificat", 150, 15);
        std::cout << d << std::endl;
        std::cout << "-------------------------" << std::endl;
        f.beSigned(b);

        b.signForm(d);
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
