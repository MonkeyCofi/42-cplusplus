/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:28:44 by pipolint          #+#    #+#             */
/*   Updated: 2025/06/04 02:06:24 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>
# include <climits>
# include <exception>

class	ScalarConverter
{
	private:
		enum	e_types
		{
			Char,
			Int,
			Float,
			Double,
			Invalid
		};
		
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		ScalarConverter	&operator=(const ScalarConverter &obj);


		static char			toChar(std::string arg);
		static void			printChar(std::string arg, e_types type);
		
		static std::string	getType(std::string arg);

		static bool			isFloat(std::string arg);
		static bool			isDouble(std::string arg);
		static bool			isInt(std::string arg);
		static bool			isChar(std::string arg);
		
		static bool			checkDecimal(double arg);
		class	NotATypeException: public std::exception
		{
			public:
				const char* what() const throw();
		};
		class	IntOverflowException: public std::exception
		{
			public:
				const char* what() const throw();
		};
	public:
		static void convert(std::string to_convert);
};

#endif