#ifndef ZOMBIE_H
#define ZOMBIE_H

#pragma once

#include <string>
#include <iostream>

class Zombie {
	public:
		Zombie();
		~Zombie();

		void	announce(void);
		void	setName(std::string name);

	private:
		std::string	_name;

};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif