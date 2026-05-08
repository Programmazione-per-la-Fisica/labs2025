#ifndef PF_REGRESSION_HPP
#define PF_REGRESSION_HPP

#include <vector>

namespace pf {

struct Result {
  double A;
  double B;
};

struct Point {
  double x;
  double y;
};

bool operator==(Point const&, Point const&);

class Regression {
  std::vector<Point> points_;

 public:
  std::size_t size() const;

  const std::vector<Point>& points() const;

  void add(Point const&);
  void add(double x, double y);
  void add(std::vector<Point> const&);

  bool remove(Point const&);
  bool remove(double x, double y);

  Result fit() const;

  Regression& operator+=(Regression const&);
};

Regression operator+(Regression const&, Regression const&);

inline auto fit(Regression const& reg) {
  // the following call would fail compilation if the fit method weren't const
  return reg.fit();
}

}  // namespace pf

#endif