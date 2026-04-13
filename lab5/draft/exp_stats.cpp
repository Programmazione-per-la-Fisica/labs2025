#include <cmath>
#include <iostream>
#include <vector>
// ...

auto generate_entries(int n, double gamma) {
  std::vector<double> entries;

  // ...

  return entries;
}

double mean(std::vector<double> const& entries) {
  // ...

  return 0.0;  // dummy return value, must be changed
}

double median(std::vector<double> const& entries) {
  // ...

  return 0.0;  // dummy return value, must be changed
}

int main() {
  int N{100'000};
  double gamma{2.0};

  std::cout << "entries vector:\n";

  auto entries = generate_entries(N, gamma);
  std::cout << "- size: " << entries.size() << '\n';

  double mu = mean(entries);
  std::cout << "- mean: " << mu << " (expected: " << 1.0 / gamma << ")\n";

  double me = median(entries);
  std::cout << "- median: " << me << " (expected: " << std::log(2) / gamma
            << ")\n";
}
