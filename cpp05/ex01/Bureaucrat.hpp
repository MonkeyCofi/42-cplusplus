/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:13:54 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/19 16:07:54 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class	Form;

class	Bureaucrat
{
	private:
		const std::string	m_name;
		int					m_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);

		~Bureaucrat();
		
		Bureaucrat(const Bureaucrat &obj);
		Bureaucrat &operator=(const Bureaucrat &obj);
		
		std::string	getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		
		void		signForm(Form& form);

		class	GradeTooHighException
		{
			public:
				const char* what();
		};
		
		class	GradeTooLowException
		{
			public:
				const char*	what();
		};
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& b);

#endif