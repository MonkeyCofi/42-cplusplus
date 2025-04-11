/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 06:13:54 by pipolint          #+#    #+#             */
/*   Updated: 2025/04/08 13:10:47 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class	AForm;

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
		
		void		signForm(AForm& form);
		void		executeForm(AForm& form);

		class	GradeTooHighException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		
		class	GradeTooLowException: public std::exception
		{
			public:
				const char*	what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& stream, const Bureaucrat& b);

#endif