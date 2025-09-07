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

#include "border.hpp"
#include "line.hpp"
#include "point.hpp"
#include "range.hpp"
#include <algorithm>

namespace geompp
{
template <typename T>
class Rect
{
public:
	/* Rect (1)
	Invalid rectangle. */

	constexpr Rect()
	: Rect(0, 0, 0, 0)
	{
	}

	/* Rect (2)
	Normal rectangle. */

	constexpr Rect(T x, T y, T w, T h)
	: x(x)
	, y(y)
	, w(w)
	, h(h)
	, xw(x + w)
	, yh(y + h)
	{
	}

	Point<T> getTopLeft() const { return {x, y}; }
	Point<T> getTopRight() const { return {xw, y}; }
	Point<T> getBottomLeft() const { return {x, yh}; }
	Point<T> getBottomRight() const { return {xw, yh}; }

	Line<T> getTopLine() const { return {getTopLeft(), getTopRight()}; }
	Line<T> getBottomLine() const { return {getBottomLeft(), getBottomRight()}; }
	Line<T> getLeftLine() const { return {getTopLeft(), getBottomLeft()}; }
	Line<T> getRightLine() const { return {getTopRight(), getBottomRight()}; }

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

	/* setPosition
	Sets the top-left corner to Point 'p'. */

	void setPosition(Point<T> p)
	{
		setX(p.x);
		setY(p.y);
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

	/* reduce
	Reduces all four sides by a certain Border. */

	void reduce(Border<T> b)
	{
		x += b.left;
		y += b.top;
		w -= b.left + b.right;
		h -= b.top + b.bottom;
		xw = x + w;
		yh = y + h;
	}

	/* Scale
	Scales this Rect scaled by a certain amount. */

	void scale(float factor)
	{
		x *= factor;
		y *= factor;
		w *= factor;
		h *= factor;
		xw = x + w;
		yh = y + h;
	}

	/* isValid
	True if this Rect has size greater than zero. */

	bool isValid() const { return w > 0 && h > 0; }

	/* expand (1), (2)
	The opposite of reduce (1), (2). */

	void expand(T amountX, T amountY) { reduce(-amountX, -amountY); }
	void expand(T amount) { reduce(-amount); }

	/* with[...]
	Returns a copy of this Rect with a new position/size. */

	Rect<T> withX(T v) const { return {v, y, w, h}; }
	Rect<T> withY(T v) const { return {x, v, w, h}; }
	Rect<T> withW(T v) const { return {x, y, v, h}; }
	Rect<T> withH(T v) const { return {x, y, w, v}; }

	/* withPosition
	Returns a copy of this Rect with a new top-left corner given by Point 'p'. */

	Rect<T> withPosition(Point<T> p) const { return {p.x, p.y, w, h}; }

	/* withSize
	Returns a copy of this Rect with a new tsize. */

	Rect<T> withSize(T newW, T newH) const { return {x, y, newW, newH}; }

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

	/* with[Horizontal|Vertical]Range
	Returns a copy of this rect new position and size defined by Range 'r'. */

	Rect<T> withHorizontalRange(Range<T> r) const { return {r.a, y, r.getLength(), h}; }
	Rect<T> withVerticalRange(Range<T> r) const { return {x, r.a, w, r.getLength()}; }

	/* get[Width|Height]AsLine
	Returns width or height as a new Line object. */

	Line<T> getWidthAsLine() const { return Line(x, y, xw - 1, y); }
	Line<T> getHeightAsLine() const { return Line(x, y, x, yh - 1); }

	/* get[Width|Height]AsRange
	Returns width or height as a new Range object. */

	Range<T> getWidthAsRange() const { return x < xw ? Range(x, xw) : Range<T>(); }
	Range<T> getHeightAsRange() const { return y < yh ? Range(y, yh) : Range<T>(); }

	Point<T> getPosition() const { return Point(x, y); }

	/* reduced
	Returns a copy of this Rect with all four sides reduced by a certain Border. */

	Rect<T> reduced(Border<T> b) const
	{
		Rect r = *this;
		r.reduce(b);
		return r;
	}

	/* scaled
	Returns a copy of this Rect scaled by a certain amount. */

	Rect<T> scaled(float factor)
	{
		Rect r = *this;
		r.scale(factor);
		return r;
	}

	/* expanded (1), (2)
	The opposite of reduced (1), (2). */

	Rect<T> expanded(T amountX, T amountY) const { return reduced(-amountX, -amountY); }
	Rect<T> expanded(T amount) const { return reduced(-amount); }

	/* contains (1)
	Returns true if Point p is inside this Rect. */

	bool contains(Point<T> p) const
	{
		return p.x >= x && p.y >= y && p.x < xw && p.y < yh;
	}

	/* contains (2)
	Returns true if Line l is inside this Rect. */

	bool contains(Line<T> l) const
	{
		return l.x1 >= x && l.x1 < xw && l.x2 >= x && l.x2 < xw &&
		       l.y1 >= y && l.y1 < yh && l.y2 >= y && l.y2 < yh;
	}

	/* contains (3)
	Returns true if Rect o is inside this Rect. */

	bool contains(const Rect<T>& o) const
	{
		return x <= o.x && y <= o.y && x + w >= o.x + o.w && y + h >= o.y + o.h;
	}

	/* getIntersection
	Returns the intersection with another Rect o and this one. Might return
	an invalid Rect if the two don't intersect. */

	Rect<T> getIntersection(const Rect<T>& o) const
	{
		T nx = std::max(x, o.x);
		T ny = std::max(y, o.y);
		T nw = std::min(x + w, o.x + o.w) - nx;
		T nh = std::min(y + h, o.y + o.h) - ny;

		if (nw <= 0 || nh <= 0)
			return {};
		return {nx, ny, nw, nh};
	}

	T x, y, w, h, xw, yh;
};
} // namespace geompp

#endif