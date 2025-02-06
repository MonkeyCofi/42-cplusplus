/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 21:08:02 by pipolint          #+#    #+#             */
/*   Updated: 2024/09/25 21:14:27 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	;
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	;
};

Point::~Point()
{
	std::cout << RED << "Destructor for Point class was called" << RESET << std::endl;
}

//Point::Point(const Point &obj) : x(obj.x), y(obj.y)
//{
//	;
//}