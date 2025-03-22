/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:24 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/22 19:15:53 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

PMergeMe::PMergeMe()
{
	
};

PMergeMe::~PMergeMe()
{

};

PMergeMe::PMergeMe(const PMergeMe& obj)
{
	(void)obj;
};

PMergeMe	&PMergeMe::operator=(const PMergeMe& obj)
{
	(void)obj;
	return (*this);
}

void	PMergeMe::fillContainers(const char** args)
{
	for (int i = 1; args[i]; i++)
	{
		if (std::string(args[i]).find_first_not_of("0123456789") != std::string::npos)
			throw (std::invalid_argument("Error: Only positive integers"));
		int	argInt = std::atoi(args[i]);
		if (argInt < 0)
			throw (std::invalid_argument("Error: Only positive integers"));
		this->vector.push_back(argInt);
		this->list.push_back(argInt);
	}
}

void	PMergeMe::sortVector()
{
	// for (std::vector<int>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
	// 	std::cout << "Vector: " << (*it) << "\n";
	recurseVector(2);
}

void	PMergeMe::sortList()
{
	// for (std::list<int>::iterator it = this->list.begin(); it != this->list.end(); it++)
	// {
	// 	std::cout << "list: " << (*it) << "\n";
	// }
}

void	PMergeMe::printVector()
{
	for (std::vector<int>::iterator it = this->vector.begin(); it != this->vector.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\n";
}

void	PMergeMe::printPairs(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (; begin != end; begin++)
	{
		std::cout << *begin << " ";
	}
	std::cout << "\n";
}

/*
	divide elements into pairs
	with each recursive call, the size of the pairings increases by size*2
	stop once the size of pairings is larger than number of elements
*/

unsigned int	PMergeMe::binarySearchVector(unsigned int start, unsigned int middle, unsigned int end, int valToInsert)
{
	if (end - start == 0)
		throw(std::invalid_argument("Element not found"));
	if (valToInsert < this->vector[middle])
		return (binarySearchVector(start, (middle + end) / 2, middle - 1, valToInsert));
	else if (valToInsert > this->vector[middle])
		return (binarySearchVector(middle + 1, (middle + end) / 2, end, valToInsert));
	return (middle);
}

int	PMergeMe::size()
{
	return (this->vector.size());
}

int	PMergeMe::calculateJacobsthal(int nthJacobsthal)
{
	if (nthJacobsthal == 1)
		return (0);
	if (nthJacobsthal == 2 || nthJacobsthal == 3)
		return (1);
	return (calculateJacobsthal(nthJacobsthal - 1) + (calculateJacobsthal(nthJacobsthal - 2) * 2));
}
 
void	PMergeMe::recurseVector(int pairSize)
{
	if (static_cast<unsigned int>(pairSize) > this->vector.size())
		return ;

	const std::vector<int>::iterator 	begin = this->vector.begin();
	const unsigned int					size = 	this->vector.size();
	std::vector< std::pair<int, int> >	pairElements;
	unsigned int						firstElem;
	unsigned int						secondElem;
	unsigned int						i;

	for (i = 0; i < size; i += pairSize)
	{
		firstElem = ((pairSize / 2) - 1) + i;
		secondElem = (pairSize - 1) + i;
		if (firstElem >= size || secondElem >= size)
			continue ;
		if (this->vector[firstElem] > this->vector[secondElem])
			std::swap_ranges(begin + i, begin + firstElem + 1, begin + firstElem + 1);
		pairElements.push_back(std::pair<int, int>(firstElem, secondElem));
	}
	if (firstElem < size && secondElem >= size)
		pairElements.push_back(std::pair<int, int>(firstElem, -1));
	// for (unsigned int i = 0; i < pairElements.size(); i++)
	// {
	// 	std::cout << "First element: " << vector[pairElements[i].first] << "[" << pairElements[i].first << "] " << " Second element: " << (pairElements[i].second == -1 ? -1 : vector[pairElements[i].second]) << "[" << pairElements[i].second << "] " << "\n";
	// 	// std::cout << "First element: " << pairElements[i].first << " element: " << pairElements[i].second << "\n";
	// }
	recurseVector(pairSize * 2);
	std::cout << "\n";
	for (i = 0; i < pairElements.size(); i++)
		std::cout << "b" << i + 1 << ": " << pairElements[i].first << " a" << i + 1 << ": " << pairElements[i].second << "\n";
	
	// create the main chain: b1, a1, a2....ax: every odd element is a and every even element is b
	// create the appendage chain b2, b3....bx
}