#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

struct Point {
  double x;
  double y;
};

double norm2(const Point& p) { return p.x * p.x + p.y * p.y; }

std::vector<Point> generate_points(int n) {
  std::vector<Point> points;
  points.reserve(n);

  std::random_device rd{};
  std::default_random_engine eng{rd()};
  std::uniform_real_distribution<double> uniform{0.0, 1.0};

  std::generate_n(std::back_inserter(points), n,
                  [&] { return Point{uniform(eng), uniform(eng)}; });

  assert(static_cast<int>(points.size()) == n);

  return points;
}

double compute_pi(std::vector<Point> const& points) {
  auto n = points.size();
  auto n_in_circle =
      std::count_if(points.begin(), points.end(),
                    [](Point const& p) { return norm2(p) < 1.0; });

  return 4.0 * n_in_circle / n;
}

int main() {
  int const N{1'000'000};

  auto points = generate_points(N);
  std::cout << "Points std::vector size: " << points.size() << '\n';

  double pi_approx = compute_pi(points);
  std::cout << "Approximated pi value: " << pi_approx << '\n';
}
