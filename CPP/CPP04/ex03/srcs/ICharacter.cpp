/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:12:59 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:12:59 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ICharacter.hpp"

ICharacter::ICharacter() {

}

ICharacter::ICharacter(const ICharacter& other) {

}

ICharacter&	ICharacter::operator=(const ICharacter& other) {
	if (this != &other) {

	}
	return (*this);
}

ICharacter::~ICharacter() {

}
