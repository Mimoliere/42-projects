/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:05:09 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:17:27 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {

	public:
		Weapon(std::string type);
		~Weapon();

		const std::string&	getType() const;
		void		setType(std::string type);

	private:
		std::string	_type;
};

#endif