/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:42:58 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/23 18:55:05 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy request", "None", 72, 45)
{
	;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\033[31mDestructor for RobotomyRequestForm " \
		<< this->getName() << " was called\n\033[0m";
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): Form(obj)
{
	;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	(void)obj;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("robotomy request", target, 72, 45)
{
	;
}

void	RobotomyRequestForm::actualExecute(const Bureaucrat& executor)
{
	Form::execute(executor);
	std::cout << "\033[3m*drilling noises*\033[0m\n";
	std::cout << this->getTarget() << " has been successfully robotomized\n";
}
