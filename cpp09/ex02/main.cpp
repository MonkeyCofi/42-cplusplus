/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:47:11 by pipolint          #+#    #+#             */
/*   Updated: 2025/06/15 18:53:29 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./PmergeMe [Sequence of numbers]\n";
		return (1);
	}
	PmergeMe	containers;
	try
	{
		containers.fillContainers((av));
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << e.what() << "\n";
		return (1);
	}
	std::cout << "Unsorted elements: ";
	containers.printInternalVector();
	containers.sortVector();
	containers.sortList();
	std::cout << "  Sorted elements: ";
	containers.printInternalVector();
	std::cout << "list: ";
	containers.printInternalList();
}
