/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maalmeid <maalmeid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:21:45 by maalmeid          #+#    #+#             */
/*   Updated: 2025/04/28 13:16:38 by maalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
    return _nbAccounts;
}
int Account::getTotalAmount(void)
{
    return _totalAmount;
}

int Account::getNbAccounts(void)
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout   << "accounts:" << _nbAccounts << ";"
                << "total:" << _totalAmount << ";"
                << "deposits:" << _totalNbDeposits << ";"
                << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    std::cout   << "["
                << tm_now->tm_hour + 1900
                << std::setfill('0') << std::setw(2) << tm_now->tm_mon + 1
                << std::setfill('0') << std::setw(2) << tm_now->tm_mday
                << "_"
                << std::setfill('0') << std::setw(2) << tm_now->tm_hour
                << std::setfill('0') << std::setw(2) << tm_now->tm_min
                << std::setfill('0') << std::setw(2) << tm_now->tm_sec
                << "] ";
}

Account::Account(int initial_deposit) :
    _accountIndex(_nbAccounts),
    _amount(initial_deposit),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "created" << std::endl;
}

Account::~Account(void)
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "deposit:" << deposit << ";";
                
    _amount += deposit;
    _nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;
    
    std::cout   << "amount:" << _amount << ";"
                << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "p_amount:" << _amount << ";"
                << "withdrawal:";
                
    if (withdrawal > _amount)
    {
        std::cout << "refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _nbWithdrawals++;

    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    std::cout   << withdrawal << ";"
                << "amount:" << _amount << ";"
                << "nb_withdrawals:" << _nbWithdrawals << std::endl;
                
    return true;
}

int Account::checkAmount(void) const
{
    return _amount;
}

void Account::displayStatus(void) const 
{
    _displayTimestamp();
    std::cout   << "index:" << _accountIndex << ";"
                << "amount:" << _amount << ";"
                << "deposits:" << _nbDeposits << ";"
                << "withdrawals:" << _nbWithdrawals << std::endl;
}