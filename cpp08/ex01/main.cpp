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

//int main()
//{
//	Span sp = Span(5);
//	sp.addNumber(6);
//	sp.addNumber(3);
//	sp.addNumber(17);
//	sp.addNumber(9);
//	sp.addNumber(11);
//	sp.printElements();
//	//std::cout << sp.shortestSpan() << std::endl;
//	std::cout << sp.longestSpan() << std::endl;
//	return 0;
//}

int main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	return 0;
	std::vector<int>	vec;
	std::vector<int>	test;
	test.push_back(1);
	test.push_back(5);
	test.push_back(10);
	test.push_back(11);
	test.push_back(14);
	test.push_back(22);
	vec.insert(vec.begin(), test.begin(), test.end());
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		std::cout << "test: " << (*it) << "\n";
	}
}