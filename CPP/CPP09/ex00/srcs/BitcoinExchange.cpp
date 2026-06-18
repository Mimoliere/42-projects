/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:20:04 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/18 22:42:39 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

std::string	BitcoinExchange::db_path_ = "data.csv";

BitcoinExchange::BitcoinExchange(std::string ip) : input_path_(ip)
{
	input_file_.open(input_path_.c_str());
	if (!input_file_)
		throw OpenFileException(input_path_);

	db_file_.open(db_path_.c_str());
	if (!db_file_)
		throw OpenFileException(db_path_);

	readDataBase();
}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : input_path_(other.input_path_)
{
	if (input_file_)
		input_file_.close();
	if (db_file_)
		db_file_.close();

	input_file_.open(input_path_.c_str());
	if (!input_file_)
		throw OpenFileException(input_path_);

	db_file_.open(db_path_.c_str());
	if (!db_file_)
		throw OpenFileException(db_path_);

	readDataBase();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other) {
		input_path_ = other.input_path_;

		if (input_file_)
			input_file_.close();
		if (db_file_)
			db_file_.close();

		input_file_.open(input_path_.c_str());
		if (!input_file_)
			throw OpenFileException(input_path_);

		db_file_.open(db_path_.c_str());
		if (!db_file_)
			throw OpenFileException(db_path_);

		readDataBase();
	}

	return (*this);
}

void	BitcoinExchange::readDataBase()
{
	std::string	line;

	std::getline(db_file_, line);
	while (std::getline(db_file_, line)) {
		std::istringstream	iss(line);
		std::string			date;
		float				rate;

		if (std::getline(iss, date, ','))
			if (iss >> rate)
				rates_[date] = rate;
	}
}

void	BitcoinExchange::readInput()
{
	std::string	line;

	std::getline(input_file_, line);
	while (std::getline(input_file_, line)) {
		if (line.empty() || onlySpaces(line, 0))
			continue;

		if (!isValidLine(line)) {
			std::cout << "Error: bad input => " + line << std::endl;
			continue;
		}

		treatLine(line);
	}
}

void	BitcoinExchange::treatLine(std::string line)
{
	size_t				sep_pos = line.find(" | ");
	std::string			date = line.substr(0, sep_pos);
	std::string			value = line.substr(sep_pos + 3, line.size());
	float				val;
	std::istringstream	iss(value);

	if (date.find_first_not_of("0123456789-") != std::string::npos) {
		std::cout << "Error: not a valid date." << std::endl;
		return;
	}

	if (!(iss >> val) || val < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}

	if (val > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return;
	}

	printResults(date, val);
}

void	BitcoinExchange::printResults(std::string date, float val)
{
	std::map<std::string, float>::iterator	it = rates_.lower_bound(date);

	if (it != rates_.end() && it->first != date)
		it--;
	else if (it == rates_.begin()) {
		std::cout << "Error: date is too early, no data available." << std::endl;
		return;
	}

	std::cout << date + " => " << val << " = " << val * it->second;
	std::cout << std::endl;
}

bool	isValidLine(std::string& line)
{
	size_t	sep_pos = line.find(" | ");
	if (sep_pos == std::string::npos)
		return (false);

	size_t	tmp = line.find(' ', sep_pos + 3);
	if (tmp != std::string::npos && !onlySpaces(line, tmp))
		return (false);

	return (true);
}

bool	onlySpaces(std::string& str, size_t start)
{
	while (start < str.size() && str[start] == ' ')
		start++;

	if (start < str.size())
		return (false);
	return (true);
}
