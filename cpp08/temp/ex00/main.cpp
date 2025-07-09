/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:48:57 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/23 15:34:09 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	
	// vector
	{
		std::vector<int>	vec;
		std::cout << "Array: ";
		for (int i = 0; i < 5; i++)
			vec.push_back(i + 1);
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			std::cout << *it << (it + 1 == vec.end() ? "\n" : " ");
		}
		try
		{
			int res = *easyfind(vec, 123);
			std::cout << "result: " << res << "\n";
		}
		catch (std::invalid_argument& obj)
		{
			std::cout << obj.what() << "\n";
		}
	}
	
	std::cout << "\n";
	// list
	{
		std::list<int>	list;
		for (int i = 0; i < 10; i++)
		{
			int num = i + 1;
			if (num % 2 == 0)
				list.push_front(num);
			else
				list.push_back(num);
		}
		std::cout << "list: ";
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
		{
			std::list<int>::iterator next = it;
			std::advance(next, 1);
			std::cout << *it << (next == list.end() ? "\n" : " ");
		}

		try
		{
			int res = *easyfind(list, 5);
			std::cout << "result: " << res << "\n";
		}
		catch (std::invalid_argument& ex)
		{
			std::cout << ex.what() << "\n";
		}
	}
}