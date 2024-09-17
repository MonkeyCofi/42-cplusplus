/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 16:35:35 by pipolint          #+#    #+#             */
/*   Updated: 2024/08/31 14:18:46 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string name;
		Weapon	*weap;
	public:
		HumanB(std::string name);
		HumanB(Weapon *weap, std::string name);
		~HumanB();
		void	attack();
		void	pickWeapon(Weapon *weap);
};

#endif