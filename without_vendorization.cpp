#include <iostream>

#include "include/mylib/do_print_macro.hpp"
#include "include/mylib/do_return_macro.hpp"
#include "include/mylib/do_use_macro.hpp"

// #include "ext/print_macro.hpp"

int main() {

  mylib::do_print_macro();

  ext::print_macro();

  std::cout << mylib::do_return_macro() << '\n';
  std::cout << mylib::do_use_macro() << '\n';

  #ifdef MYLIB_THIS_1ST_EXT_MACRO
  std::cout << "MYLIB_THIS_1ST_EXT_MACRO" << '\n';
  #endif

  #ifdef MYLIB_THAT_1ST_EXT_MACRO
  std::cout << "MYLIB_THAT_1ST_EXT_MACRO" << '\n';
  #endif

}
