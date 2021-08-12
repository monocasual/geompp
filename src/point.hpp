/* -----------------------------------------------------------------------------
 *
 * geompp - Basic geometrical utilities for C++.
 *
 * -----------------------------------------------------------------------------
 *
 * Copyright (C) 2021 Giovanni A. Zuliani | Monocasual Laboratories
 *
 * This file is part of geompp - Basic geometrical utilities for C++.
 *
 * geompp - Basic geometrical utilities for C++ is free software: you can
 * redistribute it and/or modify it under the terms of the GNU General
 * Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 *
 * geompp - Basic geometrical utilities for C++ is distributed in the hope that 
 * it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with geompp - Basic geometrical utilities for C++. If not, see
 * <http://www.gnu.org/licenses/>.
 *
 * -------------------------------------------------------------------------- */

#ifndef GEOMPP_POINT_HH
#define GEOMPP_POINT_HH

#include <cassert>

namespace geompp
{
template <typename T>
class Point
{
public:
	constexpr Point()
	: Point(0, 0)
	{
	}

	constexpr Point(T x, T y)
	: x(x)
	, y(y)
	{
	}

	bool operator==(const Point<T>& o) const
	{
		return x == o.x && y == o.y;
	}

	bool operator!=(const Point<T>& o) const
	{
		return !(*this == o);
	}

	Point<T> operator+(const Point<T>& o) const
	{
		return {x + o.x, y + o.y};
	}

	Point<T> operator-(const Point<T>& o) const
	{
		return {x - o.x, y - o.y};
	}

	/* with[...]
    Returns a copy of this Point with a new coordinate. */

	Point<T> withX(T v) const { return {v, y}; }
	Point<T> withY(T v) const { return {x, v}; }

	T x;
	T y;
};
} // namespace geompp

#endif
