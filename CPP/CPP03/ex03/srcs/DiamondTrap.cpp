/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:09:23 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:09:24 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "DiamondTrap constructor called" << std::endl;

	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_ad = FragTrap::_ad;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	_name = other._name;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ScavTrap::operator=(other);
		FragTrap::operator=(other);
		_name = other._name;
	}
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
