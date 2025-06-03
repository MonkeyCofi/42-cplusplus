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

int main(void)
{
	std::cout << GREEN"In first test block\n" << RESET;
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

	std::cout << GREEN"In second test block\n" << RESET;
	try
	{
		Bureaucrat evilMan("Ahmed Aarij", 130);
		RobotomyRequestForm robotomyForm("Abdullah Sayed");

		evilMan.signForm(robotomyForm);
		evilMan.executeForm(robotomyForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	std::cout << GREEN"In third test block\n" << RESET;
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

	std::cout << GREEN"In fourth test block\n" << RESET;
	try
	{
		piolo.incrementGrade();
		piolo.executeForm(shrubberyForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}

	std::cout << GREEN"In fifth test block\n" << RESET;
	try
	{
		Bureaucrat bill("Bill", 149);
		AForm* robotomizationForm = new RobotomyRequestForm("Jorjor Well");
		bill.signForm(*robotomizationForm);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what();
	}
}