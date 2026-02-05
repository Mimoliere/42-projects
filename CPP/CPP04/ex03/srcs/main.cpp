/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:13:12 by bguerrou          #+#    #+#             */
/*   Updated: 2026/02/05 17:46:18 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/IMateriaSource.hpp"
#include "../includes/MateriaSource.hpp"
#include "../includes/Ice.hpp"
#include "../includes/Cure.hpp"
#include "../includes/Character.hpp"

int main() {
	IMateriaSource*	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());

	ICharacter*	me = new Character("me");
	AMateria*	tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	me->unequip(0);
	me->unequip(0);
	tmp = src->createMateria("ice");
	
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(5, *bob);
	
	delete bob;
	delete me;
	delete src;

	return 0;
}
