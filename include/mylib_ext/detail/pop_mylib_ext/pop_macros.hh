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
