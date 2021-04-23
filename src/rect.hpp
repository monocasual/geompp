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

#ifndef GEOMPP_RECT_HH
#define GEOMPP_RECT_HH

#include "line.hpp"
#include "point.hpp"

namespace geompp
{
template <typename T>
class Rect
{
public:
	/* Rect (1) 
    Invalid rectangle. */

	Rect()
	: Rect(0, 0, 0, 0)
	{
	}

	/* Rect (2) 
    Normal rectangle. */

	Rect(T x, T y, T w, T h)
	: x(x)
	, y(y)
	, w(w)
	, h(h)
	, xw(x + w)
	, yh(y + h)
	{
	}

	void setX(T v)
	{
		x  = v;
		xw = x + w;
	}

	void setY(T v)
	{
		y  = v;
		yh = y + h;
	}

	void setW(T v)
	{
		w  = v;
		xw = x + w;
	}

	void setH(T v)
	{
		h  = v;
		yh = y + h;
	}

	/* shift[...]
	Shifts the rectangle by a certain amount. */

	void shiftX(T amount)
	{
		x += amount;
		xw = x + w;
	}

	void shiftY(T amount)
	{
		y += amount;
		yh = y + h;
	}

	/* trim[..]
    Removes 'amount' from the one of the edges. */

	void trimLeft(T amount)
	{
		x += amount;
		w -= amount;
	}

	void trimRight(T amount)
	{
		w -= amount;
		xw = x + w;
	}

	void trimTop(T amount)
	{
		y += amount;
		h -= amount;
	}

	void trimBottom(T amount)
	{
		h -= amount;
		yh = y + h;
	}

	/* reduce (1)
    Reduces width and height by a certain amount around the center point. */

	void reduce(T amountX, T amountY)
	{
		x += amountX;
		y += amountY;
		w -= amountX * 2;
		h -= amountY * 2;
		xw = x + w;
		yh = y + h;
	}

	/* reduce (2)
    Reduces all four sides by a certain amount around the center point. */

	void reduce(T amount) { reduce(amount, amount); }

	/* with[...]
    Returns a copy of this Rect with a new position/size. */

	Rect<T> withX(T v) const { return {v, y, w, h}; }
	Rect<T> withY(T v) const { return {x, v, w, h}; }
	Rect<T> withW(T v) const { return {x, y, v, h}; }
	Rect<T> withH(T v) const { return {x, y, w, v}; }

	/* withShifted[...]
	Returns a copy of this Rect shifted by a certain amount. */

	Rect<T> withShiftedX(T amount) const { return {x + amount, y, w, h}; }
	Rect<T> withShiftedY(T amount) const { return {x, y + amount, w, h}; }

	/* withTrimmed[...]
    Returns a copy of this Rect with 'amount' removed from the one of the 
    edges. */

	Rect<T> withTrimmedLeft(T amount) const { return {x + amount, y, w - amount, h}; }
	Rect<T> withTrimmedRight(T amount) const { return {x, y, w - amount, h}; }
	Rect<T> withTrimmedTop(T amount) const { return {x, y + amount, w, h - amount}; }
	Rect<T> withTrimmedBottom(T amount) const { return {x, y, w, h - amount}; }

	/* getHeightAsLine
    Returns height as a new Line object. */

	Line<T> getHeightAsLine() const { return Line(x, y, yh); }

	/* reduced (1)
    Returns a copy of this Rect with width and height reduced by a certain 
    amount. */

	Rect<T> reduced(T amountX, T amountY) const
	{
		Rect r = *this;
		r.reduce(amountX, amountY);
		return r;
	}

	/* reduced (2)
    Returns a copy of this Rect with all four sides reduced by a certain amount 
    around the center point. */

	Rect<T> reduced(T amount) const
	{
		return reduced(amount, amount);
	}

	/* contains
	Returns true if Point p is inside this Rect. */

	bool contains(Point<T> p) const
	{
		return p.x >= x && p.y >= y && p.x < wx && p.y < yh;
	}

	T x, y, w, h, xw, yh;
};
} // namespace geompp

#endif