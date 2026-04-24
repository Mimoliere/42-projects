/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:56:07 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/23 13:01:35 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Data.hpp"

Data::Data(const int data) : _data(data) {

}

Data::Data(const Data& other) : _data(other._data) {

}

Data&	Data::operator=(const Data& other) {
	if (this != &other)
		_data = other._data;

	return (*this);
}

Data::~Data() {

}
