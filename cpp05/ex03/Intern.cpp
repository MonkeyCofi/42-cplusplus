/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:46:29 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/23 18:53:33 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	;
}

Intern::~Intern()
{
	;
}

Intern::Intern(const Intern& obj)
{
	(void)obj;
}

Intern	&Intern::operator=(const Intern& obj)
{
	(void)obj;
	return (*this);
}

AForm*	Intern::makePardonForm(std::string form_target)
{
	return (new PresidentialPardonForm(form_target));
}

AForm*	Intern::makeRobotomyForm(std::string form_target)
{
	return (new RobotomyRequestForm(form_target));
}

AForm*	Intern::makeShrubberyCreationForm(std::string form_target)
{
	return (new ShrubberyCreationForm(form_target));
}

AForm*	Intern::makeForm(std::string form_name, std::string form_target)
{
	std::string	selected_form = "none";
	std::string	options[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm	*(Intern::*forms[3])(std::string) = {&Intern::makePardonForm, &Intern::makeRobotomyForm, &Intern::makeShrubberyCreationForm};
	for (int i = 0; i < 3; i++)
	{
		if (options[i] == form_name)
		{
			std::cout << "\033[30mIntern created form\n" << RESET;
			return ((this->*forms[i])(form_target));
		}
	}
	std::cerr << RED"Couldn't create form because " << form_name << " doesn't exist\n" << RESET;
	return (NULL);
}
