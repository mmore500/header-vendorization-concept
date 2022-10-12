#include <iostream>


#include "include/mylib/do_print_macro.hpp"

#include "ext/print_macro.hpp"

#include "include/mylib/do_return_macro.hpp"


int main() {

  mylib::do_print_macro();

  ext::print_macro();

  std::cout << mylib::do_return_macro() << '\n';

}
