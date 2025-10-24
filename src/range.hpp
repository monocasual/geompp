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
#include <utility>

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

	bool operator==(const Range<T>& o) const { return a == o.a && b == o.b; }
	bool operator!=(const Range<T>& o) const { return !operator==(o); }

	Range<T> operator*(const T m) const { return {a * m, b * m}; }
	Range<T> operator*=(const T m)
	{
		a *= m;
		b *= m;
		return *this;
	}

	Range<T> operator/(const T m) const { return {a / m, b / m}; }
	Range<T> operator/=(const T m)
	{
		a /= m;
		b /= m;
		return *this;
	}

	Range<T> operator+(const T m) const { return {a + m, b + m}; }
	Range<T> operator+=(const T m)
	{
		a += m;
		b += m;
		return *this;
	}

	Range<T> operator-(const T m) const { return {a - m, b - m}; }
	Range<T> operator-=(const T m)
	{
		a -= m;
		b -= m;
		return *this;
	}

	T getLength() const { return b - a; }

	bool isValid() const
	{
		return a < b;
	}

	bool contains(T t) const
	{
		return t >= a && t < b;
	}

	/* intersects
	True if Range o intersects this one. */

	bool intersects(Range<T> o) const
	{
		return o.a < b && a < o.b;
	}

	/* contains
	True if Range o lies entirely inside this one. */

	bool contains(Range<T> o) const
	{
		return a <= o.a && b >= o.b;
	}

	/* getDifference
	Returns the difference of this Range with another one as two ranges. They
	might be invalid in some cases.
	See: https://en.wikipedia.org/wiki/Symmetric_difference */

	std::pair<Range<T>, Range<T>> getDifference(Range<T> o) const
	{
		if (!intersects(o))
			return {};
		// if (contains(o))
		//	return {{a, o.a}, {o.b, b}};

		Range<T> r1 = a == o.a ? Range<T>() : a < o.a ? Range(a, o.a)
		                                              : Range(o.a, a);
		Range<T> r2 = b == o.b ? Range<T>() : o.b < b ? Range(o.b, b)
		                                              : Range(b, o.b);

		return {r1, r2};
	}

	T a, b;
};
} // namespace geompp

#endif
