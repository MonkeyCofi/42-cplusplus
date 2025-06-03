/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:42:58 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/22 15:21:20 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// default constructor
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotmyRequestForm", "None", 72, 45)
{
	;
}

// destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[31mDestructor for RobotomyRequestForm " \
		<< this->getName() << " was called\n\033[0m";
}

// copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): AForm(obj)
{
	;
}

// copy assignment operator
RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	(void)obj;
	return (*this);
}

// parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotmyRequestForm", target, 72, 45)
{
	std::cout << GREEN << "RobotomyRequestForm: " << "Sign grade: " << 72 << " Exec grade: " << 45 << RESET << "\n";
}

void	RobotomyRequestForm::actualExecute(const Bureaucrat& executor)
{
	AForm::execute(executor);
	std::cout << "\033[3m*drilling noises*\033[0m\n";
	std::cout << this->getTarget() << " has been successfully robotomized\n";
}
