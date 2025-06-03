/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:32:11 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/22 15:34:03 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// default constructor
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", "None", 145, 137)
{
	;
}

// destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[31mDestructor for ShrubberyCreationForm " \
		<< this->getName() << " was called\n\033[0m";
}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): AForm(obj)
{
	;
}

// copy assignment operator
ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	(void)obj;
	return (*this);
}

// parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", target, 145, 137)
{
	std::cout << GREEN << "ShrubberyCreationForm: " << "Sign grade: " << 145 << " Exec grade: " << 137 << RESET << "\n";
}

const char*	ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "ShrubberyCreationForm: Couldn't open file\n";
}

void	ShrubberyCreationForm::actualExecute(const Bureaucrat& executor)
{
	AForm::execute(executor);
	std::ofstream	file;
	const std::string name = this->m_target + "_shrubbery";
	file.open(name.c_str());
	if (file.is_open() == false)
	{
		throw ShrubberyCreationForm::FileOpenException();
	}

	// printing the trees
	file << "               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << "\n";
}
