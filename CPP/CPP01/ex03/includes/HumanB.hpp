#ifndef HUMANB_H
#define HUMANB_H

#pragma once

#include "Weapon.hpp"

class HumanB {

	public:
		HumanB(std::string name);
		~HumanB();

		void	attack();
		void	setWeapon(Weapon& weapon);	// weapon est ici une référence au paramètre

	private:
		std::string	_name;
		Weapon*		_weapon;	// On utilise un pointeur parce que :
								// Il est crée sans arme (pointeur nul)
								// Il reçoit une arme après sa création (réassignation)
};

#endif