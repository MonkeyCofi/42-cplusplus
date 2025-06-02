/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:22:48 by pipolint          #+#    #+#             */
/*   Updated: 2025/04/06 20:09:27 by pipolint         ###   ########.fr       */
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
	std::cout << GREEN"Successfully created Bureaucrat " << this->m_name << " with grade " << this->m_grade << RESET"\n";
};

Bureaucrat::~Bureaucrat()
{
	std::cout << RED"Destructor for Bureaucrat " << this->m_name << " was called" << RESET << "\n";
};

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : m_name(obj.m_name)
{
	if (obj.getGrade() < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (obj.getGrade() > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->m_grade = obj.m_grade;
};

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &obj)
{
	(void)obj;
	return (*this);
};

const std::string	Bureaucrat::getName() const
{
	return (this->m_name);
};

int	Bureaucrat::getGrade() const
{
	return (this->m_grade);
};

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high\n";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low\n";
}

void		Bureaucrat::incrementGrade()
{
	std::cout << "Attempting to increment " << this->m_name << "'s grade from " << this->m_grade << " to " << this->m_grade - 1 << "\n";
	if (this->m_grade - 1 < 1)
		throw GradeTooHighException();
	std::cout << "Successfully incremented " << this->m_name << "'s grade\n";
	this->m_grade--;
}

void		Bureaucrat::decrementGrade()
{
	std::cout << "Attempting to decrement " << this->m_name << "'s grade from " << this->m_grade << " to " << this->m_grade + 1 << "\n";
	if (this->m_grade + 1 > 150)
		throw GradeTooLowException();
	std::cout << "Successfully decremented " << this->m_name << "'s grade\n";
	this->m_grade++;
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return (stream);
};