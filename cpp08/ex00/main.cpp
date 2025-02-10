/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 13:48:57 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/09 14:59:01 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <class T>
typename T::iterator	easyfind(T& container, int to_find)
{
	typename T::iterator res = std::find(container.begin(), container.end(), to_find);
	if (res == container.end())
	{
		throw (std::invalid_argument("Parameter not found"));
	}
	return (res);
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	
	// vector
	{
		std::vector<int>	vec;
		for (int i = 0; i < 5; i++)
			vec.push_back(i + 1);
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			std::cout << *it << "\n";

		try
		{
			int res = *easyfind(vec, std::atoi(av[1]));
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
		for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
			std::cout << *it << "\n";

		try
		{
			int res = *easyfind(list, std::atoi(av[1]));
			std::cout << "result: " << res << "\n";
		}
		catch (std::invalid_argument& ex)
		{
			std::cout << ex.what() << "\n";
		}
	}
}