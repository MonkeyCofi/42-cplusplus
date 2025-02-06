/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:28:22 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/24 17:57:39 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
	check the type of the argument passed
	for char: if its displayable, display the character
		else display 'Non displayable'
	for int: if it overflows, print that the integer overflows
	for float: check whether its -inf, +inf
	for double: check wheter its -inf, +inf, or nan
*/

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./cast <str to cast>\n";
		return (1);
	} 
	ScalarConverter::convert(av[1]);
}
