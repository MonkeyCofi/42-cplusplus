/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:45:24 by pipolint          #+#    #+#             */
/*   Updated: 2025/06/14 19:32:12 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

long	PmergeMe::sequence[] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 
	5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765,
	2863311531, 5726623061, 11453246123};

int comparisonCount = 0;

PmergeMe::PmergeMe()
{
	oddSize = false;
	lastElem = -1;
};

PmergeMe::~PmergeMe()
{
	;
};

PmergeMe::PmergeMe(const PmergeMe& obj)
{
	*this = obj;
};

PmergeMe	&PmergeMe::operator=(const PmergeMe& obj)
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

void	PmergeMe::fillContainers(const char** args)
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

long	PmergeMe::getJacobsthal(int n)
{
	return (PmergeMe::sequence[n]);
}

template <typename T>
void	PmergeMe::printStructure(T& structure)
{
	for (typename T::iterator it = structure.begin(); it != structure.end(); it++)
	{
		std::cout << (*it) << (it + 1 == structure.end() ? "\n" : " ");
	}
}

void	PmergeMe::printPairs(std::vector< std::pair<int, int> >& print)
{
	for (std::vector< std::pair<int, int> >::iterator it = print.begin(); it != print.end(); it++)
	{
		std::cout << (*it).first << " -> " << (*it).second << "\n";
	}
}

int	PmergeMe::binaryInsertSearch(int _toInsert, size_t capIndex, std::vector<int>& searchVector)
{
	int low = 0;
	int high = capIndex;
	while (low <= high)
	{
		int middle = round((high + low) / 2);
		std::cout << "low " << searchVector[low] << " middle " << searchVector[middle] << " high " << searchVector[high] << " insert " << _toInsert << "\n";
		if (_toInsert < searchVector[middle])
			high = middle - 1;
		else
			low = middle + 1;
		comparisonCount++;
	}
	return (low);
}

void	PmergeMe::printVector()
{
	std::cout << "\033[34m";
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
		std::cout << (*it) << " ";
	std::cout << "\n\033[0m";
}

void	PmergeMe::positionPendElements(std::vector<int>& unsorted_winners, std::vector<int>& sorted_winners, 
	std::vector<int>& losers, std::vector<int>& pendChain)
{
	/*
		go through the vector of new winners
		for each winner, find its position in the orignal_winners vector
			the loser at this found position gets pushed into the pendChain
	*/
	// std::cout << "Untouched winners: ";
	// printStructure(unsorted_winners);
	// std::cout << "Sorted winners: ";
	// printStructure(sorted_winners);
	// std::cout << "Size of winners: " << unsorted_winners.size() << "\n";
	// std::cout << "Size of winners: " << sorted_winners.size() << "\n";
	// std::cout << "Size of losers: " << losers.size() << "\n";
	// std::cout << "losers: ";
	// printStructure(losers);
	for (size_t i = 0, size = sorted_winners.size(); i < size; i++)
	{
		// returns an iterator to sorted_value[i] in the unsorted_winners vector
		std::vector<int>::iterator pos = std::find(unsorted_winners.begin(), 
			unsorted_winners.end(), sorted_winners[i]);
		std::cout << "current element: " << (*pos) << "\n";
		// get the distance from the start of the losers vector to the position
		int index = std::distance(unsorted_winners.begin(), pos);
		pendChain.push_back(losers[index]);
	}
	if (losers.size() > unsorted_winners.size())
		pendChain.push_back(losers[losers.size() - 1]);
	(void)losers;
	(void)pendChain;
}

/*
	form pairs and sort using one comparison per pair
	once the pairs are sorted; name all elements a[i] and b[i] where a[i] - a[n / 2] > b[i] - b[n / 2]
	repeat this process for all a[i] - a[n / 2] elements

*/

void	PmergeMe::insertPend(std::vector<int>& pendChain, std::vector<int>& unsorted_winners, std::vector<int>& losers)
{
	std::cout << "\033[31mNEW CALL\033[0m\n";
	// the pendchain is the losers vector sorted according to its winners
	std::cout << "Pend: ";
	printStructure(pendChain);
	std::cout << "Inserting into: ";
	printStructure(this->vector);
	unsigned int	insertCount = 0;
	int	jacobsthalIndex = 3;
	unsigned int	currentJacobsthal = getJacobsthal(jacobsthalIndex);
	unsigned int	prevJacobsthal = getJacobsthal(jacobsthalIndex - 1);
	std::vector<int>	winners = vector;
	// insert pend chain's first element
	if (pendChain.size())
	{
		vector.insert(vector.begin(), pendChain[0]);
		insertCount++;
	}
	while (insertCount < pendChain.size() - 1)	// terminate loop once insert count is equal to size
	{
		if (currentJacobsthal == prevJacobsthal)
		{
			prevJacobsthal = currentJacobsthal;
			currentJacobsthal = getJacobsthal(++jacobsthalIndex);
		}
		// find pend chain's partner's position in vector
		int	cap = 0;
		std::vector<int>::iterator partnerIt = std::find(vector.begin(), vector.end(), winners[currentJacobsthal - 1]);
		cap = partnerIt - vector.begin() - (partnerIt == vector.end());
		// int	pos = binaryInsertSearch(pendChain[currentJacobsthal - 1], partnerIt - vector.begin(), vector);
		int	pos = binaryInsertSearch(pendChain[currentJacobsthal - 1], cap, vector);
		vector.insert(vector.begin() + pos, pendChain[currentJacobsthal - 1]);
		insertCount++;
		currentJacobsthal--;
	}
	(void)prevJacobsthal;
	(void)unsorted_winners;
	(void)currentJacobsthal;
	(void)losers;
}

void	PmergeMe::sortVector()
{
	if (this->vector.size() <= 1)
		return ;
	if (this->vector.size() == 2)
	{
		if (comp(vector[0], vector[1]) == false)
		{
			std::swap(vector[0], vector[1]);
		}
		printStructure(vector);
		return ;
	}
	std::vector<int>					winners;
	std::vector<int>					losers;
	std::vector< std::pair<int, int> >	pairs;

	for (std::vector<int>::iterator it = vector.begin(); it != vector.end();)
	{
		if (it + 1 == vector.end())
		{
			// std::cout << "True" << "\n";
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
	printPairs(pairs);
	std::cout << "\n";
	// winners vector stores the original positions of the winners
	// the cap index for the binarysearch should be where the loser's winner is with respect to whats been inserted
	this->vector = winners;
	// std::cout << "winners: ";
	// printStructure(winners);
	// std::cout << "Losers: ";
	// printStructure(losers);
	sortVector();
	// printStructure(vector);
	std::vector<int>	pendChain;
	positionPendElements(winners, vector, losers, pendChain);
	insertPend(pendChain, winners, losers);
}
