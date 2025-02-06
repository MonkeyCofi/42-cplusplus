/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:22:48 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/19 16:14:01 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : m_name("Kyle")
{
	this->m_grade = 1;
};

Bureaucrat::Bureaucrat(std::string name, int grade) : m_name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->m_grade = grade;
};

Bureaucrat::~Bureaucrat()
{
	std::cout << "\033[31mDestructor for Bureaucrat " << this->m_name << " was called\033[0m\n";
};

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : m_name(obj.m_name)
{
	this->m_grade = obj.m_grade;
};

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	(void)obj;
	return (*this);
};

std::string	Bureaucrat::getName() const
{
	return (this->m_name);
};

int	Bureaucrat::getGrade() const
{
	return (this->m_grade);
};

const char*	Bureaucrat::GradeTooHighException::what()
{
	return "Grade too high\n";
}

const char*	Bureaucrat::GradeTooLowException::what()
{
	return "Grade too low\n";
}

void		Bureaucrat::incrementGrade()
{
	if (this->m_grade - 1 < 1)
		throw GradeTooHighException();
	this->m_grade--;
}

void		Bureaucrat::decrementGrade()
{
	if (this->m_grade + 1 > 150)
		throw GradeTooLowException();
	this->m_grade++;
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return (stream);
};