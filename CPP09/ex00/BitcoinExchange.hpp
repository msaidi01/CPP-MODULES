/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 03:53:05 by msaidi            #+#    #+#             */
/*   Updated: 2024/03/31 00:42:08 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
class BitcoinExchange 
{
    private:
    std::map<std::string, double> data;
    std::string date;
    double exchange;
    double val;

    public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange &ob);
    BitcoinExchange& operator=(BitcoinExchange &ob);
    ~BitcoinExchange();

    void setDate(std::string date);
    void setExchange(std::map<std::string, double> &data);
    void setValue(double value);
    void storeData();
    void parseInput(std::string input);
    void printExchangeRate();

};






#endif