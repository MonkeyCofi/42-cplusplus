/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:33:48 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/24 11:50:39 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	m_empty = true;
}

void	Contact::setNonEmpty()
{
	this->m_empty = false;
};

bool	Contact::isEmpty()
{
	return (this->m_empty);
}

int		Contact::setContact()
{
	if (setNames() == 0)
		return (0);
	if (setNumber() == 0)
		return (0);
	if (setSecret() == 0)
		return (0);
	setNonEmpty();
	return (1);
};

void	Contact::print_query(std::string str)
{
	std::cout << "\x1b[33m" << str << "\x1b[0m";
};

int	Contact::setNames()
{
	std::string	first;
	std::string	last;
	std::string	nick;

	while (!valid_input(first, 2))
	{
		print_query("Enter first name: ");
		std::getline(std::cin, first);
		if (std::cin.eof() || std::cin.fail())
			return (0);
	}
	m_firstName = first;
	while (!valid_input(last, 2))
	{
		print_query("Enter last name: ");
		std::getline(std::cin, last);
		if (std::cin.eof() || std::cin.fail())
			return (0);
	}
	m_lastName = last;
	while (!valid_input(nick, 0))
	{
		print_query("Enter nickname: ");
		std::getline(std::cin, nick);
		if (std::cin.eof() || std::cin.fail())
			return (0);
	}
	m_nickName = nick;
	return (1);
};

int	Contact::setNumber()
{
	std::string	number;
	while (!valid_input(number, 1))
	{
		print_query("Enter phone number: ");
		std::getline(std::cin, number);
		if (std::cin.eof() || std::cin.fail())
			return (0);
	}
	m_phoneNumber = number;
	return (1);
};

int	Contact::setSecret()
{
	std::string	secret;

	while (!valid_input(secret, 0))
	{
		std::cout << "\x1b[33m" << "Enter " << this->m_firstName << "'s deepest, darkest secret: " << "\x1b[0m";
		std::getline(std::cin, secret);
		if (std::cin.eof() || std::cin.fail())
			return (0);
	}
	m_darkestSecret = secret;
	return (1);
}

std::string	Contact::getFirst() const
{
	return this->m_firstName;
};

std::string Contact::getLast() const
{
	return this->m_lastName;
};

std::string Contact::getNick() const
{
	return this->m_nickName;
};

std::string	Contact::getNumber() const
{
	return this->m_phoneNumber;
};

std::string	Contact::getSecret() const
{
	return this->m_darkestSecret;
};