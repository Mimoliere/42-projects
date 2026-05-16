/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <boualemguerroumi21@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:16:32 by bguerrou          #+#    #+#             */
/*   Updated: 2026/05/05 10:40:11 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array {
	private:
		unsigned int	size_;
		T*				arr_;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array();

		T&			operator[](unsigned int index);
		const T&	operator[](unsigned int index) const;
		
		unsigned int	size() const;
		
		class OutOfBoundsException : public std::exception {
			public:
				virtual const char*	what() const throw() {
					return ("Index is out of bounds.");
				}
		};

};

#include "../srcs/Array.tpp"

#endif
