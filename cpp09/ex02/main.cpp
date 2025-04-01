/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:47:11 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/31 23:25:17 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./PMergeMe [Sequence of numbers]\n";
		return (1);
	}
	std::cout << "There are " << ac - 1 << " elements\n";
	PMergeMe	containers;
	try
	{
		containers.fillContainers(const_cast<const char **>(av));
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << e.what() << "\n";
		return (1);
	}
	containers.sortVector();
	containers.sortList();
	containers.printVector();
	(void)av;
}