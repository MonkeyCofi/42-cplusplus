/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:17:37 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/19 17:32:21 by pipolint         ###   ########.fr       */
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
	bool	negative = arg.find_first_of('-') != std::string::npos;

	if (arg.find_first_of('.') == std::string::npos || arg.find_first_of('.') != arg.find_last_of('.') \
		|| (negative && (arg.find_first_of('-') != arg.find_last_of('-'))) || (negative && \
			arg.find('-') != 0))
		return (false);
	if (arg.find_first_not_of("0123456789.") != std::string::npos)
	{
		if ((*(arg.end() - 1)) == 'f')
			return (true);
		return (negative ? true : false);
	}
	return (true);
}

static bool	isDouble(std::string arg)
{
	float	fl_arg;
	double	dbl_arg;
	const double	epsilon = 0.00001;

	if (isFloat(arg) == true)
	{
		fl_arg = std::atof(arg.c_str());
		dbl_arg = std::atof(arg.c_str());
		if (std::fabs(fl_arg - dbl_arg) > epsilon)
			return (false);
		return (true);
	}
	return (false);
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
	if (isInt(arg)) return ("Int");
	if (isFloat(arg)) return ("Float");
	if (isDouble(arg)) return ("Double");
	if (isChar(arg)) return ("Char");
	return ("Invalid");
}

void	ScalarConverter::printChar(std::string arg, ScalarConverter::e_types type)
{
	char	c;

	if (type != Char)
		c = static_cast<char>(std::atoi(arg.c_str()));
	else
		c = arg.at(0);
	if (c <= 31)
	{
		std::cout << "Char: " << "Non-printable\n";
		return ;
	}
	std::cout << "Char: " << c << "\n"; 
}

void	ScalarConverter::convert(std::string arg)
{
	const std::string	types[5] = {"Char", "Int", "Float", "Double", "Invalid"};
	std::string	type = getType(arg);
	int	t = 0;
	for (; t < 5; t++)
	{
		if (type == types[t])
			break ;
	}
	std::cout << "Type: " << types[t] << "\n";
	switch(t)
	{
		case(Char):
		{
			const char	c = arg.at(0);

			printChar(arg, static_cast<e_types>(t));
			std::cout << "Int: " << static_cast<int>(c) << "\n";
			std::cout << "Float: " << static_cast<float>(c) << ".0f" << "\n";
			std::cout << "Double: " << static_cast<double>(c) << ".0" << "\n";
			return ;
		}
		case(Int):
		{
			const int	res = std::atoi(arg.c_str());

			printChar(arg, static_cast<e_types>(t));
			std::cout << "Int: " << res << "\n";
			std::cout << "Float: " << static_cast<float>(res) << ".0f" << "\n";
			std::cout << "Double: " << static_cast<double>(res) << ".0" << "\n";
			return ;
		}
		case(Float):
		{
			const float	res = std::atof(arg.c_str());

			printChar(arg, static_cast<e_types>(t));
			std::cout << "Int: " << static_cast<int>(res) << "\n";
			std::cout << "Float: " << res << "f" << "\n";
			std::cout << "Double: " << static_cast<double>(res) << "\n";
			return ;
		}
		case(Double):
		{
			const double	res = std::atof(arg.c_str());

			printChar(arg, static_cast<e_types>(t));
			std::cout << "Int: " << static_cast<int>(res) << "\n";
			std::cout << "Float: " << static_cast<float>(res) << "f" << "\n";
			std::cout << "Double: " << res << "\n";
			return ;
		}
		case(Invalid):
		{
			std::cout << "Char: " << "impossible\n";
			std::cout << "Int: " << "impossible\n";
			std::cout << "Float: " << "nanf\n";
			std::cout << "Double: " << "nan\n";
		}
	}
}