/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppolinta <ppolinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:11:21 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/25 13:11:35 by ppolinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

BTC::BTC()
{
	;
}

BTC::~BTC()
{
	;
}
BTC::BTC(const BTC& obj)
{
	(void)obj;
}

BTC	&BTC::operator=(const BTC& obj)
{
	(void)obj;
	return (*this);
}

void	BTC::open_btc_database()
{
	this->database_file.open("data.csv", std::ifstream::in);
	if (this->database_file.is_open() == false)
	{
		throw (BTC::BtcDataBaseException());
	}
}

void	BTC::fillDatabase()
{
	std::string	line;
	
	while (std::getline(this->database_file, line))
	{
		if (line == "date,exhange_rate" || line.empty())
			continue ;
		std::string	key = line.substr(0, line.find_first_of(','));
		double		value = static_cast<double>(std::atof(line.substr(line.find_first_of(',') + 1, std::string::npos).c_str()));
		std::pair<std::string, double>	key_value;
		this->database.insert(key_value);
	}
}

void	BTC::open_input_database(const char *const cl_arg)
{
	this->input_file.open(cl_arg, std::ifstream::in);
	if (this->input_file.is_open() == false)
	{
		throw (BTC::InputDataBaseException());
	}
}

const char*	BTC::InputDataBaseException::what()
{
	return ("Database file: Could not open input database file");
}

const char*	BTC::BtcDataBaseException::what()
{
	return ("Database file: Could not open BTC database file");
}
