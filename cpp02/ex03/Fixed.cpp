/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 18:03:05 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/19 15:06:02 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::fractPoint = 8; 

Fixed::Fixed(Fixed &obj)
{
	std::cout << YELLOW <<  "Copy constructor has been called" << RESET << std::endl;
	this->fixedPoint = obj.fixedPoint;
};

Fixed::Fixed(const int toFixed)
{
	std::cout << CYAN << "Paramterized(integer) constructor was called" << RESET << std::endl;
	this->fixedPoint = (int)toFixed << this->fractPoint;
};

Fixed::Fixed(const float toFixed)
{
	std::cout << CYAN << "Paramterized(Float) constructor was called" << RESET << std::endl;
	this->fixedPoint = roundf(toFixed * (1 << this->fractPoint));
};

Fixed::Fixed()
{
	std::cout << BLUE << "Default constructor has been called" << RESET << std::endl;
	this->fixedPoint = 0;
};

Fixed 	&Fixed::operator=(Fixed const &obj)
{
	std::cout << YELLOW << "Copy assignment operator has been called" << RESET << std::endl;
	this->fixedPoint = obj.getRawBits();
	return *this;
};

Fixed::~Fixed()
{
	std::cout << RED << "Destructor has been called" << RESET << std::endl;
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
	return (this->toFloat() == obj.toFloat());
};

bool	Fixed::operator<(const Fixed &obj)
{
	return (this->toFloat() < obj.toFloat());
};

bool	Fixed::operator>(const Fixed &obj)
{
	return (this->toFloat() > obj.toFloat());
};

bool	Fixed::operator<=(const Fixed &obj)
{
	return (this->toFloat() <= obj.toFloat());
};

bool	Fixed::operator>=(const Fixed &obj)
{
	return (this->toFloat() >= obj.toFloat());
};

bool	Fixed::operator!=(const Fixed &obj)
{
	return (!(this->toFloat() == obj.toFloat()));
};

float		Fixed::operator+(const Fixed &obj)
{
	return (this->toFloat() + obj.toFloat());
};

float		Fixed::operator-(const Fixed &obj)
{
	return (this->toFloat() - obj.toFloat());
};

float		Fixed::operator*(const Fixed &obj)
{
	return (this->toFloat() * obj.toFloat());
};

float		Fixed::operator/(const Fixed &obj)
{
	return (this->toFloat() / obj.toFloat());
};

/* Increment and decrement operators */
Fixed	&Fixed::operator++(void)
{
	++this->fixedPoint;
	return (*this);
};

Fixed	Fixed::operator++(int)
{
	Fixed obj(*this);
	++this->fixedPoint;
	return (obj);
};

Fixed	&Fixed::operator--(void)
{
	--this->fixedPoint;
	return (*this);
};

Fixed	Fixed::operator--(int)
{
	Fixed obj(*this);
	--this->fixedPoint;
	return (obj);
};

Fixed	&Fixed::min(Fixed &obj1, Fixed &obj2)
{
	if (obj1 <= obj2)
		return (obj1);
	return (obj2);
}

Fixed	&Fixed::max(Fixed &obj1, Fixed &obj2)
{
	if (obj1 >= obj2)
		return (obj1);
	return (obj2);
}

const Fixed	&Fixed::min(Fixed const &obj1, Fixed const &obj2)
{
	if (obj1.toFloat() <= obj2.toFloat())
		return (obj1);
	return (obj2);
}


const Fixed	&Fixed::max(const Fixed &obj1, const Fixed &obj2)
{
	if (obj1.toFloat() >= obj2.toFloat())
		return (obj1);
	return (obj2);
}