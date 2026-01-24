#include "../includes/Fixed.hpp"

Fixed::Fixed() {
	_rawBits = 0;
}

Fixed::Fixed(const int val) {
	_rawBits = val << _fracBitsNb;
}

Fixed::Fixed(const float val) {
	_rawBits = roundf(val * (1 << _fracBitsNb));
}

Fixed::Fixed(const Fixed& other) {	
	_rawBits = other.getRawBits();
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		_rawBits = other.getRawBits();
	}
	return (*this);
}

bool	Fixed::operator>(const Fixed& other) const {
	return (_rawBits > other.getRawBits());
}

bool	Fixed::operator<(const Fixed& other) const {
	return (_rawBits < other.getRawBits());
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (_rawBits >= other.getRawBits());
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (_rawBits <= other.getRawBits());
}

bool	Fixed::operator==(const Fixed& other) const {
	return (_rawBits == other.getRawBits());
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (_rawBits != other.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& other) const {
	Fixed	result;

	result.setRawBits(_rawBits + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	Fixed	result;

	result.setRawBits(_rawBits - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	Fixed	result;

	result.setRawBits((_rawBits * other.getRawBits()) >> _fracBitsNb);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& other) const {
	Fixed	result;

	result.setRawBits((_rawBits << _fracBitsNb) / other.getRawBits());
	return (result);
}

Fixed&	Fixed::operator++() {
	++_rawBits;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	old = *this;
	++_rawBits;
	return (old);
}

Fixed&	Fixed::operator--() {
	--_rawBits;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed old = *this;
	--_rawBits;
	return (old);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2) {
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2) {
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed::~Fixed() {

}

int	Fixed::getRawBits(void) const {
	return (_rawBits);
}

void	Fixed::setRawBits(int const newRawBits) {
	_rawBits = newRawBits;
}

int		Fixed::toInt(void) const {
	return (_rawBits >> _fracBitsNb);
}

float	Fixed::toFloat(void) const {
	return ((float) _rawBits / (1 << _fracBitsNb));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return (os);
}
