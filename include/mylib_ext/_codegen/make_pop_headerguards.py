#!/usr/bin/python3

import textwrap

from pylib import iter_headerguards

content = "#ifdef MYLIB_VENDORIZE_EXT\n"
for headerguard in iter_headerguards():

    content += textwrap.dedent(f"""\

        #ifdef {headerguard}
        #define MYLIB_{headerguard}_HEADERGUARD
        #endif // #ifdef {headerguard}
        #pragma pop_macro("{headerguard}")
    """)

content += "\n"
content += "#endif // #ifdef MYLIB_VENDORIZE_EXT"
content += "\n"

with open(f"detail/pop_headerguards.hh", "w") as f:
    f.write(content)
