/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:03:05 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/17 20:37:47 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractPoint = 8; 

Fixed::Fixed(Fixed &obj)
{
	std::cout << "Copy constructor has been called" << std::endl;
	this->fixedPoint = obj.fixedPoint;
};

Fixed::Fixed(const int toFixed)
{
	std::cout << "Constructor to convert an integer was called" << std::endl;
	this->fixedPoint = (int)toFixed << this->fractPoint;
};

Fixed::Fixed(const float toFixed)
{
	std::cout << "Constructor to convert a float was called" << std::endl;
	this->fixedPoint = roundf(toFixed * (1 << this->fractPoint));
};

Fixed::Fixed()
{
	std::cout << "Default constructor has been called" << std::endl;
	this->fixedPoint = 0;
};

Fixed 	&Fixed::operator=(Fixed const &obj)
{
	std::cout << "Copy assignment operator has been called" << std::endl;
	this->fixedPoint = obj.getRawBits();
	return *this;
};

Fixed::~Fixed()
{
	std::cout << "Destructor has been called" << std::endl;
};

int		Fixed::getRawBits(void) const
{
	return (this->fixedPoint);
};

void	Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
};

float 	Fixed::toFloat(void) const
{
	return ((float)this->fixedPoint / (1 << this->fractPoint));
};

int 	Fixed::toInt(void) const
{
	return (getRawBits() >> 8);
};

/* Comparison and relational operations */
std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
	os << obj.toFloat();
	return os;
};

bool	Fixed::operator==(const Fixed &obj)
{
	return (this->getRawBits() == obj.getRawBits());
};

bool	Fixed::operator!=(const Fixed &obj)
{
	return (!(this->getRawBits() == obj.getRawBits()));
};

int		Fixed::operator+(const Fixed &obj)
{
	return (this->getRawBits() + obj.getRawBits());
};

int		Fixed::operator*(const Fixed &obj)
{
	float	a = this->getRawBits() ;
	float	b;
};

/* Increment and decrement operators */
Fixed	&Fixed::operator++(void)
{
	++this->fixedPoint;
	return (*this);
};

Fixed	&Fixed::operator++(int)
{
	this->fixedPoint++;
	return (*this);
};
