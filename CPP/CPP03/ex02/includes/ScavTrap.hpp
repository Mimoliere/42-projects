/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:08:40 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:08:42 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	private:

	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);
		virtual ~ScavTrap();

		void	attack(const std::string& target);
		void	guardGate();
};

#endif
