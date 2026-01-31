/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:07:02 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:07:06 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {

	private:
		int					_rawBits;
		static const int	_fracBitsNb = 8;

	public:
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;

		Fixed&	operator++();		// ++i
		Fixed	operator++(int);	// i++
		Fixed&	operator--();		// --i
		Fixed	operator--(int);	// i--

		static Fixed&		min(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static Fixed&		max(Fixed& f1, Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);

		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const newRawBits);
		int		toInt(void) const;
		float	toFloat(void) const;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
