/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:06:39 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:06:43 by bguerrou         ###   ########.fr       */
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
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const newRawBits);
		int		toInt(void) const;
		float	toFloat(void) const;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
