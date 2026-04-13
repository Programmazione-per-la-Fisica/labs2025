#include <iostream>
#include <vector>
// ...

struct Point {
  double x;
  double y;
};

double norm2(const Point& p) { return p.x * p.x + p.y * p.y; }

std::vector<Point> generate_points(int n) {
  std::vector<Point> points;

  // ...

  return points;
}

double compute_pi(std::vector<Point> const& points) {
  // ...

  return 0.0;  // dummy return value, must be changed
}

int main() {
  int const N{100};

  auto points = generate_points(N);
  std::cout << "Points std::vector size: " << points.size() << '\n';

  double pi_approx = compute_pi(points);
  std::cout << "Approximated pi value: " << pi_approx << '\n';
}
