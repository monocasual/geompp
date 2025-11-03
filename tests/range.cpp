#include "src/range.hpp"
#include <catch2/catch_test_macros.hpp>

TEST_CASE("Range")
{
	using namespace geompp;

	const Range r1{0, 10};

	SECTION("Test validity")
	{
		REQUIRE(r1.isValid());
	}

	SECTION("Test length")
	{
		REQUIRE(r1.getLength() == r1.getB() - r1.getA());

		Range r2{0, 10};
		r2.setLength(r1.getLength() * 2);

		REQUIRE(r2.getLength() == r2.getB() - r2.getA());
	}

	SECTION("Test move")
	{
		const int delta = 100;
		Range     r2    = r1;

		r2.move(delta);

		REQUIRE(r2.getLength() == r1.getLength());
		REQUIRE(r2.getA() == r1.getA() + delta);
		REQUIRE(r2.getB() == r1.getB() + delta);
	}

	SECTION("Test contains point")
	{
		REQUIRE(r1.contains(r1.getA() + 1));
		REQUIRE(!r1.contains(r1.getB() + 1));
	}

	SECTION("Test intersection")
	{
		REQUIRE(r1.intersects({r1.getA(), r1.getB() - 1}));
		REQUIRE(r1.intersects({r1.getA(), r1.getB() + 1}));
		REQUIRE(r1.intersects({r1.getA() - 1, r1.getB()}));
		REQUIRE(r1.intersects({r1.getA() + 1, r1.getB()}));
		REQUIRE(r1.intersects({r1.getA() - 1, r1.getB() + 1}));
		REQUIRE(r1.intersects({r1.getA() + 1, r1.getB() - 1}));
		REQUIRE(!r1.intersects({r1.getB(), r1.getB() + 1}));
	}

	SECTION("Test contains Range")
	{
		REQUIRE(r1.contains({r1.getA(), r1.getB()}));
		REQUIRE(r1.contains({r1.getA() + 1, r1.getB() - 1}));
		REQUIRE(!r1.contains({r1.getA() - 1, r1.getB()}));
		REQUIRE(!r1.contains({r1.getA(), r1.getB() + 1}));
	}

	SECTION("Test difference")
	{
		SECTION("Test middle")
		{
			// r1: ----------
			// r2:   --
			const Range r2{2, 4};
			const auto [left, right] = r1.getDifference(r2);

			REQUIRE(left.isValid());
			REQUIRE(right.isValid());
			REQUIRE(left.getA() == r1.getA());
			REQUIRE(left.getB() == r2.getA());
			REQUIRE(left.getLength() == r2.getA() - r1.getA());
			REQUIRE(right.getA() == r2.getB());
			REQUIRE(right.getB() == r1.getB());
			REQUIRE(right.getLength() == r1.getB() - r2.getB());
		}

		SECTION("Test left edge")
		{
			// r1: ----------
			// r2: --
			const Range r2{0, 2};
			const auto [left, right] = r1.getDifference(r2);

			REQUIRE(!left.isValid());
			REQUIRE(right.isValid());
			REQUIRE(right.getA() == r2.getB());
			REQUIRE(right.getB() == r1.getB());
			REQUIRE(right.getLength() == r1.getB() - r2.getB());
		}

		SECTION("Test right edge")
		{
			// r1: ----------
			// r2:         --
			const Range r2{8, 10};
			const auto [left, right] = r1.getDifference(r2);

			REQUIRE(left.isValid());
			REQUIRE(!right.isValid());
			REQUIRE(left.getA() == r1.getA());
			REQUIRE(left.getB() == r2.getA());
			REQUIRE(left.getLength() == r2.getA() - r1.getA());
		}

		SECTION("Test invalid")
		{
			// r1: ----------
			// r2:             --
			const Range r2{12, 14};
			const auto [left, right] = r1.getDifference(r2);

			REQUIRE(!left.isValid());
			REQUIRE(!right.isValid());
		}
	}

	SECTION("Test operations (compound)")
	{
		auto rMult = r1;
		rMult *= 2;
		REQUIRE(rMult == Range{r1.getA(), r1.getB() * 2});

		auto rDiv = r1;
		rDiv /= 2;
		REQUIRE(rDiv == Range{r1.getA(), r1.getB() / 2});

		auto rPlus = r1;
		rPlus += 2;
		REQUIRE(rPlus == Range{r1.getA() + 2, r1.getB() + 2});

		auto rMin = r1;
		rMin -= 2;
		REQUIRE(rMin == Range{r1.getA() - 2, r1.getB() - 2});
	}

	SECTION("Test operations")
	{
		const auto rCopy = r1;
		REQUIRE(r1 == rCopy);
		REQUIRE(r1 != rCopy + 1);

		const auto rMult = r1 * 2;
		REQUIRE(rMult == Range{r1.getA(), r1.getB() * 2});

		const auto rDiv = r1 / 2;
		REQUIRE(rDiv == Range{r1.getA(), r1.getB() / 2});

		const auto rPlus = r1 + 2;
		REQUIRE(rPlus == Range{r1.getA() + 2, r1.getB() + 2});

		const auto rMin = r1 - 2;
		REQUIRE(rMin == Range{r1.getA() - 2, r1.getB() - 2});
	}
}
