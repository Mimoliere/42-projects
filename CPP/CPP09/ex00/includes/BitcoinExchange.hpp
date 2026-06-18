/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:20:00 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/18 16:48:31 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

class BitcoinExchange {
	private:
		std::string			input_path_;
		static std::string	db_path_;
		std::ifstream		input_file_, db_file_;

		std::map<std::string, float>		rates_;

		void	readDataBase();
		void	treatLine(std::string line);
		void	printResults(std::string date, float val);

	public:
		BitcoinExchange(std::string ip);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	readInput();

		class OpenFileException : public std::exception {
			private:
				std::string	msg_;
			public:
				OpenFileException(const std::string& filename)
					: msg_("Error: Can't open file (" + filename + ").") {}
				~OpenFileException() throw() {}

				virtual const char*	what() const throw() {
					return msg_.c_str();
				}
		};

};

bool	isValidLine(std::string& line);
bool	onlySpaces(std::string& str, size_t start);

#endif
