#!/usr/bin/python3

import textwrap

from pylib import iter_headerguards

content = ""
for headerguard in iter_headerguards():

    content += textwrap.dedent(f"""\

        #ifdef {headerguard}
        #define MYLIB_{headerguard}_HEADERGUARD
        #endif // #ifdef {headerguard}
        #pragma pop_macro("{headerguard}")
    """)

with open(f"detail/pop_headerguards.hh", "w") as f:
    f.write(content)
