/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:06:07 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/08 17:40:30 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	private:
		std::string Name;
	public:
		FragTrap();
		~FragTrap();
		FragTrap(std::string Name);
		FragTrap(const FragTrap &obj);
		FragTrap &operator=(const FragTrap &obj);
		void	highFivesGuys(void);
};

#endif
