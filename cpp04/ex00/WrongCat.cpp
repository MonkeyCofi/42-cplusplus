/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:16:17 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/13 13:27:11 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "Chichilla";
	std::cout << BLUE << "Default constructor for WrongCat was called" << RESET << std::endl;
};

WrongCat::WrongCat(std::string Type)
{
	this->type = Type;
	std::cout << CYAN << "Parameterized constructor for WrongCat was called" << RESET << std::endl;
};

WrongCat::WrongCat(const WrongCat &obj)
{
	this->type = obj.type;
	std::cout << YELLOW << "Copy constructor constructor for WrongCat was called" << RESET << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &obj)
{
	this->type = obj.type;
	std::cout << YELLOW << "Copy assignment operation for WrongCat was called" << RESET << std::endl;
	return (*this);
}

void	WrongCat::makeSound()
{
	std::cout << "Weird looking cat: Rehehehehe" << std::endl;
}

