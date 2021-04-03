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

	Line withShiftedX(T x) const
	{
		Line l = *this;
		l.shiftX(x);
		return l;
	}

	void shiftX(T x)
	{
		x1 = x;
		x2 = x;
	}

	T x1, y1, x2, y2;

private:
};
} // namespace geompp

#endif