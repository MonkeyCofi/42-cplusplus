/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 20:38:45 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/23 20:03:01 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

AMateria	*Character::m_last_dropped = NULL;

Character::Character(std::string const &name)
{
	this->m_name = name;
	this->m_inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
	this->m_full = 0;
	std::cout << BLUE << this->m_name << " was constructed" << RESET << std::endl;
};

Character::Character()
{
	this->m_name = "Chocobo";
	this->m_inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		m_inventory[i] = NULL;
	this->m_full = 0;
	std::cout << BLUE << "A Chocobo has arrived to assist you!" << RESET << std::endl;
}

Character::Character(const Character &obj)
{
	this->m_name = obj.m_name;
	if (m_inventory[0])
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->m_inventory[i])
				delete this->m_inventory[i];
		}
		delete [] this->m_inventory;
	}
	this->m_inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->m_inventory[i] = obj.m_inventory[i]->clone();
	this->m_full = obj.m_full;
}

Character	&Character::operator=(const Character &obj)
{
	this->m_name = obj.m_name;
	if (m_inventory[0])
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->m_inventory[i])
				delete this->m_inventory[i];
		}
		delete [] this->m_inventory;
	}
	this->m_inventory = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		this->m_inventory[i] = obj.m_inventory[i]->clone();
	this->m_full = obj.m_full;
	return (*this);
}

Character::~Character()
{
	if (m_inventory != NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			if (m_inventory[i])
				delete m_inventory[i];
		}
		delete [] m_inventory;
		std::cout << RED << "Deleted " << this->m_name << "'s inventory" << RESET << std::endl;
	}
	if (this->m_name == "Chocobo")
		std::cout << CYAN << "Friendly Chocobo has been relieved of its duties" << RESET << std::endl;
	else
		std::cout << RED << this->m_name << " has been killed" << RESET << std::endl;
};

const std::string	&Character::getName() const
{
	return (this->m_name);
};

void	Character::equip(AMateria *m)
{
	if (m_full)
	{
		std::cout << this->getName() << ": Inventory is full" << std::endl;
		return ;
	}
	int i = 0;
	int should_clone = 0;
	while (m_inventory[i] != NULL && i <= 3)
	{
		if (m_inventory[i] == m)
			should_clone = 1;
		i++;
	}
	if (i == 4)
	{
		std::cout << this->getName() << ": Inventory is full" << std::endl;
		m_full = 1;
		return ;
	}
	m_inventory[i] = should_clone ? m->clone() : m;
	if (m_inventory[i])
	{
		std::string t = m->getType();
		t.at(0) = (char)toupper(t.at(0));
		std::cout << YELLOW << this->getName() << " has equipped " << (t == "Ice" ? "an " : "a ") << t << " materia" << RESET << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (this->m_inventory[idx])
	{
		m_last_dropped = this->m_inventory[idx];
		this->m_inventory[idx] = NULL;
	}
	else
	{
		std::cout << this->getName() << ": No Materia equipped at slot " << idx + 1 << std::endl;
		return ;
	}
	std::cout << this->getName() << ": Unequipped materia at index: " << idx << std::endl;
};

void Character::use(int idx, ICharacter& target)
{
	if (this->m_inventory && this->m_inventory[idx])
	{
		this->m_inventory[idx]->use(target);
	}
	else
		std::cout << this->getName() << ": No materia equipped at slot " << idx + 1 << std::endl;
};

void	Character::deleteLastDropped()
{
	if (m_last_dropped)
	{
		delete(m_last_dropped);
		m_last_dropped = NULL;
	}
}