/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 00:00:54 by pipolint          #+#    #+#             */
/*   Updated: 2024/08/27 10:36:17 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::add_contact(unsigned short current)
{
	contacts[current].setContact();
};

void	PhoneBook::is_full()
{
	full = true;
};

void	PhoneBook::print_top_row() const
{
	std::cout << std::setw(10) << "Index" << std::right;
	std::cout << "|";
	std::cout << std::setw(10) << "First" << std::right;
	std::cout << "|";
	std::cout << std::setw(10) << "Last" << std::right;
	std::cout << "|";
	std::cout << std::setw(10) << "Nickname" << std::right;
	std::cout << "|";
	std::cout << std::endl;
};

void	PhoneBook::search_contact(unsigned short index)
{
	std::string	input;
	int			num;

	if (check_full())
		index = 8;
	if (contacts[0].isEmpty())
	{
		std::cout << "\x1b[31m" << "The table is currently empty" << "\x1b[0m" << std::endl;
		return ;
	}
	print_top_row();
	for (unsigned short i = 0; i < index; i++)
	{
		std::cout << std::setw(10) << i << std::right;
		std::cout << "|";
		std::cout << std::setw(10) << (contacts[i].getFirst().length() < 10 ? contacts[i].getFirst() : contacts[i].getFirst().substr(0, 9).append(".")) << std::right;
		std::cout << "|";
		std::cout << std::setw(10) << (contacts[i].getLast().length() < 10 ? contacts[i].getLast() : contacts[i].getLast().substr(0, 9).append(".")) << std::right;
		std::cout << "|";
		std::cout << std::setw(10) << (contacts[i].getNick().length() < 10 ? contacts[i].getNick() : contacts[i].getNick().substr(0, 9).append(".")) << std::right;
		std::cout << "|";
		std::cout << std::endl;
	}
	std::cout << "\x1b[33m" <<  "Enter index to search: " << "\x1b[0m";
	std::getline(std::cin, input);
	if (std::cin.eof())
		return ;
	num = atoi(input.c_str());
	if (contacts[num].isEmpty())
	{
		std::cout << "\x1b[31m" << "Contact at index " << num << " is empty" << "\x1b[0m" << std::endl;
		return ;
	}
	if (num < 0 || num > 8)
	{
		std::cout << "\x1b[31m" <<  "Number is out of range"  << "\x1b[0m" << std::endl;
		return ;
	}
	std::cout << "------------------------------" << std::endl;
	std::cout << "First name: " << contacts[num].getFirst() << std::endl;
	std::cout << "Last name: " << contacts[num].getLast() << std::endl;
	std::cout << "Nickname: " << contacts[num].getNick() << std::endl;
	std::cout << "Phone number: " << contacts[num].getNumber() << std::endl;
	std::cout << "Deepest, darkest secret: " << contacts[num].getSecret() << std::endl;
}

bool	PhoneBook::check_full() const
{
	return this->full;
};