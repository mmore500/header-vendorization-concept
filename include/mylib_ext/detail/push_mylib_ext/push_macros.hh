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

  #if defined(LIB_THIS_HAS_EXT_MACRO) && defined(LIB_THAT_1ST_EXT_MACRO)
    #ifndef LIB_SUPPRESS_OUTSIDE_MACRO_WARNINGS
      #pragma message( \
        "EXT_MACRO defined first outside vendorized header," \
        " try changing inclusion order" \
      )
    #endif
  #endif

#else // #ifdef EXT_MACRO

  #ifdef LIB_THIS_HAS_EXT_MACRO
    #pragma pop_macro("EXT_MACRO")
  #endif // #ifdef LIB_THIS_HAS_EXT_MACRO

#endif // #ifdef EXT_MACRO
