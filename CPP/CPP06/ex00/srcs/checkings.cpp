/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:40:42 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/21 17:58:19 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

bool	isPseudo(const std::string& literal) {
	std::string	pseudos[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

	for (int i = 0; i < 6; i++) {
		if (literal.compare(pseudos[i]) == 0)
			return (true);
	}

	return (false);
}

bool	validFloat(const std::string& literal) {
	std::string	values = "+-0123456789.f";
	std::size_t	a = literal.find('+');
	std::size_t	s = literal.find('-');
	std::size_t	f = literal.find('f');
	std::size_t	p = literal.rfind('.');

	if (literal.find_first_not_of(values) != std::string::npos)
		return (false);

	if (occurences(literal, '+') > 1 || (a != std::string::npos && a > 0))
		return (false);
	
	if (occurences(literal, '-') > 1 || (s != std::string::npos && s > 0))
		return (false);

	if (f != std::string::npos) {
		if (occurences(literal, 'f') > 1 || f != literal.length() - 1)
			return (false);
		if (p != std::string::npos && p == literal.length() - 2)
			return (false);
	}

	if (p != std::string::npos) {
		if (occurences(literal, '.') > 1 || p == 0 || p == literal.length() - 1)
			return (false);
	}
	else
		return (false);

	return (true);
}

bool	validInt(const std::string& literal) {
	std::string	values = "+-0123456789";
	std::size_t	a = literal.find('+');
	std::size_t	s = literal.find('-');

	if (literal.find_first_not_of(values) != std::string::npos)
		return (false);

	if (occurences(literal, '+') > 1 || (a != std::string::npos && a > 0))
		return (false);
	
	if (occurences(literal, '-') > 1 || (s != std::string::npos && s > 0))
		return (false);

	return (true);
}

int	occurences(const std::string& literal, char c) {
	int counter = 0;

	for (int i = 0; literal[i]; i++) {
		if (literal[i] == c)
			counter++;
	}

	return (counter);
}
