/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:20:51 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/27 16:40:10 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template<class T>
void	print_elem(T& elem)
{
	std::cout << elem << "\n";
}

template<class T>
void	increment_elem(T& elem)
{
	elem++;
}

template<class T>
void	half_elem(T& elem)
{
	elem /= 2;
}

template<class T>
void	iter(T* array, int arr_len, void(*func)(T&))
{
	for (int i = 0; i < arr_len; i++)
		func(array[i]);
}

int main(void)
{
	{
		std::cout << "\n";
		std::cout << "\033[2;34mIntegers\n\033[0m";
		int arr[5] = {1, 2, 3, 4, 5};
		iter(arr, 5, print_elem);
		std::cout << "Incrementing all elements of the array now\n";
		iter(arr, 5, increment_elem);
		iter(arr, 5, print_elem);
		std::cout << "\n";
	}
	{
		std::cout << "\n";
		std::cout << "\033[2;34mCharacters\n\033[0m";
		char char_arr[4] = {'d', 'l', '`', 'c'};
		iter(char_arr, 4, print_elem);
		iter(char_arr, 4, increment_elem);
		std::cout << "Now the array spells: " << "\n";
		iter(char_arr, 4, print_elem);
		std::cout << "\n";
	}
	{
		std::cout << "\n";
		std::cout << "\033[2;34mDoubles and integers\n\033[0m";
		double	arr1[4] = {1.2, 2.4, 3.6, 4.8};
		iter(arr1, 4, print_elem);
		std::cout << "Halving all arr1 values\n";
		iter(arr1, 4, half_elem);
		iter(arr1, 4, print_elem);
		std::cout << "\n";
		int arr2[4] = {1, 3, 5, 7};
		iter(arr2, 4, print_elem);
		std::cout << "Halving all arr2 values\n";
		iter(arr2, 4, half_elem);
		iter(arr2, 4, print_elem);
		std::cout << "\n";
	}
}