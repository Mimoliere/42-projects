#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

#pragma once

class FragTrap : virtual public ClapTrap {

	private:

	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		virtual ~FragTrap();

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
