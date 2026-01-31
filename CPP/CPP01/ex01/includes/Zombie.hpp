/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:04:33 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:04:37 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H

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

Zombie*	zombieHorde(int N, std::string name);

#endif