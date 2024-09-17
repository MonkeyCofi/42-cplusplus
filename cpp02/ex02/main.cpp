/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:18:42 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/17 20:32:12 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
	//Fixed a(42.42f);
	//Fixed b(a);
	//Fixed c(50);

	//std::cout << "a " << a << std::endl;
	//std::cout << "b " << b << std::endl;
	//std::cout << "c " << c + 5 << std::endl;

	//std::cout << ((a == b) ? "True" : "False") << std::endl;
	Fixed	a;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl;
	
	Fixed b(Fixed(-20) + Fixed(-1));
	//Fixed	b(Fixed(5.05f) * Fixed(2));
	std::cout << b << std::endl;
}