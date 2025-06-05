/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 11:17:37 by pipolint          #+#    #+#             */
/*   Updated: 2025/06/04 03:13:11 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() 
{
	;
};

ScalarConverter::~ScalarConverter()
{
	;
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
	(void)obj;
}

ScalarConverter	&ScalarConverter::operator=(const ScalarConverter& obj)
{
	(void)obj;
	return (*this);
}

bool	ScalarConverter::isFloat(std::string arg)
{
	const bool	has_f = (*(arg.end() - 1) == 'f') || (*(arg.end() - 1) == 'F');
	if (!has_f || (atof(arg.c_str()) == 0 && arg != "0"))
		return (false);
	if (arg == "inff" || arg == "-inff")	// for infinity
		return (true);
	if (arg.find_first_of('f') != arg.find_last_of('f') || arg.find_first_of('F') != arg.find_last_of('F'))
		throw (ScalarConverter::NotATypeException());

	const bool	is_scientific = arg.find_first_of('e');
	const bool	negative_exponent = (arg[arg.find_first_of('e') + 1]) == '-';
	arg = !negative_exponent ? arg : arg.erase(arg.find_first_of('e') + 1, 1);

	const bool	negative = arg.find_first_of('-') != std::string::npos;
	const bool	has_digit = arg.find_first_of("0123456789") != std::string::npos;

	if (arg.find_first_of('.') != arg.find_last_of('.') \
		|| (negative && (arg.find_first_of('-') != arg.find_last_of('-'))) 
			|| !has_digit || (is_scientific && arg.find_first_of('e') != arg.find_last_of('e')))
				return (false);
	return (true);
}

bool	ScalarConverter::isDouble(std::string arg)
{
	if (arg == "inf" || arg == "-inf")
		return (true);
	if ((atof(arg.c_str()) == 0 && arg != "0") || arg.find_first_not_of("0123456789-+.e") != std::string::npos)
		throw (ScalarConverter::NotATypeException());

	const bool	is_scientific = arg.find_first_of('e');
	const bool	negative = arg.find_first_of('-') != std::string::npos;
	const bool	has_digit = arg.find_first_of("0123456789") != std::string::npos;
	const bool	negative_exponent = (arg[arg.find_first_of('e') + 1]) == '-';
	if (negative_exponent)
		arg.erase(arg.find_first_of('e') + 1, 1);

	if (arg.find_first_of('.') != arg.find_last_of('.') \
		|| (negative && (arg.find_first_of('-') != arg.find_last_of('-')))
			|| !has_digit || (is_scientific && arg.find_first_of('e') != arg.find_last_of('e')))
				return (false);
	return (true);
}

bool	ScalarConverter::isInt(std::string arg)
{
	int 	i = 0;
	int 	res = 0;
	bool	negative = false;
	if (arg[i] == '-')
	{
		i++;
		negative = !negative;
	}
	for (; arg[i]; i++)
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (false);
		if ((res == INT_MAX / 10 && arg[i] - '0' > 7) || 
			(negative && res == INT_MAX / 10 && arg[i] - '0' > 8))	// if integer overflows, throw exception
			throw (ScalarConverter::IntOverflowException());
		res = arg[i] - '0' + res * 10;	
	}
	std::cout << "Res: " <<  res << "\n";
	return (true);
}

bool	ScalarConverter::isChar(std::string arg)
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

std::string	ScalarConverter::getType(std::string arg)
{
	arg = arg.erase(0, arg.find_first_not_of(" \t"));	// trim whitespaces in the beginning
	arg = arg.erase(arg.find_last_not_of(" \t") + 1, std::string::npos);	// trim whitespaces in the end
	try
	{
		if (ScalarConverter::isInt(arg)) return ("Int");
		if (ScalarConverter::isFloat(arg)) return ("Float");
		if (ScalarConverter::isDouble(arg)) return ("Double");
		if (ScalarConverter::isChar(arg)) return ("Char");
	}
	catch (std::exception& e)	// catch the two exceptions that are possibly thrown
	{
		return ("Invalid");
	}
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

bool	ScalarConverter::checkDecimal(double arg)
{
	return (static_cast<int>(arg) - static_cast<float>(arg));
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
			bool hasDecimal = checkDecimal(res);
			
			printChar(arg, static_cast<e_types>(t));
			std::cout << "Int: " << static_cast<int>(res) << "\n";
			std::cout << "Float: " << res << (hasDecimal ? "f" : ".0f") << "\n";
			std::cout << "Double: " << static_cast<double>(res) << (hasDecimal ? "" : ".0") << "\n";
			return ;
		}
		case(Double):
		{
			const double	res = std::atof(arg.c_str());
			bool hasDecimal = checkDecimal(res);

			printChar(arg, static_cast<e_types>(t));
			std::cout << "Int: " << static_cast<int>(res) << "\n";
			std::cout << "Float: " << static_cast<float>(res) << (hasDecimal ? "f" : ".0f") << "\n";
			std::cout << "Double: " << res << (hasDecimal ? "" : ".0") << "\n";
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

const char*	ScalarConverter::NotATypeException::what() const throw()
{
	return ("Not a type");
}

const char*	ScalarConverter::IntOverflowException::what() const throw()
{
	return ("Int overflow");
}