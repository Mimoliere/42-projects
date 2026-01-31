/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:04:43 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:04:43 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(void) {

}

Zombie::~Zombie(void) {
	std::cout << _name << " was destroyed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ.." << std::endl;
}

void	Zombie::setName(std::string name) {
	_name = name;
}
