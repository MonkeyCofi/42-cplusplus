/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:27:51 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/02 14:59:06 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		const static int	fractPoint;
		int					fixedPoint;
	public:
		Fixed(Fixed &obj);
		Fixed();
		~Fixed();
		Fixed &operator=(Fixed const &obj);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);	
};

#endif