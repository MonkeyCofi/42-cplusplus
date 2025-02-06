/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:46:33 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/20 18:00:39 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << BLUE << "Default constructor for Brain was called" << RESET << std::endl;
};

Brain::~Brain()
{
	std::cout << RED << "Destructor for Brain was called" << RESET << std::endl;
};

Brain::Brain(const Brain &obj)
{
	(void)obj;
	std::cout << YELLOW << "Copy constructor for Brain was called" << RESET << std::endl;
};

Brain	&Brain::operator=(const Brain &obj)
{
	(void)obj;
	return (*this);
};

Brain	*Brain::returnBrainAddress()
{
	return (this);
}