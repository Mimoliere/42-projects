/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:46:22 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/24 14:55:27 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T> void	swap(T &x, T &y) {
	T	tmp = x;

	x = y;
	y = tmp;
}

template <typename T> T		min(T x, T y) {
	return (x < y ? x : y);
}

template <typename T> T		max(T x, T y) {
	return (x > y ? x : y);
}

#endif
