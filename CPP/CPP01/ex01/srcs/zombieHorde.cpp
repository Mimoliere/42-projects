/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:04:46 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:04:47 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++) {	
		horde[i].setName(name);
	}

	return (horde);
}
