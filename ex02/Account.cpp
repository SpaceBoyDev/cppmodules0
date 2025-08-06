/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 02:10:43 by dario             #+#    #+#             */
/*   Updated: 2025/08/06 02:42:58 by dario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>
#include <iomanip>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return 0;
}

int Account::getTotalAmount(void)
{
	return 0;
}

int Account::getNbDeposits(void)
{
	return 0;
}

int Account::getNbWithdrawals(void)
{
	return 0;
}

void Account::displayAccountsInfos(void)
{
}

Account::Account(int initial_deposit) : _amount(initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbDeposits = 1;
	_nbWithdrawals = 0;

	_totalAmount += initial_deposit;
	++_totalNbDeposits;

	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << initial_deposit
		<< ";created" << std::endl;
	++_nbAccounts;
	//index:0;amount:42;created
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_amount += deposit;
	_totalAmount += deposit;
	++_totalNbDeposits;
	++_nbDeposits;

	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << _amount
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
	//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
}

bool Account::makeWithdrawal(int withdrawal)
{
	return false;
}

int Account::checkAmount(void) const
{
	return 0;
}

void Account::displayStatus(void) const
{
}

void Account::_displayTimestamp(void)
{
	std::time_t	time;
	std::tm		*tm;

	time = std::time(NULL);
	tm = std::localtime(&time);
	std::cout << "["
		<< std::setfill('0') << std::setw(4) << tm->tm_year + 1900
		<< std::setw(2) << tm->tm_mon + 1
		<< std::setw(2) << tm->tm_mday << "_"
		<< std::setw(2) << tm->tm_hour
		<< std::setw(2) << tm->tm_min
		<< std::setw(2) << tm->tm_sec
		<< "] ";
}
