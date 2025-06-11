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

long	PMergeMe::sequence[] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 
	5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

int comparisonCount = 0;

PMergeMe::PMergeMe()
{
	oddSize = false;
	lastElem = -1;
};

PMergeMe::~PMergeMe()
{
	;
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

long	PMergeMe::getJacobsthal(int n)
{
	return (PMergeMe::sequence[n]);
}

template <typename T>
void	PMergeMe::printStructure(T& structure)
{
	for (typename T::iterator it = structure.begin(); it != structure.end(); it++)
	{
		std::cout << (*it) << "\n";
	}
}

void	PMergeMe::printPairs(std::vector< std::pair<int, int> >& print)
{
	for (std::vector< std::pair<int, int> >::iterator it = print.begin(); it != print.end(); it++)
	{
		std::cout << "First elem: " << (*it).first << "\n";
		std::cout << "Second elem: " << (*it).second << "\n";
	}
}

template <typename T>
int	PMergeMe::binaryInsertSearch(int _toInsert, T& container)
{
	size_t	size = container.size();
	for (size_t i = 0; i < size; i++)
	{
		if (comp(_toInsert, container.begin() + i) == true) // _toInsert < container.at(i)
			
	}
	return (index);
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
	std::vector<int>					winners;
	std::vector<int>					losers;
	std::vector< std::pair<int, int> >	pairs;

	for (std::vector<int>::iterator it = vector.begin(); it != vector.end();)
	{
		if (it + 1 == vector.end())
		{
			std::cout << "True" << "\n";
			break ;
		}
		if (comp((*it), *(it + 1)))
		{
			losers.push_back(*it);
			winners.push_back(*(it + 1));
			pairs.push_back(std::pair<int, int>((*it), *(it + 1)));
		}
		else
		{
			winners.push_back(*it);
			losers.push_back(*(it + 1));
			pairs.push_back(std::pair<int, int>(*(it + 1), (*it)));
		}
		it += 2;
	}
	this->vector = winners;
	sortVector();
	std::cout << "\033[34m";
	printStructure(winners);
	std::cout << "\033[0m";
	std::cout << "\033[31m";
	printStructure(losers);
	std::cout << "\033[0m";
	printPairs(pairs);
	std::cout << "\n";
	/*
		the vector is now the 'main chain'
		the losers vector is the 'pend chain'
		insert from pend chain to main chain in jacobsthal sequence order
		keep track of the original pairing
	*/
	int	jacobsthalIndex = 3;
	while (1)
	{
		// if the number of elements in losers is leser than jacobsthal index, just binary insert
		break ;
	}
	(void)jacobsthalIndex;
}
