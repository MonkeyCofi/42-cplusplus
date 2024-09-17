/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:36:56 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/01 16:27:49 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << GREEN << "I really love extra olives and pepperoni on my XL sized pizza" << RESET << std::endl;
};

void	Harl::info(void)
{
	std::cout << BLUE << "Wait what? It costs extra pesos to add a tad bit of olives and pepperoni to my pizza?" << RESET << std::endl;
};

void	Harl::warning(void)
{
	std::cout << YELLOW << "Listen brother, I just want extra olives and pepperoni on my XL sized pizza for free. I think I am entitled to such a request" << RESET << std::endl;	
};

void	Harl::error(void)
{
	std::cout << RED << "HOY! What is this unacceptable service? 10 years I have been coming here and you're treating me like just came here for the first time in my life!! I will speak to your boss THIS INSTANT!!" << RESET << std::endl;
};

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	for (; i < 4; i++)
		if (level == levels[i])
			break ;
	switch(i)
	{
		case 0:
			Harl::debug();
		case 1:
			Harl::info();
		case 2:
			Harl::warning();
		case 3:
			Harl::error();
			break ;
		default:
			std::cout << CYAN << "[ Harl is busy bothering someone else's peace ]" << RESET << std::endl;
	}
	
};