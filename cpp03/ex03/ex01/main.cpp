/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:50:01 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/07 19:52:06 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	{
		ScavTrap Joe("Joe");
		ClapTrap Alice("Alice");
		Alice.attack(Joe.getName());
		Joe.takeDamage(Alice.getDamage());
		Joe.attack(Alice.getName());
		Alice.takeDamage(Joe.getDamage());
		Joe.guardGate();
	}
	{
		std::cout << std::setw(30) << std::setfill('-')  << "-" << std::endl;
		std::cout << std::setw(30) << std::setfill('-')  << "-" << std::endl;
		ScavTrap	Alan("Alan");
		ScavTrap	Lily("Lily");
		Lily.printStats();
		Alan.attack(Lily.getName());
		Lily.takeDamage(Alan.getDamage());
		Lily.printStats();
	}
	{
		std::cout << std::setw(30) << std::setfill('-')  << "-" << std::endl;
		std::cout << std::setw(30) << std::setfill('-')  << "-" << std::endl;
		ScavTrap	Zero("Zero");
		ScavTrap	Zero_clone;
		Zero_clone = Zero;
		Zero_clone.setName("Zero's clone");
		Zero_clone.attack(Zero.getName());
		Zero.takeDamage(300);
	}
}