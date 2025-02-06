/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:14:48 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/26 18:23:07 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <stdint.h>
# include "Data.hpp"
# include <iostream>

class	Serialize
{
	private:
		Serialize();
		~Serialize();
		Serialize(const Serialize& obj);
		Serialize	&operator=(const Serialize& obj);
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif