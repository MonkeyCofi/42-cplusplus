/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:27:51 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/19 15:03:52 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RESET "\e[0m"
# define BLUE "\e[0;34m"
# define GREEN "\e[0;32m"
# define YELLOW "\e[1;33m"
# define RED "\e[0;31m"
# define CYAN "\e[0;36m"

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
		bool	operator< (const Fixed &obj);
		bool	operator> (const Fixed &obj);
		bool	operator<= (const Fixed &obj);
		bool	operator>= (const Fixed &obj);
		
		/* Arithmetic overloads */
		float	operator+(const Fixed &obj);
		float	operator*(const Fixed &obj);
		float	operator/(const Fixed &obj);
		float	operator-(const Fixed &obj);
		
		/* Increment overloads */
		Fixed	&operator++(void);
		Fixed	operator++(int);
		
		/* Decrement overloads */
		Fixed	&operator--(void);
		Fixed	operator--(int);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
		float 	toFloat(void) const;
		int 	toInt(void) const;
		
		static Fixed &min(Fixed &obj1, Fixed &obj2);
		static Fixed &max(Fixed &obj1, Fixed &obj2);
		static const Fixed &min(Fixed const &obj1, Fixed const &obj2);
		static const Fixed &max(Fixed const &obj1, Fixed const &obj2);
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);

#endif