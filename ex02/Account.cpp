/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleduc <fleduc@student.42quebec.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:11:27 by fleduc            #+#    #+#             */
/*   Updated: 2022/11/13 20:50:48 by fleduc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

void	Account::_displayTimestamp( void ) {
    time_t  now = time(0);
    struct tm   tstruct = *localtime(&now);
    std::cout << "[";
    std::cout << tstruct.tm_year + 1900;
    std::cout << std::setw(2) << std::setfill('0') << tstruct.tm_mon + 1;
    std::cout << std::setw(2) << std::setfill('0') << tstruct.tm_mday;
    std::cout << "_";
    std::cout << std::setw(2) << std::setfill('0') << tstruct.tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << tstruct.tm_min;
    std::cout << std::setw(2) << std::setfill('0') << tstruct.tm_sec;
    std::cout << "] ";
}

Account::Account( void ) {
    return ;
}

Account::Account( int initial_deposit ) : _amount(initial_deposit), _nbDeposits(0),
_nbWithdrawals(0) {
    this->_accountIndex = Account::_nbAccounts;
    Account::_nbAccounts++;
    Account::_totalAmount += this->_amount;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "created" << std::endl;
}

Account::~Account( void ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos( void ) {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl; 
}

void	Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    std::cout << "amount:" << this->_amount << ";";
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << this->_amount << ";";
    if (withdrawal <= this->_amount)
    {
        std::cout << "withdrawal:" << withdrawal << ";";
        this->_amount -= withdrawal;
        Account::_totalAmount -= withdrawal;
        std::cout << "amount:" << this->_amount << ";";
        this->_nbWithdrawals++;
        Account::_totalNbWithdrawals++;
        std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return (true);
    }
    std::cout << "withdrawal:refused" << std::endl;
    return (false);
}

int Account::checkAmount( void ) const {
    return (this->_amount);
}

int	Account::getNbAccounts( void ) {
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void ) {
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
    return (Account::_totalNbWithdrawals);
}

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
