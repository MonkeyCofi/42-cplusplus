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

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", "None", 25, 5)
{
	;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\033[31mDestructor for PresidentialPardonForm " \
		<< this->getName() << " was called\n\033[0m";
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj): AForm(obj)
{
	;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	(void)obj;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", target, 25, 5)
{
	;
}

void	PresidentialPardonForm::actualExecute(const Bureaucrat& executor)
{
	AForm::execute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
