/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:24 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/24 21:13:29 by ppolinta         ###   ########.fr       */
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

// unsigned int	PMergeMe::binarySearchVector(unsigned int start, unsigned int middle, unsigned int end, int valToInsert)
// {
// 	if (end - start == 0)
// 		throw(std::invalid_argument("Element not found"));
// 	if (valToInsert < this->vector[middle])
// 	{
// 		comparisonCount++;
// 		return (binarySearchVector(start, (middle + end) / 2, middle - 1, valToInsert));
// 	}
// 	else if (valToInsert > this->vector[middle])
// 	{
// 		comparisonCount++;
// 		return (binarySearchVector(middle + 1, (middle + end) / 2, end, valToInsert));
// 	}
// 	return (middle);
// }

unsigned int	PMergeMe::binarySearchVector(std::vector<int>& _vector, unsigned int low, unsigned int high, int valToInsert)
{
	unsigned int	middle;

	while (low < high)
	{
		middle = (high + low) / 2;
		if (_vector[middle] < valToInsert)
			low = middle + 1;
		else
			high = middle - 1;
		comparisonCount++;
	}
	return (low);
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
	while (appendageCount < pairElements.size() &&  appendageCount > 0)
	{
		// insert b[jacobsthalNumber - 1] element in reverse order while appendage count is greater than 0
		// insert this->vector[pairElement[appendageCount - 1].first] into the main chain
		// use binarySearch to figure out where to append in the main chain
		// call: binarySearch(0, pairElement[appendageCount - 1] / 2, pairElement[appendageCount - 1], this->vector[pairElement[appendageCount - 1].first]);
		// decrement appendageCount
		unsigned int	insertIndex = binarySearchVector(mainChain, pairElements[appendageCount - 1].second / 2, \
				pairElements[appendageCount - 1].second, mainChain[pairElements[appendageCount - 1].first]);
		appendageCount--;
		(void)insertIndex;
	}
	(void)jacobsthalNumber;
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
	const unsigned int					elemSize = pairSize / 2;
	bool								hasOdd = false;
	std::vector< std::pair<int, int> >	pairElements;
	std::vector<int>					mainChain;
	std::vector<int>					appendChain;
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
	{
		hasOdd = true;	
		pairElements.push_back(std::pair<int, int>(firstElem, -1));
	}

	recurseVector(pairSize * 2);

	mainChain.insert(mainChain.begin(), this->vector.begin(), this->vector.begin() + pairSize);	// inserts b1 a1 into the main chain
	// insert elements into the main and append chain
	for (std::vector< std::pair<int, int> >::iterator it = pairElements.begin() + 1, end = pairElements.end(); it != end; it++)
	{
		if ((*it).second == -1)	// odd element gets inserted to pend
		{
			appendChain.insert(appendChain.end(), begin + (*(it - 1)).second + 1, begin + (*it).first + 1);
			break ;
		}
		mainChain.insert(mainChain.end(), begin + (*it).first + 1, begin + (*it).second + 1);
		appendChain.insert(appendChain.end(), begin + (*(it - 1)).second + 1, begin + (*it).first + 1);
	}
	// std::cout << comparisonCount << " comparisons so far\n";
	std::cout << "Main chain: ";
	printVector(mainChain);
	std::cout << "Pend chain: ";
	printVector(appendChain);
	int	nthJacobsthal = 4;
	unsigned int	appendageCount = calculateJacobsthal(nthJacobsthal) - calculateJacobsthal(nthJacobsthal - 1);
	std::cout << pairElements.size() << "\n";
	if (appendageCount < pairElements.size())
	{
		std::cout << "Val: " << appendChain.at((elemSize * appendageCount) - 1);
		unsigned int idx = binarySearchVector(mainChain, 0, pairElements.at(appendageCount - 1).second, appendChain[(elemSize * appendageCount) - 1]);
		std::cout << "index to insert: " << idx - (elemSize + 1) << "\n";
	}
	// std::cout << "val: " << this->vector[pairElements[appendageCount - 1].first] << "\n";
	// while (1)	// loop to append b elements to main chain which contains b1 a1....an
	// {
		// 	if (appendageCount < pairElements.size())
		// 		jacobsthalInsert(jacobsthal, appendageCount, mainChain, pairElements);
		// 	else
		// 		binaryInsert(mainChain, pairElements);
		// 	jacobsthal++;
		// 	appendageCount = calculateJacobsthal(jacobsthal) - calculateJacobsthal(jacobsthal - 1);
		// 	if (appendageCount > pairElements.size())
		// 		break ;
		// }
	std::cout << "\n";
	(void)elemSize;
	(void)hasOdd;
}