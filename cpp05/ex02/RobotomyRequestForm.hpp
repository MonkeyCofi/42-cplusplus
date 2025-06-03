/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:38:58 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/22 15:26:45 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <ctime>
# include <random>

class	RobotomyRequestForm: public AForm
{
	private:
		RobotomyRequestForm();
	public:
		~RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);
		
		RobotomyRequestForm(std::string target);
		void	actualExecute(Bureaucrat const& executor);
};

#endif