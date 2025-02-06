/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:34:59 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/23 12:53:27 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	AForm
{
	private:
		const std::string	m_name;
		bool				m_signed;
		const int			m_sign_grade;
		const int			m_exec_grade;
	protected:
		const std::string	m_target;
	public:
		AForm();
		AForm(const AForm& form);
		AForm(std::string name, std::string target, int sign_grade, int exec_grade);
		virtual ~AForm();

		const std::string	getName() const;
		const std::string	getTarget() const;
		bool				getSigned() const;
		int					getSignGrade() const;
		int					getExecGrade() const;

		virtual void		beSigned(Bureaucrat& b);
		void				execute(Bureaucrat const& executor) const;
		virtual void		actualExecute(const Bureaucrat& executor) = 0;
		
		class	GradeTooHighException
		{
			public:
				const char*	what();
		};
		class	GradeTooLowException
		{
			public:
				const char*	what();
		};
		class	UnsignedFormException
		{
			public:
				const char*	what();
		};
		class	GradeTooLowExecException
		{
			public:
				const char*	what();
		};
};

std::ostream&	operator<<(std::ostream& os, const AForm& obj);

#endif