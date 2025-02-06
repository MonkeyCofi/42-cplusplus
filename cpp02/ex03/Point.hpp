/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:06:30 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/25 21:09:14 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class	Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point();
		Point(const float x, const float y);
		~Point();
		Point(const Point &obj);
		Point &operator=(const Point &obj);
};

#endif