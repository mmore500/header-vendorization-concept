#!/usr/bin/python3

import textwrap

from pylib import iter_headerguards

content = "#ifdef MYLIB_VENDORIZE_EXT\n"
for headerguard in iter_headerguards():


    content += textwrap.dedent(f"""\

        #pragma push_macro("{ headerguard }")
        #ifndef MYLIB_{ headerguard }_HEADERGUARD
        #undef { headerguard }
        #endif // #ifndef MYLIB_{ headerguard }_HEADERGUARD
    """)

content += "\n"
content += "#endif // #ifdef MYLIB_VENDORIZE_EXT"
content += "\n"

with open(f"detail/push_headerguards.hh", "w") as f:
    f.write(content)
