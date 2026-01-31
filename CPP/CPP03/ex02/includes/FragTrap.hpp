/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:08:36 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:08:38 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

	private:

	public:
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		virtual ~FragTrap();

		void	attack(const std::string& target);
		void	highFivesGuys(void);
};

#endif
