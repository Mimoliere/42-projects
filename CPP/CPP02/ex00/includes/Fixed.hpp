#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

#pragma once

class Fixed {

	private:
		int					_rawBits;
		static const int	_fracBitsNb = 8;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const newRawBits);

};

#endif
