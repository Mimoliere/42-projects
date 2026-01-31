/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguerrou <bguerrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:07:26 by bguerrou          #+#    #+#             */
/*   Updated: 2026/01/31 14:07:29 by bguerrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(const float a, const float b);
		Point(const Point& other);
		Point&	operator=(const Point& other);
		~Point();

		Fixed const	getX(void) const;
		Fixed const	getY(void) const;

};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
