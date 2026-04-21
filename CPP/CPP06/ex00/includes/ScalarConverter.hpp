/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:38:45 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/21 17:50:56 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <cfloat>
#include <cmath>
#include <string>
#include <sstream>

enum Type {
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO,
	UNKNOWN
};

bool	isPseudo(const std::string& literal);
bool	validFloat(const std::string& literal);
bool	validInt(const std::string& literal);
int		occurences(const std::string& literal, char c);

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter&	operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static void	convert(const std::string& literal);

		class UnknownLiteralException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("Argument is unknown.");
				}
		};

};

#endif
