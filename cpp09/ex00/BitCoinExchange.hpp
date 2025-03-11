/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:58:33 by pipolint          #+#    #+#             */
/*   Updated: 2025/03/11 15:22:50 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <cstdlib>
# include <algorithm>
# include <cstdarg>

class	BTC
{
	private:
		std::ifstream					input_file;
		std::ifstream					database_file;
		std::map<std::string, double>	database;

		enum	e_varTypes
		{
			string,
			integer
		};

		void		fillDatabase();
		bool		isValidYear(std::string year) const;	// will be used to check the years in the input file
		bool		isValidValue(double value) const;
		std::string	getYear(std::string line) const;
		std::string	getValue(std::string line) const;
	public:
		BTC();
		~BTC();
		BTC(const BTC& obj);
		BTC	&operator=(const BTC& obj);
		
		void		open_btc_database();
		void		open_input_database(const char *const cl_arg);
		std::string	validateLine(std::string& line);
		void		returnDatabaseFromInput();

		class	BtcDataBaseException
		{
			public:
				const char*	what();
		};
		class	InputDataBaseException
		{
			public:
				const char*	what();
		};
		class	InvalidDatabaseHeader
		{
			public:
				const char*	what();
		};
		class	BadInputException
		{
			public:
				const char*	what();
		};
};

#endif