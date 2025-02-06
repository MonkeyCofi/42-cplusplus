/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:17:37 by pipolint          #+#    #+#             */
/*   Updated: 2024/12/26 17:07:57 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
	;
};

ScalarConverter::~ScalarConverter()
{

};

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& obj)
{
	(void)obj;
	return (*this);
}

static bool	isFloat(std::string arg)
{
	float	resFloat = std::atof(arg.c_str());
	double	resDouble = std::atof(arg.c_str());
	if (std::fabs(resDouble - resFloat) < std::numeric_limits<float>::epsilon())
		return (false);
	return (true);
}

static bool	isDouble(std::string arg)
{
	if (isFloat(arg) == true)
		return (false);
	return (true);
};

static bool	isInt(std::string arg)
{
	int i = 0;
	if (arg[i] == '-')
		i++;
	for (; arg[i]; i++)
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (false);
	}
	return (true);
}

static bool	isChar(std::string arg)
{
	for (int i = 0; arg[i]; i++)
	{
		if (arg[i] >= 127 && arg[i] <= 0)
			return (false);
	}
	return (true);
}

//int	convertInt(std::string arg)
//{
//	int	res = 0;
//	int i = 0;
//	int	negative = (-2 * (arg[i] == '-')) + 1;
//	for (; arg[i]; i++)
//	{
//		if (arg[i] >= '0' && arg[i] <= '9')
//			res = (arg[i] - '0') + (res * 10);
//	}
//	return (res *= negative);
//}

//float	convertFloat(std::string arg)
//{
//	float res = std::atof(arg.c_str());
//	return (res);
//}

//void	ScalarConverter::convert(std::string to_convert)
//{
//	std::string types[4] = {"float", "double", "char", "int"};
//	bool	(*typesFunc[4])(std::string) = {isDouble, isDouble, isChar, isInt};
//	bool	stats[4] = {false, false, false, false};
//	int	type = 0;
//	for (; type < 4; type++)
//	{
//		if (typesFunc[type](to_convert) == true)
//		{
//			stats[type] = true;
//			break ;
//		}
//	}
//	for (int i = 0; i < 4; i++)
//		std::cout << stats[i] << "\n";
//};

std::string	getType(std::string arg)
{

}

void	ScalarConverter::convert(std::string arg)
{
	// check the type
}