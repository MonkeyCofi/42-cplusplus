/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:00:41 by pipolint          #+#    #+#             */
/*   Updated: 2025/04/06 20:10:26 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << GREEN << "In first block" << RESET << "\n";
		try
		{
			Bureaucrat Jim("Jim", 1);
			std::cout << Jim;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	{
		std::cout << GREEN << "In second block" << RESET << "\n";
		const std::string name = "Joe";
		try
		{
			Bureaucrat Joe(name, -3);
			std::cout << Joe;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	{
		std::cout << GREEN << "In third block" << RESET << "\n";
		const std::string name = "Jack";
		try
		{
			Bureaucrat Jack(name, 180);
			std::cout << Jack;
			
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	{
		std::cout << GREEN << "In fourth block" << RESET << "\n";
		const std::string name = "Jonathan";
		try
		{
			Bureaucrat Jonathan(name, 150);
			std::cout << Jonathan;
			Jonathan.decrementGrade();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	{
		std::cout << GREEN << "In fifth block" << RESET << "\n";
		const std::string name = "Jess";
		try
		{
			Bureaucrat Jess(name, 1);
			std::cout << Jess;
			Jess.incrementGrade();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	{
		std::cout << GREEN << "In sixth block" << RESET << "\n";
		const std::string name = "Jasper";
		try
		{
			Bureaucrat Jasper(name, 5);
			std::cout << Jasper;
			Jasper.incrementGrade();
			Jasper.decrementGrade();
			while (1)
				Jasper.incrementGrade();
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	{
		std::cout << GREEN << "In seventh block" << RESET"\n";
		const std::string b1 = "Taylor";
		const std::string b2 = "Swift";
		try
		{
			Bureaucrat Taylor(b1, 0);
			Bureaucrat Swift(Taylor);
		}
		catch (std::exception& e)
		{
			std::cerr << e.what();
		}
	}

	return (0);
}