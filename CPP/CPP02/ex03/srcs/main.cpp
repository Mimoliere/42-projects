#include "../includes/Point.hpp"

void	printResult(Point a, Point b, Point c, Point p);

int main( void ) {
	Point	a(0, 2);
	Point	b(2, -2);
	Point	c(-2, -2);
	Point	point1(0, 2);
	Point	point2(5, 5);
	Point	point3(0, 0);

	std::cout << "Is point1(" << point1.getX().toInt() << ","
				<< point1.getY().toInt() << ") in ABC ? ";
	printResult(a, b, c, point1);

	std::cout << "Is point2(" << point2.getX().toInt() << ","
				<< point2.getY().toInt() << ") in ABC ? ";
	printResult(a, b, c, point2);

	std::cout << "Is point3(" << point3.getX().toInt() << ","
				<< point3.getY().toInt() << ") in ABC ? ";
	printResult(a, b, c, point3);

	return (0);
}

void	printResult(Point a, Point b, Point c, Point p) {
	if (bsp(a, b, c, p))
		std::cout << "Yes";
	else
		std::cout << "No";
	std::cout << std::endl;
}
