/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 17:41:49 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/26 18:14:42 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	num = 42;
};

Data::~Data()
{
	;
}

Data::Data(const Data& obj)
{
	this->num = obj.num;
}

Data	&Data::operator=(const Data& obj)
{
	this->num = obj.num;
	return (*this);
}

int	Data::getNum() const
{
	return (this->num);
}
