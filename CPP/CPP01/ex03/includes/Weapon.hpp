#ifndef WEAPON_H
#define WEAPON_H

#pragma once

#include <string>
#include <iostream>

class Weapon {

	public:
		Weapon(std::string type);
		~Weapon();

		std::string	getType();
		void		setType(std::string type);

	private:
		std::string	_type;
};

#endif