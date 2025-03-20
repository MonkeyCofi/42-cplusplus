/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:24 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/20 20:16:59 by ppolinta         ###   ########.fr       */
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

/*
	divide elements into pairs
	with each recursive call, the size of the pairings increases by size*2
	stop once the size of pairings is larger than number of elements
*/

int call_level = 0;
void	PMergeMe::recurseVector(int pairSize)
{
	call_level++;
	if (static_cast<unsigned int>(pairSize) > this->vector.size())
		return ;
	const std::vector<int>::iterator begin = this->vector.begin();
	unsigned int oddElemOut;
	for (unsigned int i = 0, size = this->vector.size(); i < size; i += pairSize)
	{
		unsigned int firstElem = ((pairSize / 2) - 1) + i;
		unsigned int secondElem = (pairSize - 1) + i;
		if (firstElem >= size || secondElem >= size)
		continue ;
		if (this->vector[firstElem] > this->vector[secondElem])	// swap ranges
		std::swap_ranges(begin + i, begin + firstElem + 1, begin + firstElem + 1);	
	}
	recurseVector(pairSize * 2);
}