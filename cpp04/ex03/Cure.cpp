/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:58:31 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/23 15:35:02 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << BLUE <<  "A Cure Materia has been constructed" << RESET << std::endl;
};

Cure::~Cure()
{
	std::cout << RED << "Destructor for Cure was called" << RESET << std::endl;
};

Cure::Cure(const Cure &obj) : AMateria("ice")
{
	this->m_type = obj.m_type;
};

Cure	&Cure::operator=(const Cure &obj)
{
	this->m_type = obj.m_type;
	return (*this);
};

const std::string	&Cure::getType() const
{
	return (this->m_type);
};

AMateria	*Cure::clone() const
{
	return (new Cure(*this));
};

void	Cure::use(ICharacter &target)
{
	std::cout << GREEN << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
};
