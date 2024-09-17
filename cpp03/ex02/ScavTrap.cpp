/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 17:09:37 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/07 19:45:52 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->Name = "ScavTrap";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << CYAN << "Default constructor for ScavTrap was called" << RESET << std::endl;
};

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name)
{
	this->Name = Name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << CYAN << "Parameterized constructor for ScavTrap " << this->Name << " was called" << RESET << std::endl;
};

ScavTrap::~ScavTrap()
{
	std::cout << RED << "Destructor for ScavTrap " << this->Name << " was called" << RESET << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &ref) : ClapTrap(ref)
{
	this->Name = ref.Name;
	this->hit_points = ref.hit_points;
	this->energy_points = ref.energy_points;
	this->attack_damage = ref.attack_damage;
	std::cout << "Copy constructor for ScavTrap " << this->Name << " was called" << RESET << std::endl;
};

ScavTrap &ScavTrap::operator=(ScavTrap const &ref)
{
	this->Name = ref.Name;
	this->hit_points = ref.hit_points;
	this->energy_points = ref.energy_points;
	this->attack_damage = ref.attack_damage;
	std::cout << CYAN << "Copy assignment operator for ScavTrap " << this->Name << " was called" << RESET << std::endl;
	return (*this);
};

void	ScavTrap::guardGate()
{
	std::cout << YELLOW << "ScavTrap " << this->Name << " is now in Gate Keeper mode" << RESET << std::endl;
};

void	ScavTrap::attack(const std::string &target)
{
	std::cout << "ScavTrap " << Name << " attacked " << target << " causing " << attack_damage << " points of damage" << std::endl;
}