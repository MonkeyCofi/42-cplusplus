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

int comparisonCount = 0;

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

void	PMergeMe::printVector(std::vector<int>& _vector)
{
	for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
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
	{
		comparisonCount++;
		return (binarySearchVector(start, (middle + end) / 2, middle - 1, valToInsert));
	}
	else if (valToInsert > this->vector[middle])
	{
		comparisonCount++;
		return (binarySearchVector(middle + 1, (middle + end) / 2, end, valToInsert));
	}
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

void	PMergeMe::jacobsthalInsert(int jacobsthalNumber, unsigned int& appendageCount, std::vector<int>& mainChain, std::vector< std::pair<int,int> >& pairElements)
{
	while (appendageCount > 0)
	{
		// insert this->vector[pairElement[appendageCount - 1].first] into the main chain
		// use binarySearch to figure out where to append in the main chain
		// call: binarySearch(0, pairElement[appendageCount - 1] / 2, pairElement[appendageCount - 1], this->vector[pairElement[appendageCount - 1].first]);
		// decrement appendageCount
		unsigned int	insertIndex = binarySearchVector(0, pairElements[appendageCount - 1].second / 2, \
				pairElements[appendageCount - 1].second, mainChain[pairElements[appendageCount - 1].first]);
		appendageCount--;
		(void)insertIndex;
	}
	(void)mainChain;
}

void	PMergeMe::binaryInsert(std::vector<int>& mainChain, std::vector< std::pair<int,int> >& pairElements)
{
	(void)mainChain;
	(void)pairElements;
	return ;
}

void	PMergeMe::recurseVector(int pairSize)
{
	if (static_cast<unsigned int>(pairSize) > this->vector.size())
		return ;

	const std::vector<int>::iterator 	begin = this->vector.begin();
	const unsigned int					size = 	this->vector.size();
	std::vector< std::pair<int, int> >	pairElements;
	std::vector<int>					mainChain;
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
		{
			comparisonCount++;
			std::swap_ranges(begin + i, begin + firstElem + 1, begin + firstElem + 1);
		}
		pairElements.push_back(std::pair<int, int>(firstElem, secondElem));
	}
	if (firstElem < size && secondElem >= size)
		pairElements.push_back(std::pair<int, int>(firstElem, -1));

	recurseVector(pairSize * 2);

	mainChain.insert(mainChain.begin(), this->vector.begin(), this->vector.begin() + pairSize);
	// insert elements into the main chain
	for (std::vector< std::pair<int, int> >::iterator it = pairElements.begin() + 1; it != pairElements.end(); it++)
	{
		if ((*it).second == -1)
			continue ;
		mainChain.insert(mainChain.end(), begin + (*it).first + 1, begin + (*it).second + 1);
	}
	std::cout << comparisonCount << " comparisons so far\n";
	int	jacobsthal = 4;
	unsigned int	appendageCount = calculateJacobsthal(jacobsthal) - calculateJacobsthal(jacobsthal - 1);
	while (appendageCount < pairElements.size())	// loop to append b elements to main chain which contains b1 a1....an
	{
		if (appendageCount < pairElements.size())
			jacobsthalInsert(jacobsthalNumber, appendageCount, mainChain, pairElements);
		else
			binaryInsert(mainChain, pairElements);
		jacobsthal++;
		appendageCount = calculateJacobsthal(jacobsthal) - calculateJacobsthal(jacobsthal - 1);
	}
}