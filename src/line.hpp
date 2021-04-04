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

	Line()
	: Line(0, 0, 0, 0)
	{
	}

	/* Line (2) - normal. */

	Line(T x1, T y1, T x2, T y2)
	: x1(x1)
	, y1(y1)
	, x2(x2)
	, y2(y2)
	{
	}

	/* Line (3) - vertical. */

	Line(T x, T y1, T y2)
	: x1(x)
	, y1(y1)
	, x2(x)
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

	/* withShiftedX
    Returns a new Line horizontally shifted by a certain amount. */

	Line withShiftedX(T amount) const { return {x1 + amount, y1, x2 + amount, y2}; }

	T x1, y1, x2, y2;

private:
};
} // namespace geompp

#endif