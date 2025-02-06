/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:18:42 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/19 15:53:21 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed	a;
	Fixed	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	
	float one = 0.1;
	double two = 0.1;
	Fixed c(one);
	Fixed d((float)two);
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << (c == d ? "c is equal to d" : "c is not equal to d") << std::endl;

	std::cout.precision(50);
	std::cout << "One is " << one << std::endl;
	std::cout << "Two is " << two << std::endl;
	std::cout << (one == two ? "True" : "False") << std::endl;
	
}