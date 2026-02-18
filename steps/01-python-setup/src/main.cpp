/**
@file main.cpp
@brief Example source file for generating simple doxygen/sphinx/breathe
documentation
*/
#include "my-math.hpp"
#include <iostream>

namespace ds {

/// @brief  struct 1 \f$\lambda\f$
struct struct1 {

  /// @brief \f$ \sum_{i=1}^n x^2 - x + 2 \f$
  double x;
};

} // namespace ds

/// @brief  struct2e\f$\mu\f$
struct struct2 {

  /// @brief \f$ \sum_{i=1}^n x^3 - x + 5 \f$
  double y;
};

/**
 * @class dog
 * @brief Dog Object \f$ \int_0^t x^2 dx \f$
 *
 */
class dog {

public:
  int x;
};

int main() {

  std::cout << "Hello, World!!" << std::endl;
  int x = add(3, 4);
  return 0;
}
