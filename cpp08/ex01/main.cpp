/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 15:37:27 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/10 16:52:24 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// int main(void)
// {
// 	Span s(5);
// 	try
// 	{
		
// 		//s.addNumber(1);
// 		//s.addNumber(2);
// 		//s.addNumber(3);
// 	}
// 	catch (Span::VectorFullException& ex)
// 	{
// 		std::cout << ex.what() << "\n";
// 	}
// 	s.printElements();
// }

//int main(void)
//{
//	std::vector<int>	vec;

//	for (int i = 0; i < 10; i++)
//	{
//		int ranNum = rand() % 10;
//		vec.push_back(ranNum);
//	}
//	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
//		std::cout << *it << "\n";
//	std::cout << "\n\n";
//	std::vector<int>	copy(vec);
//	std::sort(copy.begin(), copy.end());
//	for (std::vector<int>::iterator it = copy.begin(); it != copy.end(); it++)
//		std::cout << *it << "\n";
//	std::cout << "\n\n";
//	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
//		std::cout << *it << "\n";
//}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.printElements();
	//std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}