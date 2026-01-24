#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

#pragma once

class ClapTrap {

	protected:
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_ad;

	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& other);
		~ClapTrap();

		void	attack(const std::string& target);
		void	performAttack(const std::string& target, const std::string& typeTrap);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string	getName(void) const;
		int			getHp(void) const;
		int			getEp(void) const;
		int			getAd(void) const;
		void		setName(std::string const newName);
		void		setHp(int const newHp);
		void		setEp(int const newEp);
		void		setAd(int const newAd);

};

#endif
