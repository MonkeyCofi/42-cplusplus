/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:37:27 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/19 21:03:22 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		
		std::vector<int>	nums;
		time_t	l;
		srand(time(&l));
		for (int i = 0; i < 10000; i++)
			nums.push_back(rand() % 10000);
		Span span(10000);
		span.addNumber(span._begin(), nums.begin(), nums.end());
		for(std::vector<int>::iterator it = span._begin(); it != span._end(); it++)
		{
			std::cout << (*it) << "\n";
		}
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << "\n";
	}
}
