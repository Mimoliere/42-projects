/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:02:50 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:03:52 by bguerrou         ###   ########.fr       */
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

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif