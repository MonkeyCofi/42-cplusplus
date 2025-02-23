/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:11:21 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/23 20:23:07 by pipolint         ###   ########.fr       */
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
