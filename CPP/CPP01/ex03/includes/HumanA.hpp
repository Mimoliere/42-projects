/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:05:03 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:05:04 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

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