/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 18:30:19 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/01 16:22:35 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED << "Wrong number of parameters" << RESET << std::endl;
		return (1);
	}
	std::string arg = std::string(av[1]);
	Harl	filteredHarl;
	filteredHarl.complain(arg);
}
