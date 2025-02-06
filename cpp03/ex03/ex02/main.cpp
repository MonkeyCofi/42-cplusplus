/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:50:01 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/08 16:45:27 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	{
		FragTrap Joe("Joe");
		ClapTrap Alice("Alice");
		Joe.printStats();
		Alice.printStats();
		Alice.attack(Joe.getName());
		Joe.takeDamage(Alice.getDamage());
		Joe.attack(Alice.getName());
		Alice.takeDamage(Joe.getDamage());
		Joe.highFivesGuys();
	}
	{
		FragTrap Mac("Mac");
		FragTrap Kirby("Kirby");
		Kirby.attack(Mac.getName());
		Mac.takeDamage(Kirby.getDamage());
		Mac.printStats();
		Kirby.printStats();
	}
}