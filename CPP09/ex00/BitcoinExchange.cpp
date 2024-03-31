/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:53:01 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/31 00:44:04 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange &ob)
{
	if (this != &ob){
		*this = ob;
	}
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange &ob)
{
	if (this != &ob){
		data = ob.data;
		date = ob.date;
		exchange = ob.exchange;
		val = ob.val;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

void BitcoinExchange::setDate(std::string date)
{
	this->date = date;
}

void BitcoinExchange::setExchange(std::map<std::string, double> &data)
{
	if (data.find(date) != data.end()){
		exchange = data[date];
	}
	else{
		std::map<std::string, double> ::iterator it = data.lower_bound(date);
		if ((*it).first != date)
		{
			if (it != data.begin()){
				it--;
				exchange = (*it).second;
			}
			else{
				exchange = (*it).second;
			}
		}
	}
	
}

void BitcoinExchange::setValue(double value)
{
	this->val = value;
}

void BitcoinExchange::storeData()
{
	
	std::ifstream DataFile("data.csv");
	if (!DataFile.is_open()){
		throw std::runtime_error("Error opening file : data.csv");
	}
	std::string line;
	int pos = 0;
	while (std::getline(DataFile, line))
	{
		pos = line.find(',');
		data[line.substr(0, pos)] = atof(line.substr(pos + 1, line.size()).c_str());
	}
	DataFile.close();
}

void BitcoinExchange::printExchangeRate()
{
	std::cout << date << " => " << val << " = " << val * exchange << std::endl;
}

// The rules for determining leap years are based on the Gregorian calendar, which is the calendar 
// system commonly used today. Here's an explanation of the logic behind the leap year formula:

// Divisible by 4:

// Every year divisible by 4 is a leap year. This is the basic rule.
// Not Divisible by 100 (Exception):

// However, there is an exception to the rule above. Years that are divisible by 100 are not leap years, 
// unless they are also divisible by 400.
// This rule was introduced to correct an overcompensation in the leap year system. Without this exception, 
// years divisible by 100 but not divisible by 400 (like 1900) would be considered leap years, which is incorrect.
// Divisible by 400 (Exception to the Exception):

// Years divisible by 400 are always leap years. This is to adjust for the overcorrection introduced by the second rule.
// So, even though most years divisible by 100 are not leap years, those divisible by 400 are still leap years.

bool checkYear(std::string date)
{
	if (date.size() == 0 || date.size() != 10){
		return false;
	}
	if (date[4] != '-' || date[7] != '-'){
		return false;
	}
	
	int _year = std::atoi(date.substr(0, 4).c_str());
	int _month = std::atoi(date.substr(5, 2).c_str());
	int _day = std::atoi(date.substr(8, 2).c_str());
	
	 if (_year < 2009|| _year > 2023 || _month < 1 || _month > 12 || _day < 1 || _day > 31)
        return false;
	if (_month == 2 && _day > 28 && !(((_year % 4 == 0) && (_year % 100 != 0)) || _year % 400 == 0))
		return false;

	int max_day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (_day > max_day[_month - 1])
		return false;
	return true;
}

bool checkVal(std::string value)
{
	std::istringstream iss(value);
	double v;
	
	iss >> v;
	if (iss.eof()){
		return true;
	}
	return false;
}

void BitcoinExchange::parseInput(std::string input)
{
	std::ifstream InputFile(input);
	try
	{
		if (!InputFile.is_open()){
			throw std::runtime_error("Error: could not open file.");
		}
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
		return;
	}
	std::string line;
	std::getline(InputFile, line);
	size_t found = line.find("date | value");
	if (found == std::string::npos){
		std::cout << "Invalid input file : must start with (date | value)" << std::endl;
		return;
	}
	while (std::getline(InputFile, line))
	{
		found = line.find(" | ");
		try 
		{
			if (found == std::string::npos){
				throw std::runtime_error("Invalid input");
			}
			std::string date = line.substr(0, found);
			if (!checkYear(date)){
				throw std::runtime_error("Invalid date");
			}
			setDate(date);
			std::string value = line.substr(found + 3, line.size());
			if (!checkVal(value)){
				throw std::runtime_error("Invalid price");
			}
			double v = atof(value.c_str());
			setValue(v);
			setExchange(data);
			printExchangeRate();
		}
		catch (std::exception &e){
			std::cout << "Error: " << e.what() << std::endl;
		}
	}
	InputFile.close();
}
