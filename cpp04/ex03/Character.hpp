/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:09:43 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/23 20:00:27 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character: public ICharacter
{
	private:
		bool			m_full;
		std::string		m_name;
		AMateria 		**m_inventory;
		static AMateria	*m_last_dropped;
	public:
		Character();
		~Character();
		Character(std::string const &name);
		Character(const Character &obj);
		Character &operator=(const Character &obj);
		void 				use(int idx, ICharacter& target);
		void				equip(AMateria *m);
		void				unequip(int idx);
		static void			deleteLastDropped();
		const std::string	&getName() const;
};

#endif