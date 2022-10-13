#!/usr/bin/python3

import textwrap

from pylib import iter_macros

content = ""
for macro in iter_macros():
    content += textwrap.dedent(f"""\

        #ifdef {macro}

          #ifndef MYLIB_INTERNAL_HAS_{macro}
            #define MYLIB_INTERNAL_HAS_{macro}

            #ifdef MYLIB_EXTERNAL_1ST_{macro}
              #pragma pop_macro("{macro}")
            #endif

            #ifndef MYLIB_EXTERNAL_HAS_{macro}
              #ifndef MYLIB_INTERNAL_1ST_{macro}
                #define MYLIB_INTERNAL_1ST_{macro}
              #endif
            #endif

          #endif // #ifndef MYLIB_INTERNAL_HAS_{macro}

          #ifndef MYLIB_EXTERNAL_HAS_{macro}
            #pragma push_macro("{macro}")
            #undef {macro}
          #endif

        #endif // #ifdef {macro}
    """)

with open(f"detail/pop_macros.hh", "w") as f:
    f.write(content)
