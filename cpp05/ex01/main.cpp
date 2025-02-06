/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:00:41 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/19 16:10:35 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/*
	* if the form can't be signed, throw a grade too low exception
*/

int main(void)
{
	std::cout << "\n";
	{
		try
		{
			Bureaucrat	Bill("Bill", 2);
			std::cout << Bill;
			Form		impeach("impeach", 1, 100);
			std::cout << impeach;
			Bill.signForm(impeach);
		}
		catch(Bureaucrat::GradeTooLowException& e)
		{
			std::cout << e.what();
		}
		catch(Bureaucrat::GradeTooHighException& e)
		{
			std::cout << e.what();
		}
	}
	std::cout << "\n";
	try
	{
		Bureaucrat Bob("Bob", 100);
		std::cout << Bob;
		Form	bob_for_president("president", 100, 100);
		std::cout << bob_for_president;
		Bob.signForm(bob_for_president);
	}
	catch(Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what();
	}
	catch(Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what();
	}
	std::cout << "\n";

	return (0);
}
