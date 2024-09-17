/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:27:51 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/17 19:56:56 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		const static int	fractPoint;
		int					fixedPoint;
	public:
		Fixed(Fixed &obj);
		Fixed(const int toFixed);
		Fixed(const float toFixed);
		Fixed();
		~Fixed();
		
		/* Operator overloads */
		Fixed	&operator=(const Fixed &obj);
		bool	operator==(const Fixed &obj);
		bool	operator!= (const Fixed &obj);
		//bool	operator> (const Fixed &obj1, const Fixed &obj2);
		//bool	operator< (const Fixed &obj1, const Fixed &obj2);
		//bool	operator<= (const Fixed &obj1, const Fixed &obj2);
		//bool	operator>= (const Fixed &obj1, const Fixed &obj2);
		
		/* Arithmetic overloads */
		int		operator+(const Fixed &obj);
		int		operator*(const Fixed &obj);
		//void	operator-(const Fixed &obj);
		//void	operator/(const Fixed &obj);
		
		/* Increment overloads */
		Fixed	&operator++(void);
		Fixed	&operator++(int);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		float 	toFloat(void) const;
		int 	toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif