/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:00:41 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/23 18:54:25 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern newGuy;
	Bureaucrat	Joe("Joe", 150);
	Form	*form = newGuy.makeForm("shrubbery creation", "gardenia");
	Joe.signForm(*dynamic_cast<ShrubberyCreationForm*>(form));
	delete(form);
	//AForm* form = newGuy.makeForm("horse balls and penis", "test");
	//(void)form;
}