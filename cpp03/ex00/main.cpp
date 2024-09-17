/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:50:01 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/07 17:25:37 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	std::cout << std::setw(30) << std::setfill('-')  << "-" << std::endl;
	ClapTrap Bob("Bob");
	ClapTrap Patricius("Patricius");
	Bob.attack(Patricius.getName());
	Patricius.takeDamage(Bob.getDamage());

	ClapTrap Bob_clone;
	Bob_clone = Bob;
	Bob_clone.setName("Bob V2");
	Bob_clone.attack(Bob.getName());
	Bob.takeDamage(Bob_clone.getDamage());
	Bob.printStats();
	std::cout << std::endl;
	std::cout << std::setw(30) << std::setfill('-')  << "-" << std::endl;
}