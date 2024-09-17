/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:06:41 by pipolint          #+#    #+#             */
/*   Updated: 2024/08/31 12:08:49 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
	{
		Weapon	Spear = Weapon("Spear");
		HumanA	Bob = HumanA(Spear, "Bob");
		Bob.attack();
		Spear.setType("Sword");
		Bob.attack();
	}
	HumanB	Joe = HumanB("Joe");
	Weapon	Longsword = Weapon("Longsword");
	Joe.attack();
	Joe.pickWeapon(&Longsword);
	Joe.attack();
}