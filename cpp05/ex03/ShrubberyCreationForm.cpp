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

ShrubberyCreationForm::ShrubberyCreationForm(): Form("shrubbery creation", "None", 145, 137)
{
	;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\033[31mDestructor for ShrubberyCreationForm " \
		<< this->getName() << " was called\n\033[0m";
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj): Form(obj)
{
	;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	(void)obj;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("shrubbery creation", target, 145, 137)
{
	;
}

const char*	ShrubberyCreationForm::FileOpenException::what()
{
	return "ShrubberyCreationForm: Couldn't open file\n";
}

void	ShrubberyCreationForm::actualExecute(const Bureaucrat& executor)
{
	Form::execute(executor);
	std::ofstream	file;
	std::string	fileName = this->m_target;
	fileName.append("_shrubbery");
	file.open(fileName.c_str());
	if (file.is_open() == false)
	{
		throw ShrubberyCreationForm::FileOpenException();
	}
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
