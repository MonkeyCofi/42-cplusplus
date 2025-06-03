/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:31:23 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/22 15:33:04 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include "Bureaucrat.hpp"
# include <fstream>

class	ShrubberyCreationForm: public AForm
{
	private:
		ShrubberyCreationForm();
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
		
		ShrubberyCreationForm(std::string target);
		void	actualExecute(Bureaucrat const& executor);
		class	FileOpenException: public std::exception
		{
			public:
				const char*	what() const throw();
		};
};


#endif
