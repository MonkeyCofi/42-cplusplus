/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:00:41 by pipolint          #+#    #+#             */
/*   Updated: 2025/04/06 20:06:34 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat	Bill("Bill", 2);
			std::cout << Bill;

			Form		swag("swagify", 1, 100);
			std::cout << swag;

			Bill.signForm(swag);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	try
	{
		Bureaucrat Bob("Bob", 100);
		std::cout << Bob;
		Form	bob_for_president("president", 100, 100);
		std::cout << bob_for_president;
		Bob.signForm(bob_for_president);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
	return (0);
}
