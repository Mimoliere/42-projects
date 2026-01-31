/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:08:55 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:08:55 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap default constructor called" << std::endl;

	_hp = 100;
	_ep = 50;
	_ad = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {

}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return (*this);
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target) {
	performAttack(target, "ScavTrap");
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap is now in Gate keeper mode !" << std::endl;
}
