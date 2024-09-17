/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:10:48 by pipolint          #+#    #+#             */
/*   Updated: 2024/08/29 10:09:41 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class	Zombie
{
	private:
		std::string name;
	public:
		void	announce(void);
		void	setName(std::string name);
		Zombie();
		Zombie(std::string name);
		~Zombie();
};

Zombie	*zombieHorde(int N, std::string name);

#endif