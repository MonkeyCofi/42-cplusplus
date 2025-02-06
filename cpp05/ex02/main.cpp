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
	Bureaucrat Joe("Joe", 73);
	Bureaucrat Joseline("Joseline", 5);
	RobotomyRequestForm form("Joe");
	Joe.signForm(form);
	Joe.executeForm(form);
	PresidentialPardonForm joePardon("Joe");
	Joseline.executeForm(joePardon);
	Joseline.signForm(joePardon);
	Joseline.executeForm(joePardon);
	ShrubberyCreationForm shrub("gardenia");
	Joseline.signForm(shrub);
	Joseline.executeForm(shrub);
	return (0);
}
