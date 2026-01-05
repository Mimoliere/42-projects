#ifndef HUMANA_H
#define HUMANA_H

#pragma once

#include "Weapon.hpp"

class HumanA {

	public:
		HumanA(std::string name, Weapon&	 weapon);
		~HumanA();

		void	attack();

	private:
		std::string	_name;
		Weapon&		_weapon;	// On utilise une référence parce que :
								// Il reçoit une arme dès sa création
								// Il sera armé DANS TOUS LES CAS
								// Il ne changera JAMAIS d'arme
};

#endif