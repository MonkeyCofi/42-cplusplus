/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:21:25 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/23 15:35:34 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << BLUE << "An Ice Materia has been constructed " << RESET << std::endl;
};

Ice::~Ice()
{
	std::cout << RED << "Destructor for Ice Materia was called" << RESET << std::endl;
};

Ice::Ice(const Ice &obj) : AMateria("ice")
{
	this->m_type = obj.m_type;
};

Ice	&Ice::operator=(const Ice &obj)
{
	this->m_type = obj.m_type;
	return (*this);
};

const std::string	&Ice::getType() const
{
	return (this->m_type);
}

void	Ice::use(ICharacter &target)
{
	std::cout << GREEN << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
};

AMateria	*Ice::clone() const
{
	return (new Ice(*this));
}
