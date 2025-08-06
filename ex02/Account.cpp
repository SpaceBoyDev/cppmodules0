/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dario <dario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 02:10:43 by dario             #+#    #+#             */
/*   Updated: 2025/08/06 03:47:11 by dario            ###   ########.fr       */
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
	return (_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals
		<< std::endl;
	//[19920104_091532] accounts:8;total:12442;deposits:8;withdrawals:6
}

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_amount = initial_deposit;
	_totalAmount += initial_deposit;

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
		<< ";p_amount:" << (_amount - deposit)
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits
		<< std::endl;
	//[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		std::cout
			<< "index:" << _accountIndex
			<< ";p_amount:" << _amount
			<< ";withdrawal:refused"
			<< std::endl;
		return (false);
		//[19920104_091532] index:5;p_amount:23;withdrawal:refused
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	++_totalNbWithdrawals;
	++_nbWithdrawals;

	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";p_amount:" << (_amount + withdrawal)
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbDeposits
		<< std::endl;

	return (true);		
	//[19920104_091532] index:4;p_amount:1321;withdrawal:76;amount:1245;nb_withdrawals:1
}

int Account::checkAmount(void) const
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
	//[19920104_091532] index:7;amount:8942;deposits:1;withdrawals:1
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
