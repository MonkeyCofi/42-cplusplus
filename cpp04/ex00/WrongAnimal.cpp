/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:14:43 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/13 16:05:18 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	this->type = "Wrong animal";
	std::cout << BLUE << "Default constructor for WrongAnimal was called" << RESET << std::endl;
};

WrongAnimal::~WrongAnimal()
{
	std::cout << RED << "Destructor for WrongAnimal was called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(std::string Type)
{
	this->type = Type;
	std::cout << CYAN << "Parameterized constructor for WrongAnimal was called" << RESET << std::endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	this->type = obj.type;
	std::cout << YELLOW << "Copy constructor for WrongAnimal was called" << RESET << std::endl;
};

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &obj)
{
	this->type = obj.type;
	std::cout << YELLOW << "Copy assignment operation was called" << RESET << std::endl;
	return (*this);
};

std::string	WrongAnimal::getType()
{
	return (this->type);
};

void	WrongAnimal::makeSound()
{
	std::cout << "Chinchilla noises" << std::endl;
};