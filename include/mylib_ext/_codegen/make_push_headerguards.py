#!/usr/bin/python3

import textwrap

from pylib import iter_headerguards

content = ""
for headerguard in iter_headerguards():


    content += textwrap.dedent(f"""\

        #pragma push_macro("{ headerguard }")
        #ifndef MYLIB_{ headerguard }_HEADERGUARD
        #undef { headerguard }
        #endif // #ifndef MYLIB_{ headerguard }_HEADERGUARD
    """)

with open(f"detail/push_headerguards.hh", "w") as f:
    f.write(content)
