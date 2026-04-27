/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 16:16:32 by bguerrou          #+#    #+#             */
/*   Updated: 2026/04/27 17:26:39 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

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
