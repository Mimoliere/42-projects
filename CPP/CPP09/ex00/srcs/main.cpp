/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 16:20:09 by bguerrou          #+#    #+#             */
/*   Updated: 2026/06/18 16:49:46 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}

	try {
		BitcoinExchange	btc(argv[1]);

		btc.readInput();
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (2);
	}

	return (0);
}
