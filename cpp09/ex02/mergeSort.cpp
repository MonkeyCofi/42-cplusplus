/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergeSort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:46:58 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/14 17:59:12 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
typedef std::vector<int> vec;
typedef std::vector<int>::iterator it;

void	mergeHalves(vec vector, size_t begin, size_t midpoint, size_t end, vec& answer)
{
	std::cout << "Left half\n";
	size_t	answerIndex = 0;
	for (size_t i = begin; i <= midpoint; i++)
	{
		//if ()
		std::cout << vector[i] << "\n";
	}
	std::cout << "\n";
	std::cout << "Right half\n";
	for (size_t i = midpoint + 1; i < end; i++)
	{
		std::cout << vector[i] << "\n";
	}
	std::cout << "\n";
}

void	splitVector(vec vector, size_t begin, size_t end, vec& answer)
{
	if (begin >= end)
		return ;
	std::cout << "\n";
	for (size_t i = begin; i != end; i++)
	{
		std::cout << "Vec: " << vector[i] << "\n";
	}
	size_t	midpoint = (begin + end) / 2;
	splitVector(vector, begin, midpoint, answer);
	splitVector(vector, midpoint + 1, end, answer);
	//mergeHalves(vector, begin, midpoint, end, answer);
}

void	mergeSort(vec vector , size_t begin, size_t end)
{
	vec answer;

	splitVector(vector, begin, end, answer);
}

int main(void)
{
	std::vector<int> vecToSort;
	vecToSort.push_back(5);
	vecToSort.push_back(1);
	vecToSort.push_back(2);
	vecToSort.push_back(3);
	vecToSort.push_back(4);
	mergeSort(vecToSort, 0, vecToSort.size());
}