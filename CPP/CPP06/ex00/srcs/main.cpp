/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:39:22 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/21 17:42:42 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: ./converter <literal>" << std::endl;
		return (1);
	}

	try {
		ScalarConverter::convert(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
