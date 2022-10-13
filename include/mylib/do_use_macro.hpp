#ifndef MYLIB_DO_USE_MACRO_HPP
#define MYLIB_DO_USE_MACRO_HPP

#include "../mylib_ext/define_macro.hpp"
#include "../mylib_ext/detail/push_macros.hh"

namespace mylib {

int do_use_macro() {
  return EXT_MACRO;
}

} // namespace mylib

#include "../mylib_ext/detail/pop_macros.hh"

#endif // #ifndef MYLIB_DO_USE_MACRO_HPP
