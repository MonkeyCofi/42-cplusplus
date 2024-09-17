/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 10:42:20 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/17 14:18:47 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	a = Fixed(1234.4321f);
	Fixed const b(10);
	Fixed c(42.42f);
	Fixed const d(a);
	std::cout << "a is: " << a << std::endl;
	std::cout << "b is: " << b << std::endl;
	std::cout << "c is: " << c << std::endl;
	std::cout << "d is: " << d << std::endl;
	
	std::cout << "a as integer is: " << a.toInt() << std::endl;
	std::cout << "b as integer is: " << b.toInt() << std::endl;
	std::cout << "c as integer is: " << c.toInt() << std::endl;
	std::cout << "d as integer is: " << d.toInt() << std::endl;
}