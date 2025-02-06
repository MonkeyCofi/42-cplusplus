/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:24:37 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/20 18:48:10 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	brain = new Brain();
	std::cout << BLUE << "Default constructor for Dog was called" << RESET << std::endl;
};

Dog::Dog(std::string type)
{
	this->type = type;
	brain = new Brain();
	std::cout << CYAN << "Parameterized constructor for Dog was called" << RESET << std::endl;
};

Dog::~Dog()
{
	delete brain;
	std::cout << RED << "Destructor for Dog was called" << RESET << std::endl;
};

Dog::Dog(const Dog &obj) : Animal(obj)
{
	this->type = obj.type;
	this->brain = new Brain();
	std::cout << YELLOW << "Copy constructor for Dog was called" << RESET << std::endl;
};

Dog	&Dog::operator=(const Dog &obj)
{
	this->brain = new Brain();
	this->type = obj.type;
	std::cout << YELLOW << "Copy assignment operation for Dog was called" << std::endl;
	return *this;
};

void	Dog::makeSound()
{
	std::cout << "Dog: bark bark bark" << std::endl;
};

Brain	*Dog::brainAddress()
{
	return (this->brain->returnBrainAddress());
}