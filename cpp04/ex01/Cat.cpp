/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:58:57 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/14 13:05:09 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	brain = new Brain();
	std::cout << BLUE << "Default constructor for Cat was called" << RESET << std::endl;
};

Cat::~Cat()
{
	delete brain;
	std::cout << RED << "Destructor for Cat was called" << RESET << std::endl;
};

Cat::Cat(std::string type)
{
	this->type = type;
	std::cout << YELLOW << "Parameterized constructor for Cat was called" << RESET << std::endl;
};

Cat::Cat(const Cat &obj) : Animal(obj)
{
	this->type = obj.type;
	std::cout << YELLOW << "Copy constructor for Cat was called" << RESET << std::endl;
};

Cat	&Cat::operator=(const Cat &obj)
{
	this->type = obj.type;
	std::cout << YELLOW << "Copy assigment for Cat was called" << RESET << std::endl;
	return *this;
};

void	Cat::makeSound()
{
	std::cout << "Cat: Meow" << std::endl;
};