#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

auto generate_entries(int n, double gamma) {
  assert(n > 0);
  assert(gamma > 0.0);
  std::vector<double> entries;
  entries.reserve(n);

  std::random_device rd{};
  std::default_random_engine eng{rd()};
  std::exponential_distribution<double> exp{gamma};

  std::generate_n(std::back_inserter(entries), n, [&]() { return exp(eng); });

  assert(static_cast<int>(entries.size()) == n);

  return entries;
}

double mean(std::vector<double> const& entries) {
  assert(entries.size() > 0);
  return std::accumulate(entries.begin(), entries.end(), 0.0) / entries.size();
}

double median(std::vector<double> const& entries) {
  assert(entries.size() > 0);
  auto e_sorted{entries};
  const std::size_t n = e_sorted.size();

  std::sort(e_sorted.begin(), e_sorted.end());

  auto it = e_sorted.begin() + n / 2;

  return n % 2 == 0 ? (*it + *(it-1)) / 2.0 : *it;
}

double median_nth(std::vector<double> const& entries) {
  assert(entries.size() > 0);
  auto e_nth{entries};
  const std::size_t n = e_nth.size();

  auto it = e_nth.begin() + n / 2;

  std::nth_element(e_nth.begin(), it, e_nth.end());

  return n % 2 == 0 ? (*it + *(std::max_element(e_nth.begin(), it))) / 2.0 : *it;
}

int main() {
  int N{1'000'000};
  double gamma{2.0};

  std::cout << "entries vector:\n";

  auto entries = generate_entries(N, gamma);
  std::cout << "- size: " << entries.size() << '\n';

  double mu = mean(entries);
  std::cout << "- mean: " << mu << " (expected: " << 1.0 / gamma << ")\n";

  double exp_med{std::log(2.0) / gamma};

  double med = median(entries);
  std::cout << "- median: " << med << " (expected: " << exp_med << ")\n";

  double med_nth = median_nth(entries);
  std::cout << "- median (nth_element): " << med_nth
            << " (expected: " << exp_med << ")\n";
}
