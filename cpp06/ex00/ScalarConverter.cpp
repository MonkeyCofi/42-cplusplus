/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:17:37 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/18 20:07:50 by pipolint         ###   ########.fr       */
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
	if (arg.length() == 1)
	{
		if (static_cast<unsigned char>(arg.at(0)) > 127)
			return (false);
		return (true);
	}
	return (false);
}

char	ScalarConverter::toChar(std::string arg)
{
	char c = std::atoi(arg.c_str());
	return (c);
}

std::string	getType(std::string arg)
{
	if (isChar(arg)) return ("Char");
	if (isInt(arg)) return ("Int");
	if (isDouble(arg)) return ("Double");
	return ("Float");
}

void	ScalarConverter::printChar(char c) const
{
	if (c <= 31)
		return ;
	std::cout << 
}

void	ScalarConverter::convert(std::string arg)
{
	const std::string	types[4] = {"Char", "Int", "Float", "Double"};
	std::string	type = getType(arg);
	int	t = 0;
	for (; t < 4; t++)
	{
		if (type == types[t])
			break ;
	}
	switch(t)
	{
		case(Char):
		{
			std::cout << "Char: " << arg << "\n";
			std::cout << "Int: " << static_cast<int>(arg.at(0)) << "\n";
			std::cout << "Float: " << static_cast<float>(arg.at(0)) << "\n";
			std::cout << "Float: " << static_cast<double>(arg.at(0)) << "\n";
			return ;
		}
		case(Int):
		{
			std::cout << "Char: " << static_cast<unsigned char>(std::atoi(arg.c_str())) << "\n";
			std::cout << "Int: " << std::atoi(arg.c_str()) << "\n";
			std::cout << "Float: " << static_cast<float>(std::atoi(arg.c_str())) << "\n";
			std::cout << "Double: " << static_cast<double>(std::atoi(arg.c_str())) << "\n";
			return ;
		}
	}
}