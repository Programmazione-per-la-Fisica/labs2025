#include <cstdlib>
#include <exception>
#include <iostream>
#include <limits>

#include "regression.hpp"

int main() {
  try {
    pf::Regression data{};

    std::cout << "Valid commands: \n"
              << "- add a point [a x y]\n"
              << "- remove a point [r x y]\n"
              << "- execute the fit [x]\n"
              << "- quit [q]\n";

    char cmd{};

    while (std::cin >> cmd) {
      double x{};
      double y{};

      if (cmd == 'a' && std::cin >> x >> y) {
        data.add(pf::Point{x, y});
      } else if (cmd == 'r' && std::cin >> x >> y) {
        if (!data.remove(pf::Point{x, y})) {
          std::cout << "Point (" << x << ", " << y
                    << ") not found in the data sample, not removed\n";
        }
      } else if (cmd == 'x') {
        auto const result = data.fit();
        std::cout << "Fit result: y = " << result.A << " + (" << result.B
                  << ") * x\n";
      } else if (cmd == 'q') {
        return EXIT_SUCCESS;
      } else {
        std::cout << "Bad format, insert a new command\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
    }

  } catch (std::exception const& e) {
    std::cerr << "Caught exception: '" << e.what() << "'\n";
    return EXIT_FAILURE;
  } catch (...) {
    std::cerr << "Caught unknown exception\n";
    return EXIT_FAILURE;
  }
}
