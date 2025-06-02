/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:22:48 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/22 20:07:08 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
	std::cout << RED"Destructor for Bureaucrat " << this->m_name << " was called" << RESET << "\n";
};

// copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &obj) : m_name(obj.m_name)
{
	if (obj.m_grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (obj.m_grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	std::cout << "Copy constructor for Bureaucrat was called\n";
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
	this->m_grade++;
	std::cout << "Successfully decremented " << this->m_name << "'s grade\n";
};

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << RED"Bureaucrat " << this->m_name << " couldn't sign form " << form.getName() << RESET << "\n";
		throw (AForm::GradeTooLowException());
	}
	// if this function throws, catch it and print an erro message and then throw its exception again
}

void		Bureaucrat::executeForm(AForm& form)
{
	try
	{
		form.actualExecute(*this);
		std::cout << this->m_name << " executed " << form.getName() << "\n";
	}
	catch(ShrubberyCreationForm::FileOpenException& e)
	{
		// std::cerr << e.what();
		std::cout << "\033[31m" << this->m_name << " couldn't execute form " << form.getName()\
			<< " because the Shrubbery file couldn't be opened\n" << "\033[0m";
		throw (e);
	}
	catch(AForm::UnsignedFormException& e)
	{
		// std::cerr << e.what();
		std::cout << "\033[31m" << this->m_name << " couldn't execute form " << form.getName()\
			<< " because the form is unsigned\n" << "\033[0m";
		throw (e);
	}
	catch(AForm::GradeTooLowExecException& e)
	{
		// std::cerr << e.what();
		std::cout << "\033[31m" << this->m_name << " couldn't execute form " << form.getName()\
			<< " because their grade is too low\n" << "\033[0m";
		throw (e);
	}
}

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& b)
{
	stream << b.getName() << ", bureaucrat grade " << b.getGrade() << "\n";
	return (stream);
};