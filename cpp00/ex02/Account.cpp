/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pipolint <pipolint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 20:12:32 by pipolint          #+#    #+#             */
/*   Updated: 2024/08/28 16:06:31 by pipolint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_totalAmount += _amount;
	_nbAccounts++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "created" \
		<< std::endl;
};

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";" << "closed" \
		<< std::endl;
};

void	Account::_displayTimestamp(void)
{
	std::time_t	t = std::time(NULL);
	std::tm *ti = std::localtime(&t);
	std::cout << "[" << ti->tm_year + 1900 << std::setw(2) << std::setfill('0') << ti->tm_mon + 1 << \
		std::setw(2) << std::setfill('0') << ti->tm_mday << "_" << std::setw(2) << std::setfill('0') << ti->tm_hour << \
			std::setw(2) << std::setfill('0') << ti->tm_min << std::setw(2) << std::setfill('0') << ti->tm_sec << "] ";
};

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";" \
		"deposit:" << deposit << ";";
	_totalNbDeposits += 1;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	std::cout << "amount:" << _amount << ";" << "nb_deposits:" << _nbDeposits << std::endl;
};

bool	Account::makeWithdrawal(int withdrawal)
{
	bool	result = true;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "p_amount:" << _amount << ";";
	_totalNbWithdrawals++;
	if (_amount - withdrawal < 0)
		result = false;
	else
		_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	if (result)
	{
		std::cout << "withdrawal:" << withdrawal << ";" << "amount:" << _amount << ";" \
			<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	else
		std::cout << "withdrawal:" << "refused" << std::endl;
	return (result);
};

int	Account::checkAmount(void) const
{
	return (this->_amount);
};

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" << checkAmount() << ";" \
		"deposits:" << _nbDeposits << ";" << "withdrawals:" << _nbWithdrawals << ";" << std::endl;
};

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
};

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
};

int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
};

int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
};

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";" << "total:" << getTotalAmount() << ";" << \
		"deposits:" << getNbDeposits() << ";" << "withdrawals:" << getNbWithdrawals() << ";" << std::endl;
};
