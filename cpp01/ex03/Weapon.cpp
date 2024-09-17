/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 21:08:56 by pipolint          #+#    #+#             */
/*   Updated: 2024/08/31 12:18:04 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
	this->type = weapon_type;
};

Weapon::~Weapon()
{
	;
};

const std::string	Weapon::getType()
{
	return (this->type);
};

void	Weapon::setType(std::string type)
{
	this->type = type;
}
