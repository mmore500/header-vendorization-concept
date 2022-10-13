#define ext mylib::ext

#pragma push_macro("EXT_PRINT_MACRO_HPP")
#ifndef MYLIB_EXT_PRINT_MACRO_HPP
#undef EXT_PRINT_MACRO_HPP
#endif // #ifndef MYLIB_EXT_PRINT_MACRO_HPP

#pragma push_macro("EXT_RETURN_MACRO_HPP")
#ifndef MYLIB_EXT_RETURN_MACRO_HPP
#undef EXT_RETURN_MACRO_HPP
#endif // #ifndef MYLIB_EXT_RETURN_MACRO_HPP

#pragma push_macro("EXT_DEFINE_MACRO_HPP")
#ifndef MYLIB_EXT_DEFINE_MACRO_HPP
#undef EXT_DEFINE_MACRO_HPP
#endif // #ifndef MYLIB_EXT_DEFINE_MACRO_HPP

#ifdef EXT_MACRO

  #ifndef LIB_THAT_HAS_EXT_MACRO
    #define LIB_THAT_HAS_EXT_MACRO
    #ifndef LIB_THIS_HAS_EXT_MACRO
      #define LIB_THAT_1ST_EXT_MACRO
    #endif
  #endif

  #ifndef LIB_THIS_HAS_EXT_MACRO
    #pragma push_macro("EXT_MACRO")
    #undef EXT_MACRO
  #endif

#else // #ifdef EXT_MACRO

  #ifdef LIB_THIS_HAS_EXT_MACRO
    #pragma pop_macro("EXT_MACRO")
  #endif // #ifdef LIB_THIS_HAS_EXT_MACRO

#endif // #ifdef EXT_MACRO
