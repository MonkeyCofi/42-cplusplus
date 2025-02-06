/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:41:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/21 14:17:31 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

# define RESET "\e[0m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RED "\e[0;31m"
# define CYAN "\e[0;36m"

class	Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal(std::string type);
		Animal(const Animal &obj);
		virtual void	makeSound();
		std::string		getType() const;
		void			setType(std::string NewType);
		Animal			&operator=(const Animal &obj);
		virtual Brain	*brainAddress();
};

#endif