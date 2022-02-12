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

#ifndef GEOMPP_BORDER_HH
#define GEOMPP_BORDER_HH

namespace geompp
{
template <typename T>
class Border
{
public:
	/* Border (1) 
    Empty border. */

	constexpr Border()
	: Border(0, 0, 0, 0)
	{
	}

	/* Border (2) 
    Normal border. */

	constexpr Border(T t, T r, T b, T l)
	: top(t)
	, right(r)
	, bottom(b)
	, left(l)
	{
	}

	/* Border (3) 
    Normal border, all sides equal. */

	constexpr Border(T v)
	: Border(v, v, v, v)
	{
	}

	/* Border (4) 
    Normal border, horizontal and vertical sides equal. */

	constexpr Border(T x, T y)
	: Border(y, x, y, x)
	{
	}

	T top, right, bottom, left;
};
} // namespace geompp

#endif