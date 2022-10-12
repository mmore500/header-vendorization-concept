#ifndef EXT_PRINT_MACRO_HPP
#define EXT_PRINT_MACRO_HPP

#include <iostream>

#include "define_macro.hpp"

namespace ext {

void print_macro() {
  std::cout << EXT_MACRO << '\n';
  std::cout << "user library" << '\n';
}

} // namespace ext

#endif // #define EXT_PRINT_MACRO_HPP
