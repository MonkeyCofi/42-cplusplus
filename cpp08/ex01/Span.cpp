/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:33:26 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/09 17:45:34 by pipolint         ###   ########.fr       */
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
}

Span	&Span::operator=(const Span& obj)
{
	this->N = obj.N;
	return (*this);
}

Span::Span(unsigned int N)
{
	this->N = N;
}

int	Span::shortestSpan()
{
	if (numbers.empty())
		throw(Span::NoElementsException());
	if (numbers.size() == 1)
		throw (Span::OneElementException());
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