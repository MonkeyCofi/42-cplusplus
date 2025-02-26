/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:58:33 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/26 16:11:17 by pipolint         ###   ########.fr       */
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

class	BTC
{
	private:
		std::ifstream					input_file;
		std::ifstream					database_file;
		std::map<std::string, double>	database;

		void	fillDatabase();
		bool	isValidYear(std::string year) const;	// will be used to check the years in the input file
		bool	isValidValue(std::string value) const;
	public:
		BTC();
		~BTC();
		BTC(const BTC& obj);
		BTC	&operator=(const BTC& obj);
		
		void	open_btc_database();
		bool	open_input_database(const char *const cl_arg, std::string& err_str);
		bool	parseInputDatabase(std::string& err_str);
		
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
};

#endif