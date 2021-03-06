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

#ifndef GEOMPP_RANGE_HH
#define GEOMPP_RANGE_HH

#include <cassert>

namespace geompp
{
template <typename T>
class Range
{
public:
	constexpr Range() // Invalid default range
	: a(0)
	, b(0)
	{
	}

	constexpr Range(T a, T b)
	: a(a)
	, b(b)
	{
		assert(a < b);
	}

	Range<T> operator*(const T m) const { return {a * m, b * m}; }
	Range<T> operator*=(const T m) const { return {a * m, b * m}; }
	Range<T> operator/(const T m) const { return {a / m, b / m}; }
	Range<T> operator/=(const T m) const { return {a / m, b / m}; }
	Range<T> operator+(const T m) const { return {a + m, b + m}; }
	Range<T> operator+=(const T m) const { return {a + m, b + m}; }
	Range<T> operator-(const T m) const { return {a - m, b - m}; }
	Range<T> operator-=(const T m) const { return {a - m, b - m}; }

	T getLength() const { return b - a; }

	bool isValid() const
	{
		return a < b;
	}

	bool contains(T t) const
	{
		return t >= a && t < b;
	}

	T a, b;
};
} // namespace geompp

#endif
