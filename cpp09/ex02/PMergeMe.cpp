/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:24 by pipolint          #+#    #+#             */
/*   Updated: 2025/06/12 13:58:34 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

long	PMergeMe::sequence[] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 
	5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765,
	2863311531, 5726623061, 11453246123};

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
	// this->oddSize = vector.size() % 2;
	// if (this->oddSize)
	// {
	// 	this->lastElem = vector.back();
	// 	this->vector.pop_back();
	// }
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
		std::cout << (*it) << (it + 1 == structure.end() ? "\n" : " ");
	}
}

void	PMergeMe::printPairs(std::vector< std::pair<int, int> >& print)
{
	for (std::vector< std::pair<int, int> >::iterator it = print.begin(); it != print.end(); it++)
	{
		std::cout << (*it).first << " -> " << (*it).second << "\n";
	}
}

int	PMergeMe::binaryInsertSearch(int _toInsert, size_t capIndex, std::vector<int>& searchVector)
{
	int low = 0;
	int high = capIndex;
	std::cout << _toInsert << " < " << searchVector[capIndex] << "\n";
	while (low <= high)
	{
		int middle = (high + low) / 2;
		if (_toInsert < searchVector[middle])
			high = middle - 1;
		else
			low = middle + 1;
		comparisonCount++;
	}
	return (low);
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
			losers.push_back(*it);
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
	/*
		the vector is now the 'main chain'
		the losers vector is the 'pend chain'
		insert from pend chain to main chain in jacobsthal sequence order
		keep track of the original pairing
	*/
	int	jacobsthalIndex = 3;
	std::cout << "Losers: ";
	printStructure(losers);
	while (1)
	{
		// if the number of elements in losers is leser than jacobsthal index, just binary insert
		if (losers.size() < static_cast<size_t>(getJacobsthal(jacobsthalIndex)))
		{
			std::cout << "Inserting from losers in reverse order\n";
			while (losers.size() > 0)
			{
				int insertPos = binaryInsertSearch(losers.back(), vector.size() - 1, vector);
				vector.insert(vector.begin() + insertPos, losers.back());
				std::cout << "Element to insert: " << losers.back() << " at " << insertPos << "\n";
				losers.pop_back();
			}
			// printStructure(vector);
		}
		else	// use jacobsthal sequence to determine insertion 
		{
			std::cout << "Using jacobsthal to determine insertion point\n";
			int jacobsthalNumber = getJacobsthal(jacobsthalIndex);
			int previousJacobsthal = getJacobsthal(jacobsthalIndex - 1);
			while (jacobsthalNumber > previousJacobsthal)
			{
				int insertPos = 0;
				int toInsert = losers[jacobsthalNumber - 1];
				std::cout << "Inserting " << toInsert << " from pend to main\n";
				// if jacobsthal number is larger than vector size, this means straggler is being inserted
				if (static_cast<size_t>(jacobsthalNumber) > vector.size())
				{
					std::cout << "Using size of main as the cap index\n";
					insertPos = binaryInsertSearch(toInsert, vector.size() - 1, vector);
					vector.insert(vector.begin() + insertPos, toInsert);
				}
				else
				{
					std::cout << "using a" << jacobsthalNumber << " as the cap for the main\n";
					insertPos = binaryInsertSearch(toInsert, jacobsthalNumber - 1, vector);
					vector.insert(vector.begin() + insertPos, toInsert);
				}
				losers.erase(losers.begin() + jacobsthalNumber - 1);
				std::cout << "jacobsthal: " << jacobsthalNumber << "\n";
				jacobsthalNumber--;	
			}
			previousJacobsthal = jacobsthalNumber;
			jacobsthalNumber = getJacobsthal(++jacobsthalIndex);
		}
		if (losers.size() == 0)
			break ;
		// break ;
	}
	printStructure(vector);
	std::cout << "Number of comparisons: " << comparisonCount << "\n";
}
