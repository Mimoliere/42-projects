/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:06:14 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:06:14 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Harl.hpp"

Harl::Harl() {

}

Harl::~Harl() {

}

void	Harl::complain(std::string level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	void	(Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error}; //	IMPORTANT !!!

	int 	i;
	bool	loop = true;

	for (i = 0; i < 4 && loop; i++) {
		if (!levels[i].compare(level)) {
			loop = false;
			i--;
		}
	}

	switch(i) {
		case 0:
			(this->*functions[i++])();
			std::cout << std::endl;
			/* fallthrough */
		case 1:
			(this->*functions[i++])();
			std::cout << std::endl;
			/* fallthrough */
		case 2:
			(this->*functions[i++])();
			std::cout << std::endl;
			/* fallthrough */
		case 3:
			(this->*functions[i])();
			std::cout << std::endl;
			break ;
		default:
			std::cout << "Harl doesn't know this complain !!" << std::endl;
	}
}

void	Harl::debug() {
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info() {
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning() {
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error() {
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
