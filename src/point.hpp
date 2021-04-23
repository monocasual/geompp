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
	Point()
	: Point(0, 0)
	{
	}

	Point(T x, T y)
	: x(x)
	, y(y)
	{
	}

	T x, y;
};
} // namespace geompp

#endif
