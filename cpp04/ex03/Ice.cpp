/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:21:25 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/21 22:23:52 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	;
};

Ice::~Ice()
{
	;
};

Ice::Ice(const Ice &obj)
{
	;
};

Ice	&Ice::operator=(const Ice &obj)
{
	return (*this);
};

std::string	

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
};
