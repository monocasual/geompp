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

#ifndef GEOMPP_LINE_HH
#define GEOMPP_LINE_HH

namespace geompp
{
template <typename T>
class Line
{
public:
	/* Line (1) - invalid. */

	constexpr Line()
	: Line(0, 0, 0, 0)
	{
	}

	/* Line (2) - normal. */

	constexpr Line(T x1, T y1, T x2, T y2)
	: x1(x1)
	, y1(y1)
	, x2(x2)
	, y2(y2)
	{
	}

	/* shiftX
    Horizontally shifts the line of a certain amount. */

	void shiftX(T amount)
	{
		x1 += amount;
		x2 += amount;
	}

	/* with[...]
    Returns a copy of this Line with new coordintates. */

	Line withX1(T v) const { return {v, y1, x2, y2}; }
	Line withY1(T v) const { return {x1, v, x2, y2}; }
	Line withX2(T v) const { return {x1, y1, v, y2}; }
	Line withY2(T v) const { return {x1, y1, x2, v}; }
	Line withX(T v) const { return {v, y1, v, y2}; }
	Line withY(T v) const { return {x1, v, x2, v}; }

	/* withShiftedX
    Returns a new Line horizontally shifted by a certain amount. */

	Line withShiftedX(T amount) const { return {x1 + amount, y1, x2 + amount, y2}; }

	T x1, y1, x2, y2;
};
} // namespace geompp

#endif