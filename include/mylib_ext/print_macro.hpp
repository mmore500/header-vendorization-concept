#ifndef MYLIB_EXT_PRINT_MACRO_HPP
#define MYLIB_EXT_PRINT_MACRO_HPP

#ifdef MYLIB_VENDORIZE_EXT
#include "detail/push_mylib_ext.hh"
#endif // #ifdef MYLIB_VENDORIZE_EXT

#include "../../third-party/ext/print_macro.hpp"

#ifndef MYLIB_VENDORIZE_EXT
namespace mylib_ext = ext;
#endif // #ifndef MYLIB_VENDORIZE_EXT

#ifdef MYLIB_VENDORIZE_EXT
#include "detail/pop_mylib_ext.hh"
#endif // #ifdef MYLIB_VENDORIZE_EXT

#endif // #ifndef MYLIB_EXT_PRINT_MACRO_HPP
