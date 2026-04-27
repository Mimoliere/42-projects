/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 15:04:36 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/27 16:14:21 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	printIt(T const c) {
	std::cout << c << " ";
}

void	doubleIt(int& n) {
	n *= 2;
}

void	toMaj(char& c) {
	c = std::toupper(c);
}

template <typename T, typename F>
void	iter(T* arr, const int len, F func) {
	for (int i = 0; i < len; i++) {
		func(arr[i]);
	}
}

#endif
