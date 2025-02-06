/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:44:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/20 18:07:49 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define RESET "\e[0m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RED "\e[0;31m"
# define CYAN "\e[0;36m"

class	Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		~Brain();
		Brain(const Brain &obj);
		Brain	&operator=(const Brain &obj);
		Brain	*returnBrainAddress();
};

#endif