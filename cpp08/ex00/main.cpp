/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:41:06 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/08 15:25:23 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <class T>
typename T::iterator	easyfind(T& container, int to_find)
{
	// create the result
	typename T::iterator	res = std::find(container.begin(), container.end(), to_find);
	if (res == container.end())
	{
		throw (std::invalid_argument("Could not find number in container"));
	}
	return (res);
}

int main(void)
{
	{
		std::vector<int>	intVec;
		int n = 0;
		for (int i = 0; i < 5; i++)
			intVec.push_back(i + 1);
		try
		{
			n = *easyfind(intVec, 6);
		}
		catch  (std::invalid_argument)
		{
			std::cout << "Could not find number in container\n";
		}
	}

	{
		std::list<int>	intList;
		for (int i = 0; i < 5; i++)
		{
			intList.push_front(i);
		}
		for (std::list<int>::iterator it = intList.begin(); it != intList.end(); it++)
		{

		}
	}
}
