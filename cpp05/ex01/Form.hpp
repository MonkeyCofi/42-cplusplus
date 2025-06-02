/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:34:59 by pipolint          #+#    #+#             */
/*   Updated: 2025/04/08 13:10:35 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

# define RED "\033[31m"
# define RESET "\033[0m"
# define GREEN "\033[32m"

class	Form
{
	private:
		const std::string	m_name;
		bool				m_signed;
		const int			m_sign_grade;
		const int			m_exec_grade;
	public:
		Form();
		~Form();
		Form(const Form& obj);
		Form	operator=(const Form& obj);
		
		Form(std::string name, int sign_grade, int exec_grade);

		const std::string	getName() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		void				beSigned(Bureaucrat& b);
		
		class	GradeTooHighException: public std::exception
		{
			public:
				const char*	what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif