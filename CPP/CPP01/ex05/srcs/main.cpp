/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:06:02 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:06:02 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

int	main(int argc, char *argv[]) {

	if (argc != 2) {
		std::cout << "Wrong number of arguments." << std::endl;
		std::cout << "Usage: ./harl {complain-level}" << std::endl;
		return (1);
	}

	Harl		harl;
	std::string	level = argv[1];

	harl.complain(level);

	return (0);
}
