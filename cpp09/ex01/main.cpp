/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 12:52:58 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/08 18:13:18 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./rpn <expression>\n";
		return (1);
	}

	try
	{
		RPN::fillStack(av[1]);
	}
	catch (std::invalid_argument& e)
	{
		std::cerr << e.what() << "\n";
		return (1);
	}
}