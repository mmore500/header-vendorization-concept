
#ifdef EXT_MACRO

  #ifndef MYLIB_THIS_HAS_EXT_MACRO
    #define MYLIB_THIS_HAS_EXT_MACRO

    #ifdef MYLIB_THAT_1ST_EXT_MACRO
      #pragma pop_macro("EXT_MACRO")
    #endif

    #ifndef MYLIB_THAT_HAS_EXT_MACRO
      #ifndef MYLIB_THIS_1ST_EXT_MACRO
        #define MYLIB_THIS_1ST_EXT_MACRO
      #endif
    #endif

  #endif // #ifndef MYLIB_THIS_HAS_EXT_MACRO

  #ifndef MYLIB_THAT_HAS_EXT_MACRO
    #pragma push_macro("EXT_MACRO")
    #undef EXT_MACRO
  #endif

#endif // #ifdef EXT_MACRO
