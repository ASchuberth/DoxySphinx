/** 
Example source file for generating simple doxygen/sphinx/breathe documentation
*/
#include <iostream>

namespace ds {

/// @brief  struct 1 \f$\lambda\f$
struct struct1 {

  /// @brief \f$ \sum_{i=1}^n x^2 - x + 2 \f$
  double x;
};

} // namespace ds

/// @brief  struct 2 \f$\mu\f$
struct struct2 {

  /// @brief \f$ \sum_{i=1}^n x^3 - x + 5 \f$
  double y;
};

int main() {

  std::cout << "Hello, World!" << std::endl;
  return 0;
}