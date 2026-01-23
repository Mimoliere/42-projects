#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#pragma once

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
