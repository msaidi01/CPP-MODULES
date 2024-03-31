/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:52:57 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/31 05:38:26 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Program takes 1 parameter." << std::endl;
		return 0;
	}
	RPN rpn(av[1]);
	rpn.parseCalculate();

	return 0;
}