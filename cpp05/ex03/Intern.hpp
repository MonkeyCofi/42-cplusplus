/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:43:50 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/23 18:53:47 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "Form.hpp"
//# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern&	operator=(const Intern& obj);

		Form*	makeForm(std::string form_name, std::string form_target);
		Form*	makePardonForm(std::string form_target);
		Form*	makeRobotomyForm(std::string form_target);
		Form*	makeShrubberyCreationForm(std::string form_target);
};

#endif