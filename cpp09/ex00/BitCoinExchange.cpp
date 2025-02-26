/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:11:21 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/26 19:15:39 by pipolint         ###   ########.fr       */
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

bool	BTC::isValidYear(std::string year) const
{
	if (std::count<std::string::iterator, char>(year.begin(), year.end(), '-') != 2)
	{
		std::cout << "Returning false\n";
		return (false);
	}
	return (year.find_first_not_of("0123456789-") == std::string::npos);
}

bool	BTC::isValidValue(std::string value) const
{
	if (value.find_first_not_of("-0123456789.") != std::string::npos || \
		std::count(value.begin(), value.end(), '.') > 1 || std::count(value.begin(), value.end(), '-') > 1)
			return (false);
	return (true);
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
		std::pair<std::string, double>	key_value(key, value);
		this->database.insert(key_value);
	}
}

bool	BTC::open_input_database(const char *const cl_arg, std::string& err_str)
{
	this->input_file.open(cl_arg, std::ifstream::in);
	if (this->input_file.is_open() == false)
	{
		throw (BTC::InputDataBaseException());
	}
	this->fillDatabase();
	return (this->parseInputDatabase(err_str));
}

bool	BTC::parseInputDatabase(std::string& err_str)
{
	std::string	line;
	std::string	year;
	std::string	value;
	int			line_count = 0;

	std::getline(this->input_file, line);
	if (line != "date | value")
		return (false);
	line_count++;
	while (std::getline(this->input_file, line))
	{
		if (line.find_first_of(" \t") < line.find_first_not_of(" \t"))
			line.erase(line.find_first_of(" \t"), line.find_first_not_of(" \t"));
		year = line.substr(0, line.find_first_of(' '));
		value = line.substr(line.find_first_of("|"), std::string::npos).substr(value.find_first_not_of("| \t"), std::string::npos);
		//value = value.substr(value.find_first_not_of("| \t"), std::string::npos);
		line_count++;
		std::cout << "value:" << value << "\n";
		if (!isValidYear(year) || !isValidValue(value))
		{
			std::ostringstream	str_stream(err_str);
			str_stream << "Error at line: " << line_count << "\nLine: " << line;
			err_str = str_stream.str();
			return (false);
		}
	}
	return (true);
}

const char*	BTC::InputDataBaseException::what()
{
	return ("Database file: Could not open input database file");
}

const char*	BTC::BtcDataBaseException::what()
{
	return ("Database file: Could not open BTC database file");
}

const char*	BTC::InvalidDatabaseHeader::what()
{
	return ("The input database has invalid header fields");
}