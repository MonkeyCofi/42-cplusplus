/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:33:26 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/10 13:51:19 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	this->N = 0;
}

Span::~Span()
{
	std::cout << "Destructor for Span was called\n";
}

Span::Span(const Span& obj)
{
	this->N = obj.N;
	this->numbers = obj.numbers;
}

Span	&Span::operator=(const Span& obj)
{
	this->N = obj.N;
	this->numbers = obj.numbers;
	return (*this);
}

Span::Span(unsigned int N)
{
	this->N = N;
}

int	Span::shortestSpan()
{
	std::vector<int>	copy(this->numbers);

	if (numbers.empty())
		throw(Span::NoElementsException());
	if (numbers.size() == 1)
		throw (Span::OneElementException());
	std::sort(copy.begin(), copy.end());	// sort the vector of numbers
	
	return (1);
}

int	Span::longestSpan()
{
	if (numbers.empty())
		throw(Span::NoElementsException());
	if (numbers.size() == 1)
		throw (Span::OneElementException());
	return (1);
}

void	Span::addNumber(int number)
{
	if (numbers.size() == N)
		throw (Span::VectorFullException());
	numbers.push_back(number);
}

void	Span::printElements()
{
	int current = 0;
	for (std::vector<int>::iterator it = this->numbers.begin(); it != this->numbers.end(); it++)
	{
		std::cout << ++current << ": " << *it << "\n";
	}
}

const char*	Span::VectorFullException::what()
{
	return ("Cannot add number. Vector is full");
}

const char*	Span::OneElementException::what()
{
	return ("Only one element in vector");
}

const char*	Span::NoElementsException::what()
{
	return ("Vector is empty");
}