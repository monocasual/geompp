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
		REQUIRE(r1.getLength() == r1.b - r1.a);
	}

	SECTION("Test contains point")
	{
		REQUIRE(r1.contains(r1.a + 1));
		REQUIRE(!r1.contains(r1.b + 1));
	}

	SECTION("Test intersection")
	{
		REQUIRE(r1.intersects({r1.a, r1.b - 1}));
		REQUIRE(r1.intersects({r1.a, r1.b + 1}));
		REQUIRE(r1.intersects({r1.a - 1, r1.b}));
		REQUIRE(r1.intersects({r1.a + 1, r1.b}));
		REQUIRE(r1.intersects({r1.a - 1, r1.b + 1}));
		REQUIRE(r1.intersects({r1.a + 1, r1.b - 1}));
		REQUIRE(!r1.intersects({r1.b, r1.b + 1}));
	}

	SECTION("Test contains Range")
	{
		REQUIRE(r1.contains({r1.a, r1.b}));
		REQUIRE(r1.contains({r1.a + 1, r1.b - 1}));
		REQUIRE(!r1.contains({r1.a - 1, r1.b}));
		REQUIRE(!r1.contains({r1.a, r1.b + 1}));
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
			REQUIRE(left.a == r1.a);
			REQUIRE(left.b == r2.a);
			REQUIRE(left.getLength() == r2.a - r1.a);
			REQUIRE(right.a == r2.b);
			REQUIRE(right.b == r1.b);
			REQUIRE(right.getLength() == r1.b - r2.b);
		}

		SECTION("Test left edge")
		{
			// r1: ----------
			// r2: --
			const Range r2{0, 2};
			const auto [left, right] = r1.getDifference(r2);

			REQUIRE(!left.isValid());
			REQUIRE(right.isValid());
			REQUIRE(right.a == r2.b);
			REQUIRE(right.b == r1.b);
			REQUIRE(right.getLength() == r1.b - r2.b);
		}

		SECTION("Test right edge")
		{
			// r1: ----------
			// r2:         --
			const Range r2{8, 10};
			const auto [left, right] = r1.getDifference(r2);

			REQUIRE(left.isValid());
			REQUIRE(!right.isValid());
			REQUIRE(left.a == r1.a);
			REQUIRE(left.b == r2.a);
			REQUIRE(left.getLength() == r2.a - r1.a);
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
}