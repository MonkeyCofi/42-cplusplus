/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:47:45 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/13 13:10:51 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	type = "Animal";
	std::cout << BLUE << "Default constructor for Animal was called" << RESET << std::endl;
};

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << CYAN << "Parameterized constructor for Animal was called" << RESET << std::endl;
};

Animal::Animal(const Animal &obj)
{
	this->type = obj.type;
	std::cout << YELLOW << "Copy constructor for Animal was called" << RESET << std::endl;
}

Animal	&Animal::operator=(const Animal &obj)
{
	this->type = obj.type;
	std::cout << YELLOW << "Copy assignment for Animal was called" << RESET << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << RED << "Destructor for Animal was called" << RESET << std::endl;
};

void	Animal::makeSound()
{
	std::cout << "Generic animal noises" << std::endl;
}

std::string	Animal::getType()
{
	return (this->type);
};