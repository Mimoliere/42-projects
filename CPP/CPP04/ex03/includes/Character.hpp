/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:11:56 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:11:59 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "linkedLists.hpp"

#define MAX_INVENTORY 4

class Character : public ICharacter {

	private:
		std::string		_name;
		AMateria*		_inventory[MAX_INVENTORY];
		int				_nb_equip;
		t_abandoned*	_abandon;

	public:
		Character(const std::string& name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character();

		virtual std::string const & getName() const;
		int	const					getNbEquip() const;

		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter& target);
};

#endif
