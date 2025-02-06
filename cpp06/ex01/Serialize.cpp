/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:44:46 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/26 18:19:32 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"

Serialize::Serialize()
{
	;
}

Serialize::~Serialize()
{
	;
}

Serialize::Serialize(const Serialize& obj)
{
	(void)obj;
}

Serialize	&Serialize::operator=(const Serialize& obj)
{
	(void)obj;
	return (*this);
}

uintptr_t Serialize::serialize(Data* ptr)
{
	uintptr_t	ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
};

Data* Serialize::deserialize(uintptr_t raw)
{
	Data	*data = reinterpret_cast<Data*>(raw);
	return (data);
};