/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:40:58 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/19 15:23:24 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): m_name("Form"), m_signed(false), m_sign_grade(0), m_exec_grade(0)
{
	;
};

Form::~Form()
{
	std::cout << "\033[31mDestructor for Form " << this->m_name << " was called\033[0m\n";
};

// copy constructor
Form::Form(const Form& form) : m_name(form.m_name), m_signed(form.m_signed), \
	m_sign_grade(form.m_sign_grade), m_exec_grade(form.m_exec_grade)
{
	;
};

Form	Form::operator=(const Form& obj)
{
	(void)obj;
	return (*this);
};

// paramterized constructor
Form::Form(std::string name, int sign_grade, int exec_grade) : m_name(name), \
	m_signed(false), m_sign_grade(sign_grade), m_exec_grade(exec_grade)
{
	;
}

const std::string	Form::getName() const
{
	return (this->m_name);
};

bool	Form::getSigned() const
{
	return (this->m_signed);
};

int		Form::getSignGrade() const
{
	return (this->m_sign_grade);
};

int		Form::getExecGrade() const
{
	return (this->m_exec_grade);
}

void	Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->m_sign_grade)
		throw Form::GradeTooLowException();
	this->m_signed = true;
}

const char*	Form::GradeTooHighException::what()
{
	return "Form: Grade too high\n";
}

const char*	Form::GradeTooLowException::what()
{
	return "Form: Grade too low\n";
}

std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	std::cout << obj.getName() << ", signed: " << (obj.getSigned() == true ? "true" : "false") \
		 << ", grade to sign: " << obj.getSignGrade() \
		 	<< " grade to exec: " << obj.getExecGrade() << "\n";
	return (os);
}