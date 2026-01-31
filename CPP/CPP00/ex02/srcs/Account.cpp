/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:02:12 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:02:13 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	Account::_displayTimestamp();

	_accountIndex = getNbAccounts();
	Account::_nbAccounts++;
	_amount = initial_deposit;
	Account::_totalAmount += _amount;

	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";created" << std::endl;
}

void	Account::displayAccountsInfos(void) {
	Account::_displayTimestamp();

	std::cout << "accounts:" << Account::getNbAccounts();
	std::cout << ";total:" << Account::getTotalAmount();
	std::cout << ";deposits:" << Account::getNbDeposits();
	std::cout << ";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit) {
	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << checkAmount();
	std::cout << ";deposit:" << deposit;

	_amount += deposit;
	_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;

	std::cout << ";amount:" << checkAmount();
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << checkAmount();

	if (withdrawal >= checkAmount()) {
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << ";withdrawal:" << withdrawal;

	_amount -= withdrawal;
	_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;

	std::cout << ";amount:" << checkAmount();
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

	return (true);
}

int	Account::checkAmount(void) const {
	return (_amount);
}

void	Account::displayStatus(void) const {
	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void) {
	time_t		curr_time;
	struct tm	*datetime;

	time(&curr_time);
	datetime = localtime(&curr_time);
	
	std::cout << "[" << datetime->tm_year + 1900;	// Year
	if (datetime->tm_mon + 1 < 10)
		std::cout << "0";
	std::cout << datetime->tm_mon + 1;				// Month
	if (datetime->tm_mday < 10)
		std::cout << "0";
	std::cout << datetime->tm_mday << "_";			// Day
	if (datetime->tm_hour < 10)
		std::cout << "0";
	std::cout << datetime->tm_hour;					// Hour
	if (datetime->tm_min < 10)
		std::cout << "0";
	std::cout << datetime->tm_min;					// Minutes
	if (datetime->tm_sec < 10)
		std::cout << "0";
	std::cout << datetime->tm_sec << "] ";			// Seconds
}

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

Account::~Account(void) {
	Account::_displayTimestamp();

	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";closed" << std::endl;
}
