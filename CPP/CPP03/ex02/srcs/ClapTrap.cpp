/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:08:46 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:08:47 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	std::cout << "ClapTrap default constructor called" << std::endl;

	_name = name;
	_hp = 10;
	_ep = 10;
	_ad = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	_name = other.getName();
	_hp = other.getHp();
	_ep = other.getEp();
	_ad = other.getAd();
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other) {
	if (this != &other) {
		_name = other.getName();
		_hp = other.getHp();
		_ep = other.getEp();
		_ad = other.getAd();
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target) {
	performAttack(target, "ClapTrap");
}

void	ClapTrap::performAttack(const std::string& target, const std::string& typeTrap) {
	if (_ep > 0) {
		std::cout << typeTrap << " " << _name << " attacks " << target << ", ";
		std::cout << "causing " << _ad << " points of damage !\n";

		_ep--;
		std::cout << _name << " loses 1 energy point." << std::endl;
	} else {
		std::cout << _name << " has no energy !" <<std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (_hp > 0) {
		std::cout << _name << " takes " << amount << " damage !";
		std::cout << std::endl;

		_hp -= amount;
	} else {
		std::cout << "HE'S ALREADY DEAD YOU MONSTER !!!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_ep > 0) {
		std::cout << _name << " regains " << amount << " hit points !";
		std::cout << std::endl;

		_ep--;
		std::cout << _name << " loses 1 energy point."  << std::endl;
	} else {
		std::cout << _name << " has no energy !" <<std::endl;
	}
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

std::string	ClapTrap::getName(void) const {
	return (_name);
}

int	ClapTrap::getHp(void) const {
	return (_hp);
}

int	ClapTrap::getEp(void) const {
	return (_ep);
}

int	ClapTrap::getAd(void) const {
	return (_ad);
}

void	ClapTrap::setName(std::string const newName) {
	_name = newName;
}

void	ClapTrap::setHp(int const newHp) {
	_hp = newHp;
}

void	ClapTrap::setEp(int const newEp) {
	_ep = newEp;
}

void	ClapTrap::setAd(int const newAd) {
	_ad = newAd;
}
