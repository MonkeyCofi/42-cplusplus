/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:00:28 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/11 10:41:45 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->Name = "DiamondTrap";
	ClapTrap::setName(ClapTrap::getName() + "_clap_name");
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << BLUE << "Default constructor for DiamondTrap was called" << RESET << std::endl;
};

DiamondTrap::~DiamondTrap()
{
	std::cout << RED << "Destructor for DiamondTrap " << this->Name << " was called" << RESET << std::endl;
};

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name), FragTrap(Name), ScavTrap(Name)
{
	this->Name = Name;
	ClapTrap::setName(ClapTrap::getName() + "_clap_name");
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << CYAN << "Parameterized constructor for DiamondTrap " << this->Name << " was called" << RESET << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
	this->Name = obj.Name;
	ClapTrap::setName(ClapTrap::getName() + "_clap_name");
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << CYAN << "Copy constructor for DiamondTrap " << this->Name << " was called" << RESET << std::endl;
};

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &obj)
{
	this->Name = obj.Name;
	ClapTrap::setName(ClapTrap::getName() + "_clap_trap");
	this->hit_points = obj.hit_points;
	this->energy_points = obj.energy_points;
	this->attack_damage = obj.attack_damage;
	std::cout << CYAN << "Copy assignment operation for DiamondTrap " << this->Name << " was called" << RESET << std::endl;
	return *this;
};

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
};

void	DiamondTrap::whoAmI(void)
{
	std::cout << "My ClapTrap name is " << ClapTrap::getName() << std::endl;
};
