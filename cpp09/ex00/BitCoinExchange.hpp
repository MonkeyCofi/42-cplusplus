/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:58:33 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/25 13:01:01 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <sstream>
# include <cstdlib>

class	BTC
{
	private:
		std::ifstream					input_file;
		std::ifstream					database_file;
		std::map<std::string, double>	database;
	public:
		BTC();
		~BTC();
		BTC(const BTC& obj);
		BTC	&operator=(const BTC& obj);
		
		void	open_btc_database();
		void	open_input_database(const char* const cl_arg);
		void	fillDatabase();
		
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
};

#endif