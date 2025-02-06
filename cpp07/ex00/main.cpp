/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:20:51 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/27 16:13:34 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

template<class T>
T	min(T x, T y)
{
	return (x < y ? x : y);
}

template<class T>
T	max(T x, T y)
{
	return (x > y ? x : y);
}

template<class T>
void	swap(T& x, T& y)
{
	T	temp = x;
	x = y;
	y = temp;
}

int main(void)
{
	{
		std::cout << "\n";
		std::cout << "\033[2;34mMin and max\n\033[0m";
		int x = 5;
		int y = 10;
		std::cout << "x is " << x << " and y is " << y << "\n";
		std::cout << "Between x and y, " << (max<int>(x, y) == x ? "x" : "y") << " is greater\n";
		std::cout << "\n";
		double a = 1.2;
		double b = -21;
		std::cout << "a is " << a << " and b is " << b << "\n";
		std::cout << "Between a and b, " << (min<double>(a, b) == a ? "a" : "b") << " is lesser\n";
		std::cout << "\n";
	}
	{
		std::cout << "\033[2;34mSwap\n\033[0m";
		double x = 12.1;
		double y = -66.1;
		std::cout << "x before swap: " << x << "\n";
		std::cout << "y before swap: " << y << "\n";
		swap<double>(x, y);
		std::cout << "\n";
		std::cout << "x after swap: " << x << "\n";
		std::cout << "y after swap: " << y << "\n";
		std::cout << "\n";
	}
}