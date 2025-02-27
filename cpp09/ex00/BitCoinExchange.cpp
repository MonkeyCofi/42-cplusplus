/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitCoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:11:21 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/27 16:46:15 by pipolint         ###   ########.fr       */
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
	std::string	yyyy;
	std::string	mm;
	std::string	dd;

	if (std::count<std::string::iterator, char>(year.begin(), year.end(), '-') != 2)
		return (false);
	yyyy = year.substr(0, year.find_first_of('-'));
	if (yyyy.length() != 4)
	{
		std::cout << "Invalid year\n";
		return (false);
	}
	mm = year.substr(year.find_first_of('-') + 1, (year.find_last_of('-') - year.find_first_of('-')) - 1);
	if (mm.length() != 2 || std::atoi(mm.c_str()) > 12)
	{
		std::cout << "Invalid month\n";
		return (false);
	}
	dd = year.substr(year.find_last_of('-') + 1, std::string::npos);
	if (dd.length() != 2 || std::atoi(dd.c_str()) > 31)
	{
		std::cout << "Invalid day\n";
		return (false);
	}
	return (year.find_first_not_of("0123456789-") == std::string::npos);
}

bool	BTC::isValidValue(std::string value) const
{
	const size_t				hyphen_pos = value.find_first_of('-');
	const std::string::iterator	start = value.begin();
	const std::string::iterator	end = value.end();

	if (value.find_first_not_of("-0123456789.") != std::string::npos || \
		std::count(start, end, '.') > 1 || std::count(start, end, '-') > 1 \
		|| (hyphen_pos != std::string::npos && hyphen_pos > value.find_first_of("0123456789")))
			return (false);
	if (std::atof(value.c_str()) > 1000)
	{
		std::cout << "Value can only be between 0 and 1000\n";
		return (false);
	}
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
	return (this->validateInputDatabase(err_str));
}

std::string	BTC::setErrorString(std::string& errString, unsigned int argCount, BTC::e_varTypes *varTypes, ...) const
{
	std::ostringstream	stream(errString);
	va_list				args;
	va_start(args, varTypes);

	for (unsigned int i = 0; i < argCount; i++)
	{
		switch(varTypes[i])
		{
			case(integer):
			{
				int	i = va_arg(args, int);
				stream << i;
				break ;
			}
			case(string):
			{
				char*	arg = va_arg(args, char *);
				stream << std::string(arg);
				break ;
			}
		}
	}
	va_end(args);
	return (stream.str());
}

std::string	BTC::getYear(std::string line) const
{
	return (line.substr(0, line.find_first_of(' ')));
}

std::string	BTC::getValue(std::string line) const
{
	std::string	value;
	
	value = line.substr(line.find_first_of("|"), std::string::npos);
	return (value.substr(value.find_first_not_of("| \t"), std::string::npos));
}

bool	BTC::validateInputDatabase(std::string& err_str)
{
	std::string	line;
	std::string	year;
	std::string	value;
	int			line_count; 

	std::getline(this->input_file, line);
	line_count = line == "date | value";
	if (line != "date | value")
	{
		BTC::e_varTypes	varTypes[1] = {string};
		err_str = setErrorString(err_str, 1, varTypes, "Error: Table has wrong header fields");
		return (false);
	}
	line_count++;
	while (std::getline(this->input_file, line))
	{
		if (line.find_first_not_of("0123456789-|. \t") != std::string::npos || line.find_first_of('|') == std::string::npos)	// these are the only valid characters
		{
			BTC::e_varTypes	varTypes[4] = {string, integer, string, string};
			err_str = setErrorString(err_str, 4, varTypes, "Error at line: ", line_count, "\nLine: ", line.c_str());
			return (false);
		}
		if (line.empty())
			continue ;
		if (line.find_first_of(" \t") < line.find_first_not_of(" \t"))
			line.erase(line.find_first_of(" \t"), line.find_first_not_of(" \t"));
		year = line.substr(0, line.find_first_of(' '));
		value = line.substr(line.find_first_of("|"), std::string::npos);
		if (value.find_first_not_of("| \t") == std::string::npos)
		{
			BTC::e_varTypes	varTypes[4] = {string, integer, string, string};
			err_str = setErrorString(err_str, 4, varTypes, "Error at line: ", line_count, "\nLine: ", line.c_str());
			return (false);
		}
		value = value.substr(value.find_first_not_of("| \t"), std::string::npos);
		line_count++;
		if (!isValidYear(year) || !isValidValue(value))
		{
			BTC::e_varTypes	varTypes[4] = {string, integer, string, string};
			err_str = setErrorString(err_str, 4, varTypes, "Error at line: ", line_count, "\nLine: ", line.c_str());
			return (false);
		}
	}
	this->input_file.clear();
	return (true);
}

void	BTC::returnDatabaseFromInput()
{
	std::string	line;
	std::string	year;
	double		value;

	std::getline(this->database_file, line);
	while (std::getline(this->input_file, line))
	{
		std::cout << "line: " << line << "\n";
		year = this->getYear(line);
		value = std::atof(this->getValue(line).c_str());
		std::cout << "csv val: " << this->database.at(year);
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

const char*	BTC::InvalidDatabaseHeader::what()
{
	return ("The input database has invalid header fields");
}