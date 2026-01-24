#include "../includes/Point.hpp"

// Aire d'un triangle : Aire= 1/2 * ​​∣ ​x1​(y2​−y3​) + x2​(y3​−y1​) + x3​(y1​−y2​) ∣

Fixed	areaCalcul(Point const a, Point const b, Point const c);
float	process(Fixed x1, Fixed y2, Fixed y3);

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed	A;
	Fixed	A1;
	Fixed	A2;
	Fixed	A3;
	bool	res;

	A = areaCalcul(a, b, c);
	A1 = areaCalcul(point, a, b);
	A2 = areaCalcul(point, b, c);
	A3 = areaCalcul(point, a, c);

	if (A1 == 0 || A2 == 0 || A3 == 0)
		res = false;
	else
		res = A == A1 + A2 + A3;

	return (res);
}

Fixed	areaCalcul(Point const a, Point const b, Point const c) {
	float	calcul;

	calcul = 0.5 * (process(a.getX(), b.getY(), c.getY())
					+ process(b.getX(), c.getY(), a.getY())
					+ process(c.getX(), a.getY(), b.getY()));
	if (calcul < 0)
		calcul = -calcul;

	return (Fixed(calcul));
}

float	process(Fixed x1, Fixed y2, Fixed y3) {
	float	res;

	res = x1.toFloat() * (y2.toFloat() - y3.toFloat());
	return (res);
}
