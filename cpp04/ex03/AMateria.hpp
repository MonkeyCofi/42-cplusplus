/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:20:44 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/23 18:24:49 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <iomanip>
# include "ICharacter.hpp"
# include "colors.hpp"

class	ICharacter;

class	AMateria
{
	protected:
		std::string m_type;
		AMateria();
	public:
		AMateria(std::string const &type);
		virtual ~AMateria();
		virtual const std::string 	&getType() const;
		virtual AMateria			*clone() const = 0;
		virtual void				use(ICharacter &target);
		const AMateria				*returnMateria() const;
};

#endif
