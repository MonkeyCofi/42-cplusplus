/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:50:29 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/07 18:14:47 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>
# include <iomanip>

# define RESET "\e[0m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RED "\e[0;31m"
# define CYAN "\e[0;36m"

class ClapTrap
{
	private:
		std::string Name;
	protected:
		int			hit_points;
		int			energy_points;
		int			attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap &ref);
		ClapTrap 	&operator=(ClapTrap const &obj);
		ClapTrap(std::string Name, int hit_points, int energy_points, int attack_damage);
	
		std::string			getName();
		virtual void		attack(const std::string &target);
		int					getDamage();
		int					getHitPoints();
		void				setName(std::string name);
		void				takeDamage(unsigned int amount);
		void				beRepaired(unsigned int amount);
		int					getEnergyPoints();
		void				printStats();
};

#endif