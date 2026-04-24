/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:48:24 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/23 15:27:49 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

Serializer::Serializer() {

}

Serializer::Serializer(const Serializer& other) {
	(void) other;
}

Serializer&	Serializer::operator=(const Serializer& other) {
	(void) other;
	return (*this);
}

Serializer::~Serializer() {

}

uintptr_t	Serializer::serialize(Data* ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data*>(raw));
}
