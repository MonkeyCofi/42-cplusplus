/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:00:41 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/22 19:19:53 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat Jim("Jim", 1);
			std::cout << Jim;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what();
		}
	}
	std::cout << "\n";
	{
		try
		{
			Bureaucrat Joe("Joe", -3);
			std::cout << Joe;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what();
		}

	}
	std::cout << "\n";
	{
		try
		{
			Bureaucrat Jack("Jack", 180);
			std::cout << Jack;
			
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what();
		}

	}
	std::cout << "\n";
	{
		try
		{
			Bureaucrat Joseph("Joseph", 10);
			std::cout << Joseph;
		}
		catch (Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what();
		}
		catch (Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what();
		}

	}
	std::cout << "\n";
	try
	{
		Bureaucrat Jonathan("Jonathan", 150);
		std::cout << Jonathan;
		Jonathan.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what();
	}
	std::cout << "\n";
	try
	{
		Bureaucrat Jess("Jess", 1);
		std::cout << Jess;
		Jess.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what();
	}

	return (0);
}