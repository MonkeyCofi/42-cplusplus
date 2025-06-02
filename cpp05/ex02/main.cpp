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

// int main(void)
// {
// 	Bureaucrat Joe("Joe", 73);
// 	Bureaucrat Joseline("Joseline", 5);
// 	RobotomyRequestForm form("Joe");
// 	Joe.signForm(form);
// 	Joe.executeForm(form);
// 	PresidentialPardonForm joePardon("Joe");
// 	Joseline.executeForm(joePardon);
// 	Joseline.signForm(joePardon);
// 	Joseline.executeForm(joePardon);
// 	ShrubberyCreationForm shrub("gardenia");
// 	Joseline.signForm(shrub);
// 	Joseline.executeForm(shrub);
// 	return (0);
// }

int main(void)
{
	try
	{
		PresidentialPardonForm pardonForm("Emad Hammoude");
		Bureaucrat bureaucrat("Sean", 1);

		bureaucrat.signForm(pardonForm);
		bureaucrat.executeForm(pardonForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		RobotomyRequestForm robotomyForm("Abdullah Sayed");
		Bureaucrat evilMan("Ahmed Aarij", 130);

		evilMan.signForm(robotomyForm);
		evilMan.executeForm(robotomyForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	ShrubberyCreationForm shrubberyForm("Fujairah");
	Bureaucrat piolo("Piolo", 139);
	try
	{

		piolo.incrementGrade();
		piolo.signForm(shrubberyForm);
		piolo.executeForm(shrubberyForm);
		piolo.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	try
	{
		piolo.incrementGrade();
		piolo.incrementGrade();
		piolo.executeForm(shrubberyForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

}