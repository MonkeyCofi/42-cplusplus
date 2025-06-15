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
	std::cout << "Before:  ";
	containers.printInternalVector();
	containers.mergeInsertionVector();
	containers.mergeInsertionList();
	std::cout << "After:   ";
	containers.printInternalVector();
	std::cout << "Time for vector to sort: " << containers.getVectorTime() << "ms\n";
	std::cout << "Time for list to sort  : " << containers.getListTime() << "ms\n";
}
