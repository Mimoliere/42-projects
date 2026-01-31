/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:05:06 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:05:14 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

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