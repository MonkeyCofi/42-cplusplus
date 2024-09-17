/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 12:13:59 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/07 15:07:26 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon &weapon_type, std::string name) : weap(weapon_type)
{
	this->name = name;
};

HumanA::~HumanA()
{
	std::cout << this->name << " has died" << std::endl;
};

void	HumanA::attack()
{
	std::cout << this->name << " attacks " << "with their " << weap.getType() << std::endl;
}