#ifndef GEOMPP_RECT_HH
#define GEOMPP_RECT_HH

#include "line.hpp"

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
    Reduces width and height by a certain amount. */

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

	void reduce(T amount)
	{
		reduce(amount, amount);
	}

	/* with[...]
    Returns a copy of this Rect with a new position/size. */

	Rect<T> withX(T v) const
	{
		Rect r = *this;
		r.setX(v);
		return r;
	}

	Rect<T> withY(T v) const
	{
		Rect r = *this;
		r.setY(v);
		return r;
	}

	Rect<T> withW(T v) const
	{
		Rect r = *this;
		r.setW(v);
		return r;
	}

	Rect<T> withH(T v) const
	{
		Rect r = *this;
		r.setH(v);
		return r;
	}

	/* withTrimmed[...]
    Returns a copy of this Rect with 'amount' removed from the one of the 
    edges. */

	Rect<T> withTrimmedLeft(T v) const
	{
		Rect r = *this;
		r.trimLeft(v);
		return r;
	}

	Rect<T> withTrimmedRight(T v) const
	{
		Rect r = *this;
		r.trimRight(v);
		return r;
	}

	Rect<T> withTrimmedTop(T v) const
	{
		Rect r = *this;
		r.trimTop(v);
		return r;
	}

	Rect<T> withTrimmedBottom(T v) const
	{
		Rect r = *this;
		r.trimBottom(v);
		return r;
	}

	/* getHeightAsLine
    Returns height as a new Line object. */

	Line<T> getHeightAsLine() const
	{
		return Line(x, y, yh);
	}

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

	T x, y, w, h, xw, yh;

private:
};
} // namespace geompp

#endif