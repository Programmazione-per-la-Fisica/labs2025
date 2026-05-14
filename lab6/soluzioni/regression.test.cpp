#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "regression.hpp"

#include "doctest.h"

TEST_CASE("Regression - fitting with no points throws") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  CHECK_THROWS(reg.fit());
}

TEST_CASE("Regression - fitting on one point throws - use coordinates") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(0., 0.);
  CHECK_THROWS(reg.fit());
}

TEST_CASE(
    "Regression - fitting on two vertically aligned points throws - use "
    "coordinates") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(1., 0.);
  reg.add(1., 2.);
  CHECK_THROWS(reg.fit());
}

TEST_CASE("Regression - fitting on two points - use coordinates") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(0., 0.);
  reg.add(1., 1.);
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(0));
  CHECK(result.B == doctest::Approx(1));
}

TEST_CASE(
    "Regression - fitting on two points negative slope - use coordinates") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(0., 1.);
  reg.add(1., 0.);
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(1));
  CHECK(result.B == doctest::Approx(-1));
}

TEST_CASE("Regression - fitting on five points - use coordinates") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(2.1, 3.2);
  reg.add(6.9, 7.3);
  reg.add(2.2, 3.0);
  reg.add(0.1, 1.3);
  reg.add(4.7, 5.6);
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(1.2).epsilon(0.01));
  CHECK(result.B == doctest::Approx(0.9).epsilon(0.01));
}

TEST_CASE("Regression - fitting on one point throws - use Point") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(pf::Point{0., 0.});
  CHECK_THROWS(reg.fit());
}

TEST_CASE(
    "Regression - fitting on two vertically aligned points throws - use "
    "Point") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(pf::Point{1., 0.});
  reg.add(pf::Point{1., 2.});
  CHECK_THROWS(reg.fit());
}

TEST_CASE("Regression - fitting on two points - use Point") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(pf::Point{0., 0.});
  reg.add(pf::Point{1., 1.});
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(0));
  CHECK(result.B == doctest::Approx(1));
}

TEST_CASE("Regression - fitting on two points negative slope - use Point") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(pf::Point{0., 1.});
  reg.add(pf::Point{1., 0.});
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(1));
  CHECK(result.B == doctest::Approx(-1));
}

TEST_CASE("Regression - fitting on five points - use Point") {
  pf::Regression reg;
  REQUIRE(reg.size() == 0);
  reg.add(pf::Point{2.1, 3.2});
  reg.add(pf::Point{6.9, 7.3});
  reg.add(pf::Point{2.2, 3.0});
  reg.add(pf::Point{0.1, 1.3});
  reg.add(pf::Point{4.7, 5.6});
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(1.2).epsilon(0.01));
  CHECK(result.B == doctest::Approx(0.9).epsilon(0.01));
}

TEST_CASE("Regression - removing existing point with coordinates") {
  pf::Regression reg;
  pf::Point p1{1., 2.};
  pf::Point p2{2., 3.};
  REQUIRE(reg.size() == 0);

  reg.add(p1);
  reg.add(p2);
  CHECK(reg.remove(1., 2.) == true);
  CHECK(reg.size() == 1);
}

TEST_CASE("Regression - removing non-existing point with coordinates") {
  pf::Regression reg;
  pf::Point p1{1., 2.};
  pf::Point p2{2., 3.};
  REQUIRE(reg.size() == 0);

  reg.add(p1);
  reg.add(p2);
  CHECK(reg.remove(5., 4.) == false);
  CHECK(reg.size() == 2);
}

TEST_CASE("Regression - removing existing point with Point") {
  pf::Regression reg;
  pf::Point p1{1., 2.};
  pf::Point p2{2., 3.};
  REQUIRE(reg.size() == 0);

  reg.add(p1);
  reg.add(p2);
  CHECK(reg.remove(p1) == true);
  CHECK(reg.size() == 1);
}

TEST_CASE("Regression - removing non-existing point with Point") {
  pf::Regression reg;
  pf::Point p1{1., 2.};
  pf::Point p2{2., 3.};
  REQUIRE(reg.size() == 0);

  reg.add(p1);
  reg.add(p2);
  pf::Point p3{5., 4.};
  CHECK(reg.remove(p3) == false);
  CHECK(reg.size() == 2);
}

TEST_CASE("Testing sum of two Regression objects") {
  pf::Regression reg1;
  reg1.add(0., 1.);
  pf::Regression reg2;
  reg2.add(2., 3.);
  auto sum = reg1 + reg2;
  CHECK(sum.size() == 2);
  if (sum.size() == 2) {
    CHECK(sum.points()[0].x == doctest::Approx(0.0));
    CHECK(sum.points()[0].y == doctest::Approx(1.0));
    CHECK(sum.points()[1].x == doctest::Approx(2.0));
    CHECK(sum.points()[1].y == doctest::Approx(3.0));
  }
}
