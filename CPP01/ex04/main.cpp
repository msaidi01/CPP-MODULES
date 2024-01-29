/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 06:33:15 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/28 15:13:15 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdio>
#include <iostream>
#include <ostream>
#include <string>
#include <fstream>

bool replaceWord(std::ifstream &readFile, std::string word1, std::string word2, std::string fname)
{
    if (word1.empty())
    {
        std::cerr << "Invalid word to replace" << std::endl;
        return false;
    }
    std::string str;
    std::getline(readFile, str, '\0');
    if (str.empty())
    {
        std::cerr << "Empty read file"<< std::endl;
        return false;
    }
    readFile.close();
    std::ofstream writeFile; writeFile.open(fname + ".replace");
    if (!writeFile.is_open())
    {
        std::cerr << "Couldn't open file : " << fname + ".replace" << std::endl;
        return false;
    }
    int i = 0;
    std::size_t pos = 0;
    while (1)
    {
        pos = str.find(word1);
        i = 0;
        if (pos != std::string::npos)
        {
            writeFile << str.substr(i, pos);
            writeFile << word2;
            i = word1.length() + pos;
            if (i >= (int)str.length())
                i = (int)str.length();
            str = str.substr(i, str.length());
        }
        else
        {
            writeFile << str.substr(0, (int)str.length());
            break ;
        }
    }
    writeFile.close();
    return true;
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Invalid arguments" << std::endl;
        return 0;
    }
    std::string fname = av[1];
    std::string firstWord = av[2];
    std::string secondWord = av[3];
    std::ifstream readFile;
    readFile.open(fname, std::ifstream::in);
    if (!readFile.is_open())
    {
        std::cerr << "Couldn't open the file : "<< fname << std::endl;
        return 0;
    }
    if (!replaceWord(readFile, firstWord, secondWord, fname))
        return 0;
}