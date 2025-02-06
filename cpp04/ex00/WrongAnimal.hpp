/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 13:14:59 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/19 16:14:57 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

# define RESET "\e[0m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RED "\e[0;31m"
# define CYAN "\e[0;36m"

class	WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(std::string Type);
		WrongAnimal(const WrongAnimal &obj);
		WrongAnimal	&operator=(const WrongAnimal &obj);
		std::string		getType();
		void	makeSound();
};

#endif