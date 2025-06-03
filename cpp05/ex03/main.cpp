/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:00:41 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/22 19:31:26 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

/*
	The Three Forms
		presidential pardon
		robotomy request
		shrubbery creation
*/

int main(void)
{
	Intern poorGuy;

	AForm* pardon = poorGuy.makeForm("presidential pardon", "Ahmed Aarij");
	try
	{
		Bureaucrat joshua("Joshua", 70);
		joshua.signForm(*pardon);
		joshua.executeForm(*pardon);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}