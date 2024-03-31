/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:54:31 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/31 00:45:50 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

int main(int ac, char **av)
{
	if (ac != 2){
		std::cout << "Error: could not open file." << std::endl; return 0;
	}

	BitcoinExchange exchange;
	std::string input = av[1];

	exchange.storeData();
	exchange.parseInput(input);	
	
	return 0;
}
