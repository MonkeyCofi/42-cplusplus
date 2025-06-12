/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:47:11 by pipolint          #+#    #+#             */
/*   Updated: 2025/06/12 19:32:28 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//int main(int ac, char **av){if (ac < 2){std::cerr << "Usage: ./PmergeMe [Sequence of numbers]\n";return (1);}std::cout << "There are " << ac - 1 << " elements\n";PmergeMe	containers;try{containers.fillContainers(const_cast<const char **>(av));}catch(std::invalid_argument& e){std::cerr << e.what() << "\n";return (1);}containers.sortVector();containers.sortList();containers.printVector();(void)av;}

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Usage: ./PmergeMe [Sequence of numbers]\n";
		return (1);
	}
	std::cout << "There are " << ac - 1 << " elements\n";
	PmergeMe	containers;
	try
	{
		containers.fillContainers(const_cast<const char **>(av));
	}
	catch(std::invalid_argument& e)
	{
		std::cerr << e.what() << "\n";
		return (1);
	}
	containers.sortVector();
	containers.printVector();
	// containers.sortList();
	// containers.printVector();
	// (void)av;
}

//int main(void)
//{
//	std::vector<int> vector;
//	vector.push_back(3);
//	vector.push_back(6);
//	vector.push_back(8);
//	vector.push_back(10);
//	//int num = 15;
//	//unsigned int position = PmergeMe::binarySearchVector(vector, 0, vector.size(), num);
//	//std::cout << num << " should be inserted at position: " << position << "\n";
//	//vector.insert(vector.begin() + position, num);
//	//for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
//	//{
//	//	std::cout << *it << "\n";
//	//}

//	int num = 2;
//	unsigned position = PmergeMe::binarySearchVector(vector, 0, vector.size(), num);
//	std::cout << num << " should be inserted at position: " << position << "\n";
//	vector.insert(vector.begin() + position, num);
//	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
//	{
//		std::cout << *it << "\n";
//	}
	
//	num = -3;
//	position = PmergeMe::binarySearchVector(vector, 0, vector.size(), num);
//	std::cout << num << " should be inserted at position: " << position << "\n";
//	vector.insert(vector.begin() + position, num);
//	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
//	{
//		std::cout << *it << "\n";
//	}
//}