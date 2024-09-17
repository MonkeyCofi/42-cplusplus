/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:11:29 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/08 16:28:32 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << BLUE << "Default constructor for FragTrap was called" << RESET << std::endl;;
};

FragTrap::~FragTrap()
{
	std::cout << RED <<  "Destructor for FragTrap " << Name << " was called" << RESET << std::endl;
};

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	this->Name = Name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << CYAN <<  "Parameterized constructor for FragTrap " << this->Name << " was called" << RESET << std::endl;
};

FragTrap::FragTrap(const FragTrap &obj)
{
	this->Name = obj.Name;
	this->hit_points = obj.hit_points;
	this->energy_points= obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << CYAN <<  "Copy constructor for FragTrap " << this->Name << " was called" << RESET << std::endl;
};

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
	this->Name = obj.Name;
	this->hit_points = obj.hit_points;
	this->energy_points= obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << CYAN <<  "Copy assignment operation for FragTrap " << this->Name << " was called" << RESET << std::endl;
	return (*this);
};

void	FragTrap::highFivesGuys(void)
{
	std::cout << CYAN << "FragTrap " << this->Name << " requests high fives from everyone!!" << RESET << std::endl;
};