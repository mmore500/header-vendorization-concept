#!/usr/bin/python3

import textwrap

from pylib import iter_macros

content = ""
for macro in iter_macros():
    content += textwrap.dedent(f"""\

        #ifdef {macro}

          #ifndef MYLIB_EXTERNAL_HAS_{macro}
            #define MYLIB_EXTERNAL_HAS_{macro}
            #ifndef MYLIB_INTERNAL_HAS_{macro}
              #define MYLIB_EXTERNAL_1ST_{macro}
            #endif
          #endif

          #ifndef MYLIB_INTERNAL_HAS_{macro}
            #pragma push_macro("{macro}")
            #undef {macro}
          #endif

          #if defined(\\
            MYLIB_INTERNAL_HAS_{macro}) && defined(MYLIB_EXTERNAL_1ST_{macro}\\
          )
            #ifndef MYLIB_SUPPRESS_MACRO_INSEEP_WARNINGS
            #ifndef MYLIB_{macro}_INSEEP_WARNING
              #define MYLIB_{macro}_INSEEP_WARNING
              #pragma message(\\
                "{macro} defined first outside vendorized header,"\\
                " so outside definition will be used inside vendorized header"\\
                " on subsequent includes of the vendorized header"\\
                " --- if causes problems, try changing header include order"\\
              )
            #endif
            #endif
          #endif

        #else // #ifdef {macro}

          #ifdef MYLIB_INTERNAL_HAS_{macro}
            #pragma pop_macro("{macro}")
          #endif // #ifdef MYLIB_INTERNAL_HAS_{macro}

        #endif // #ifdef {macro}
    """)

with open(f"detail/push_macros.hh", "w") as f:
    f.write(content)
