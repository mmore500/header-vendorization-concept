#!/usr/bin/python3

import textwrap

content = ""
for macro in [
    "EXT_MACRO",
]:
    content += textwrap.dedent(f"""\
        #ifdef {macro}

          #ifndef MYLIB_THAT_HAS_{macro}
            #define MYLIB_THAT_HAS_{macro}
            #ifndef MYLIB_THIS_HAS_{macro}
              #define MYLIB_THAT_1ST_{macro}
            #endif
          #endif

          #ifndef MYLIB_THIS_HAS_{macro}
            #pragma push_macro("{macro}")
            #undef {macro}
          #endif

          #if defined(MYLIB_THIS_HAS_{macro}) && defined(MYLIB_THAT_1ST_{macro})
            #ifndef MYLIB_SUPPRESS_OUTSIDE_MACRO_WARNINGS
              #pragma message( \\
                "{macro} defined first outside vendorized header," \\
                " try changing inclusion order" \\
              )
            #endif
          #endif

        #else // #ifdef {macro}

          #ifdef MYLIB_THIS_HAS_{macro}
            #pragma pop_macro("{macro}")
          #endif // #ifdef MYLIB_THIS_HAS_{macro}

        #endif // #ifdef {macro}
    """)

with open(f"push_macros.hh", "w") as f:
    f.write(content)
