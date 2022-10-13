#!/usr/bin/python3

import textwrap

content = ""
for headerguard in [
    "EXT_DEFINE_MACRO_HPP",
    "EXT_PRINT_MACRO_HPP",
    "EXT_RETURN_MACRO_HPP",
]:

    content += textwrap.dedent(f"""\

        #ifdef {headerguard}
        #define MYLIB_{headerguard}_HEADERGUARD
        #endif // #ifdef {headerguard}
        #pragma pop_macro("{headerguard}")
    """)

with open(f"pop_headerguards.hh", "w") as f:
    f.write(content)
