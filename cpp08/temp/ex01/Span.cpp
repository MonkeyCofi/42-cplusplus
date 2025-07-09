/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:33:26 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/19 21:05:56 by pipolint         ###   ########.fr       */
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
	std::vector<int>	differences;

	if (numbers.empty())
		throw(Span::NoElementsException());
	if (numbers.size() == 1)
		throw (Span::OneElementException());
	std::sort(copy.begin(), copy.end());
	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
	{
		if (it + 1 == copy.end())
			break ;
		differences.push_back(*(it + 1) - (*it));
	}
	return (*std::min_element(differences.begin(), differences.end()));
}

int	Span::longestSpan()
{
	if (numbers.empty())
		throw(Span::NoElementsException());
	if (numbers.size() == 1)
		throw (Span::OneElementException());
	return ((*std::max_element(this->numbers.begin(), this->numbers.end())) \
		- (*std::min_element(this->numbers.begin(), this->numbers.end())));
}

void	Span::addNumber(int number)
{
	if (numbers.size() == N)
		throw (Span::VectorFullException());
	numbers.push_back(number);
}

void	Span::addNumber(std::vector<int>::iterator pos, std::vector<int>::iterator _begin, std::vector<int>::iterator _end)
{
	if (numbers.size() == N)
		throw (Span::VectorFullException());
	this->numbers.insert(pos, _begin, _end);
}

void	Span::printElements()
{
	int current = 0;

	for (std::vector<int>::iterator it = this->numbers.begin(); it != this->numbers.end(); it++)
	{
		std::cout << ++current << ": " << *it << "\n";
	}
}

std::vector<int>::iterator	Span::_begin()
{
	return (this->numbers.begin());
}

std::vector<int>::iterator	Span::_end()
{
	return (this->numbers.end());
}

const char*	Span::VectorFullException::what() const throw()
{
	return ("Cannot add number. Vector is full");
}

const char*	Span::OneElementException::what() const throw()
{
	return ("Only one element in vector");
}

const char*	Span::NoElementsException::what() const throw()
{
	return ("Vector is empty");
}