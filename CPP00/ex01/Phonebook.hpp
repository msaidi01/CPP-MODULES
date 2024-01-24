/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaidi <msaidi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:42:52 by msaidi            #+#    #+#             */
/*   Updated: 2024/01/22 03:59:03 by msaidi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP
#include "Contact.hpp"
class Phonebook
{
	private:
	Contact	BookContact[8];
	int Size;
	int	Index;
	public:
	void SetSize();
	int GetSize();
	void SetIndex();
	void IndexInc();
	void SizeInc();
	int GetIndex();
	void PbInit();
	void ADD();
	void SEARCH();
};


#endif