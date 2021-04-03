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

	/* getHeightAsLine
    Returns height as a new Line object. */

	Line<T> getHeightAsLine() const
	{
		return Line(x, y, yh);
	}

	/* reduced (1)
    Returns a new Rect with width and height reduced by a certain amount. */

	Rect<T> reduced(T amountX, T amountY) const
	{
		Rect r = *this;

		r.x += amountX;
		r.y += amountY;
		r.w -= amountX * 2;
		r.h -= amountY * 2;
		r.xw = r.x + r.w;
		r.yh = r.y + r.h;

		return r;
	}

	/* reduced (2)
    Returns a new Rect with all four sides reduced by a certain amount around
    the center point. */

	Rect<T> reduced(T amount) const
	{
		return reduced(amount, amount);
	}

	T x, y, w, h, xw, yh;

private:
};
} // namespace geompp

#endif