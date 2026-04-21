/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:43:03 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/21 18:02:59 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

static Type	isValid(const std::string& literal);
static void	printVal(double val);

ScalarConverter::ScalarConverter() {
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void) other;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void) other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {

}

void    ScalarConverter::convert(const std::string& literal) {
	Type	type = isValid(literal);
	double	val;

	switch (type) {
		case CHAR:
			val = static_cast<double>(literal[1]);
			break;

		case INT:
			int	tmp;
			std::istringstream(literal) >> tmp;
			val = static_cast<double>((tmp));
			break;

		case FLOAT:
			if (literal.find('f') != std::string::npos) {
				float	tmp;
				std::stringstream(literal) >> tmp;
				val = static_cast<double>(tmp);
				break;
			}
			else
				type = DOUBLE;

		case DOUBLE:
			std::istringstream(literal) >> val;
			break;

		case PSEUDO:
			if (!literal.compare("nan") || !literal.compare("nanf"))
				val = NAN;
			else if (!literal.compare("+inf") || !literal.compare("+inff"))
				val = INFINITY;
			else
				val = -INFINITY;
			break;

		default:
			throw UnknownLiteralException();
	}

	printVal(val);
}

static Type	isValid(const std::string& literal) {
	if (literal.empty())
		return (UNKNOWN);

	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (CHAR);

	if (isPseudo(literal))
		return (PSEUDO);
	
	if (validFloat(literal))
		return (FLOAT);

	if (validInt(literal))
		return (INT);

	return (UNKNOWN);
}

static void	printVal(double val) {
	char	c = static_cast<char>(val);
	int		i = static_cast<int>(val);
	float	f = static_cast<float>(val);

	std::cout << "char: ";
	if (std::isnan(val) || std::isinf(val) || val < 0 || val > 127)
		std::cout << "Impossible";
	else if (c < 32 || c == 127)
		std::cout << "Non displayable";
	else
		std::cout << c;
	std::cout << std::endl;

	std::cout << "int: ";
	if (std::isnan(val) || std::isinf(val) || val < INT_MIN || val > INT_MAX)
		std::cout << "Impossible";
	else
		std::cout << i;
	std::cout << std::endl;

	std::cout << "float: ";
	if (std::isnan(f))
		std::cout << "nanf";
	else if (std::isinf(f))
		std::cout << (f > 0 ? "+inff" : "-inff");
	else {
		std::cout << f;
		if (f == static_cast<int>(f))
			std::cout << ".0";
		std::cout << "f";
	}
	std::cout << std::endl;

	std::cout << "double: ";
	if (std::isnan(val))
		std::cout << "nan";
	else if (std::isinf(val))
		std::cout << (val > 0 ? "+inf" : "-inf");
	else {
		std::cout << val;
		if (val == static_cast<int>(val))
			std::cout << ".0";
	}
	std::cout << std::endl;
}
