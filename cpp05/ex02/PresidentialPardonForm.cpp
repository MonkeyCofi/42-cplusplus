/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:32:11 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/22 15:34:03 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// base constructor
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", "None", 25, 5)
{

}

// destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[31mDestructor for PresidentialPardonForm" << " was called\n\033[0m";
}

// copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj): AForm(obj)
{
	;
}

// copy assignment operator
PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	(void)obj;
	return (*this);
}

// parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", target, 25, 5)
{
	std::cout << GREEN << "PresidentialPardonForm: " << "Sign grade: " << 25 << " Exec grade: " << 5 << RESET << "\n";
}

void	PresidentialPardonForm::actualExecute(const Bureaucrat& executor)
{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
