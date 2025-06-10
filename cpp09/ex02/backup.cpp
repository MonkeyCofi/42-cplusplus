/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:24 by pipolint          #+#    #+#             */
/*   Updated: 2025/04/07 15:11:25 by pipolint         ###   ########.fr       */
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
	this->vector = obj.vector;
	this->list = obj.list;
};

PMergeMe	&PMergeMe::operator=(const PMergeMe& obj)
{
	this->vector = obj.vector;
	this->list = obj.list;
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
}

std::vector<int>	PMergeMe::swapPairs(std::vector<int>& to_sort)
{
	for (std::vector<int>::iterator it = to_sort.begin(); it != to_sort.end(); it += 2)
	{
		if (it + 1 == to_sort.end())
			break ;
		if ((*it) > *(it + 1))
		{
			std::swap(*it, *(it + 1));
			comparisonCount++;
		}
	}
	return (to_sort);
}

std::vector<int>	PMergeMe::returnWinners(std::vector<int>& _vec)
{
	std::vector<int>	ret;
	// for (std::vector<int>::iterator it = _vec.begin() + 1; it != _vec.end(); it = std::next(it, 2))
	for (std::vector<int>::iterator it = _vec.begin() + 1; it != _vec.end(); it += 2)
	{
		ret.push_back(*it);
		if (it + 1 == _vec.end())
			break ;
	}
	return (ret);
}

std::vector<int>	PMergeMe::returnLosers(std::vector<int>& _vec)
{
	std::vector<int>	ret;
	// for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it = std::next(it, 2))
	for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); it += 2)
	{
		ret.push_back(*it);
		if (it + 1 == _vec.end())
			break ;
	}
	return (ret);
}

void	PMergeMe::mergeInsertionSort(std::vector<int>& _winners, std::vector<int>& _losers)
{
	std::vector<int>	mainChain;
	std::vector<int>	pendChain;
	int					nthJacobsthal;
	int					current;
	int					previous;
	int					elemCount;
	
	mainChain = _winners;
	pendChain = _losers;
	nthJacobsthal = 0;
	while (1)
	{
		nthJacobsthal++;
		current = calculateJacobsthal(nthJacobsthal);
		previous = calculateJacobsthal(nthJacobsthal - 1);
		elemCount = current - previous;
		while (elemCount >= 0)
		{
			elemCount--;
		}
	}
}

void	PMergeMe::sortVector(std::vector<int>& _vec)
{
	if (_vec.size() == 1)
		return ;
	
	std::vector<int>	swapped;
	std::vector<int>	winners;
	std::vector<int>	losers;
	std::vector<int>	_main;
	std::vector<int>	_pend;
	
	swapped = swapPairs(_vec);
	winners = returnWinners(swapped);
	losers = returnLosers(swapped);
	_main = winners;
	sortVector(winners);
	_pend = losers;
	std::cout << "main chain: ";
	printVector(_main);
	std::cout << "pend chain: ";
	printVector(_pend);
	mergeInsertionSort(winners, losers);
}

void	PMergeMe::sortVector()
{
	std::vector<int>	swapped;
	std::vector<int>	winners;
	std::vector<int>	losers;
	std::vector<int>	_main;
	std::vector<int>	_pend;

	swapped = swapPairs(this->vector);
	winners = returnWinners(swapped);
	losers = returnLosers(swapped);
	_main = winners;
	_pend = losers;
	std::cout << "main: ";
	printVector(_main);
	std::cout << "pend: ";
	printVector(_pend);
	sortVector(winners);
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
		std::cout << "low: " << low << " middle: " << middle << " high: " << high << "\n";
		if (low == middle)
			return (_vector[low] < valToInsert ? high : low);
		if (_vector[middle] < valToInsert)
			low = middle + 1;
		else
			high = middle - 1;
		comparisonCount++;
	}
	return (low);
}

int	PMergeMe::calculateJacobsthal(int nthJacobsthal)
{
	if (nthJacobsthal == 0 || nthJacobsthal == 1)
		return (0);
	if (nthJacobsthal == 2 || nthJacobsthal == 3)
		return (1);
	return (calculateJacobsthal(nthJacobsthal - 1) + (calculateJacobsthal(nthJacobsthal - 2) * 2));
}
