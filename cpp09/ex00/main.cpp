/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:57:22 by pipolint          #+#    #+#             */
/*   Updated: 2025/02/27 16:31:33 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitCoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./btc <database file>\n";
		return (1);
	}
	BTC			btc;
	std::string	err_str;

	try
	{
		btc.open_btc_database();
	}
	catch (BTC::BtcDataBaseException& e)
	{
		std::cerr << e.what() << "\n";
	}
	if (btc.open_input_database(av[1], err_str) == false)
	{
		std::cout << err_str << "\n";
		return (1);
	}
	btc.returnDatabaseFromInput();
}