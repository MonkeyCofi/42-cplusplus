/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 20:40:14 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/24 11:54:09 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	std::string 	input;
	PhoneBook		phonebook;
	unsigned short	current;

	current = 0;
	while (1)
	{
		std::cout << "------------------------------" << std::endl;
		std::cout << "Possible operations: " << "\x1b[35m" << "ADD SEARCH EXIT" << "\x1b[0m" << std::endl;
		std::cout << "\x1b[32m" << "Enter Operation: " << "\x1b[0m";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return (1);
		if (input == "ADD")
		{
			if (phonebook.add_contact(current++) == 0)
				return (1);
		}
		else if (input == "SEARCH")
		{
			 if (phonebook.search_contact(current) == 0)
			 	return (1);
		}
		else if (input == "EXIT")
			return (0);
		if (current == 8)
		{
			current = 0;
			phonebook.is_full();
		}
	}
}