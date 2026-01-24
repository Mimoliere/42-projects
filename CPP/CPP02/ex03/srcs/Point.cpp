#include "../includes/Point.hpp"

Point::Point() : _x(0), _y(0) {

}

Point::Point(const float a, const float b) : _x(a), _y(b) {

}

Point::Point(const Point& other) : _x(other.getX()), _y(other.getY()) {

}

Point&	Point::operator=(const Point& other) {
	(void) other;
	return (*this);
}

Point::~Point() {

}

Fixed const	Point::getX(void) const {
	return (_x);
}

Fixed const	Point::getY(void) const {
	return (_y);
}
