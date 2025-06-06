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
#include <ctime>

void	set_random_int(int& i)
{
	i = rand() % 16384;
}

void	set_random_double(double& i)
{
	i = rand() % 16384;
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

template <class T, class Func>
void	iter(T* array, int arr_length, Func func)
{
	for (int i = 0; i < arr_length; i++)
		func(array[i]);
}

template <class T, class Func>
void	iter(const T* array, int arr_length, Func func)
{
	for (int i = 0; i < arr_length; i++)
		func(array[i]);
}

void	printInt(int& i)
{
	std::cout << i << "\n";
}

int main(void)
{
	{
		int size = 3;
		int *arr = new int[size];
		iter(arr, size, set_random_int);
		iter(arr, size, printInt);
		iter(const_cast<const int*>(arr), size, printInt);
		delete [] arr;
	}
	// std::cout << "\n";
	// {
	// 	int size = 5;
	// 	double *arr = new double[size]();
	// 	iter<double>(arr, size, set_random);
	// 	iter<double>(arr, size, print_elem);
	// 	iter<double>(arr, size, half_elem);
	// 	iter<double>(const_cast<double *>(arr), size, print_elem);
	// 	delete [] arr;
	// }
}
