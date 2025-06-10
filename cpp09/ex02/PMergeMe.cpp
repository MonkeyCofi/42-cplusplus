/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:24 by pipolint          #+#    #+#             */
/*   Updated: 2025/06/10 22:26:14 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int comparisonCount = 0;

PMergeMe::PMergeMe()
{
	this->lastElem = -1;
	this->oddSize = false;	
};

PMergeMe::~PMergeMe()
{

};

PMergeMe::PMergeMe(const PMergeMe& obj)
{
	*this = obj;
};

PMergeMe	&PMergeMe::operator=(const PMergeMe& obj)
{
	this->vector = obj.vector;
	this->list = obj.list;
	this->lastElem = obj.lastElem;
	this->oddSize = obj.oddSize;
	return (*this);
}

unsigned int	comp(int val, int iteratorPoint)
{
	comparisonCount++;
	return (val < iteratorPoint);
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
		this->set.insert(argInt);
	}
	if (set.size() < vector.size())
		throw (std::invalid_argument("Error: No duplicate values"));
	this->oddSize = vector.size() % 2;
	if (this->oddSize)
	{
		this->lastElem = vector.back();
		this->vector.pop_back();
	}
}

/*
	form pairs and sort using one comparison per pair
	once the pairs are sorted; name all elements a[i] and b[i] where a[i] - a[n / 2] > b[i] - b[n / 2]
	repeat this process for all a[i] - a[n / 2] elements

*/
void	PMergeMe::sortVector()
{
	if (this->vector.size() <= 1)
		return ;
	std::vector<int>	winners;
	std::vector<int>	losers;
	std::vector<int>	sortedPairs;

	for (std::vector<int>::iterator it = vector.begin(); it != vector.end();)
	{
		if (comp((*it), *(it + 1)))
		{
			losers.push_back(*it);
			winners.push_back(*(it + 1));
			sortedPairs.push_back(*it);
			sortedPairs.push_back(*(it + 1));
		}
		else
		{
			winners.push_back(*it);
			losers.push_back(*(it + 1));
			sortedPairs.push_back(*(it + 1));
			sortedPairs.push_back(*it);
		}
		it += 2;
	}
	for (std::vector<int>::iterator it = sortedPairs.begin(); it != sortedPairs.end(); it++)
		std::cout << "Vec: " << (*it) << "\n";
	std::cout << "\n";
	this->vector = winners;
	sortVector();
}
