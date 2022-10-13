#undef ext

#ifdef EXT_PRINT_MACRO_HPP
#define MYLIB_EXT_PRINT_MACRO_HPP
#endif // #ifdef EXT_PRINT_MACRO_HPP
#pragma pop_macro("EXT_PRINT_MACRO_HPP")

#ifdef EXT_RETURN_MACRO_HPP
#define MYLIB_EXT_RETURN_MACRO_HPP
#endif // #ifdef EXT_RETURN_MACRO_HPP
#pragma pop_macro("EXT_RETURN_MACRO_HPP")

#ifdef EXT_DEFINE_MACRO_HPP
#define MYLIB_EXT_DEFINE_MACRO_HPP
#endif // #ifdef EXT_DEFINE_MACRO_HPP
#pragma pop_macro("EXT_DEFINE_MACRO_HPP")

#ifdef EXT_MACRO

  #ifndef LIB_THIS_HAS_EXT_MACRO
    #define LIB_THIS_HAS_EXT_MACRO

    #ifdef LIB_THAT_1ST_EXT_MACRO
      #pragma pop_macro("EXT_MACRO")
    #endif

    #ifndef LIB_THAT_HAS_EXT_MACRO
      #ifndef LIB_THIS_1ST_EXT_MACRO
        #define LIB_THIS_1ST_EXT_MACRO
      #endif
    #endif

  #endif // #ifndef LIB_THIS_HAS_EXT_MACRO

  #ifndef LIB_THAT_HAS_EXT_MACRO
    #pragma push_macro("EXT_MACRO")
    #undef EXT_MACRO
  #endif

#endif // #ifdef EXT_MACRO
