/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:40:58 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/22 15:30:23 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

// base constructor
AForm::AForm(): m_name("Form"), m_signed(false), m_sign_grade(0), m_exec_grade(0), m_target("None")
{
	;
};

// destructor
AForm::~AForm()
{
	std::cout << RED"Base form destructor for " << this->m_name << " form was called\033[0m\n";
};

// copy constructor
AForm::AForm(const AForm& form) : m_name(form.m_name), m_signed(form.m_signed), \
	m_sign_grade(form.m_sign_grade), m_exec_grade(form.m_exec_grade), m_target(form.m_target)
{
	;
};

// paramterized constructor
AForm::AForm(std::string name, std::string target, int sign_grade, int exec_grade) : m_name(name), \
	m_signed(false), m_sign_grade(sign_grade), m_exec_grade(exec_grade), m_target(target)
{
	;
}

const std::string	AForm::getName() const
{
	return (this->m_name);
};

const std::string	AForm::getTarget() const
{
	return (this->m_target);
};

bool	AForm::getSigned() const
{
	return (this->m_signed);
};

int		AForm::getSignGrade() const
{
	return (this->m_sign_grade);
};

int		AForm::getExecGrade() const
{
	return (this->m_exec_grade);
}

void	AForm::beSigned(Bureaucrat& b)
{
	std::cout << GREEN << b.getName() << " is attempting to sign form named " << this->m_name 
		<< " with required sign grade " << this->m_sign_grade << " and required exec grade "
			<< this->m_exec_grade << RESET"\n";
	if (b.getGrade() > this->m_sign_grade)
		throw AForm::GradeTooLowException();
	std::cout << this->getName() << " has been signed by " << b.getName() << "\n";
	this->m_signed = true;
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "Form: Grade too high\n";
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "Form: Grade too low\n";
}

const char*	AForm::UnsignedFormException::what() const throw()
{
	return "Form: Form is unsigned\n";
}

const char*	AForm::GradeTooLowExecException::what() const throw()
{
	return "Form: Form cannot be executed due to grade being too low\n";
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	std::cout << obj.getName() << ", signed: " << (obj.getSigned() == true ? "true" : "false") \
		 << ", grade to sign: " << obj.getSignGrade() \
		 	<< " grade to exec: " << obj.getExecGrade() << "\n";
	return (os);
}

void		AForm::execute(Bureaucrat const& executor) const
{
	if (this->m_signed == false)	// form is unsigned therefore unexecutable
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->m_exec_grade)	// bureaucrat's grade is too low
		throw AForm::GradeTooLowExecException();
}
