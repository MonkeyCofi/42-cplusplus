/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:28:44 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/19 21:02:33 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <iomanip>

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

		static char	toChar(std::string arg);
		static void	printChar(std::string arg, e_types type);
		
	public:
		static void convert(std::string to_convert);
		class	NonCharException
		{
			public:
				const char*	what();
		};
};

#endif