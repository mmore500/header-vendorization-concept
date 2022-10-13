
#ifdef EXT_MACRO

  #ifndef MYLIB_EXTERNAL_HAS_EXT_MACRO
    #define MYLIB_EXTERNAL_HAS_EXT_MACRO
    #ifndef MYLIB_INTERNAL_HAS_EXT_MACRO
      #define MYLIB_EXTERNAL_1ST_EXT_MACRO
    #endif
  #endif

  #ifndef MYLIB_INTERNAL_HAS_EXT_MACRO
    #pragma push_macro("EXT_MACRO")
    #undef EXT_MACRO
  #endif

  #if defined(\
    MYLIB_INTERNAL_HAS_EXT_MACRO) && defined(MYLIB_EXTERNAL_1ST_EXT_MACRO\
  )
    #ifndef MYLIB_SUPPRESS_OUTSIDE_MACRO_WARNINGS
      #pragma message(\
        "EXT_MACRO defined first outside vendorized header,"\
        " try changing inclusion order"\
      )
    #endif
  #endif

#else // #ifdef EXT_MACRO

  #ifdef MYLIB_INTERNAL_HAS_EXT_MACRO
    #pragma pop_macro("EXT_MACRO")
  #endif // #ifdef MYLIB_INTERNAL_HAS_EXT_MACRO

#endif // #ifdef EXT_MACRO
