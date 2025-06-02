/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:22:48 by pipolint          #+#    #+#             */
/*   Updated: 2025/04/06 20:07:40 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

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
	std::cout << RED"Destructor for Bureaucrat " << this->m_name << " was called\033[0m\n" << RESET;
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

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << "\033[32m" << this->m_name << " signed " << form.getName() << "\033[0m\n";
	}
	catch(Form::GradeTooLowException& e)
	{
		e.what();
		std::cout << "\033[31m" << this->m_name << " couldn't sign the form '" << form.getName() << "' because" \
			<< (this->m_grade < 1 ? " their grade is too high\n" : " their grade is too low\n") << "\033[0m";
	}
	//if (form.getSigned() == true)
	//{
	//	std::cout << "\033[32m" << this->m_name << " signed " << form.getName() << "\033[0m\n";
	//}
	//else
	//{
	//	std::cout << "\033[31m" << this->m_name << " couldn't sign the form " << form.getName() << " because " \
	//		<< (this->m_grade < 1 ? " their grade is too high\n" : " their grade is too low\n") << "\033[0m";
	//}
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return (stream);
};