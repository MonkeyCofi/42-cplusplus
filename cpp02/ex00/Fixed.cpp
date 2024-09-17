/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:03:05 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/02 20:46:01 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractPoint = 8;

Fixed::Fixed(Fixed &obj)
{
	std::cout << "Copy constructor has been called" << std::endl;
	this->fixedPoint = obj.fixedPoint;
};
Fixed::Fixed()
{
	std::cout << "Default constructor has been called" << std::endl;
	this->fixedPoint = 0;
};

Fixed &Fixed::operator=(Fixed const &obj)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	this->fixedPoint = obj.fixedPoint;
	return *this;
};

Fixed::~Fixed()
{
	std::cout << "Destructor has been called" << std::endl;
};

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits() has been called" << std::endl;
	return (this->fixedPoint);
};
void	Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
};