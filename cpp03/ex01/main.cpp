/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:50:01 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/06 17:52:54 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Joe("Joe");
	ClapTrap Alice("Alice");
	Alice.takeDamage(Joe.getDamage());
	std::cout << "Alice has " << Alice.getEnergyPoints() << " energy points" << std::endl;
	Alice.beRepaired(Joe.getDamage());
	std::cout << "Alice has " << Alice.getEnergyPoints() << " energy points" << std::endl;
}