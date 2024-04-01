/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:17:54 by msaidi            #+#    #+#             */
/*   Updated: 2024/04/01 04:38:44 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PmergeMe.hpp"
#include <cstdlib>
#include <utility>
#include <vector>

bool CheckArg(char **av)
{
    for (int i = 1 ; av[i] ; i++ )
	{
		long long nbr(strtol(av[i], NULL, 10));
		if (nbr < 0 || INT_MAX < nbr)
			return false;
		for (int j = 0 ; av[i][j] ; j++)
			if (!isdigit(av[i][j]))
				return false;
	}
	return true;
}



int main(int ac, char **av)
{
    if (ac < 2 || !CheckArg(av))
    {
        std::cout << "Invalid input." << std::endl;
        return 0;
    }
	PmergeMe a;
	std::vector<int> args;
	for (int i = 1 ; av[i] ; i++){
		args.push_back(atoi(av[i]));
	}
	a.createPairs(args);
	
}
