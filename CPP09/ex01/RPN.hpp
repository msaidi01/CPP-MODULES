/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 00:53:02 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/31 06:39:45 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <string>

class RPN
{
	private:
		std::string str;
		std::stack<int> nums;
	public:
		RPN();
		RPN(std::string input);
		RPN(const RPN &rpn);
		RPN &operator=(const RPN &rpn);
		~RPN();
		void setStr(std::string input);
		std::string getStr();
		void parseCalculate();
};


#endif