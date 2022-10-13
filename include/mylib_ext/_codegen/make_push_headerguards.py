#!/usr/bin/python3

import textwrap

content = ""
for headerguard in [
    "EXT_DEFINE_MACRO_HPP",
    "EXT_PRINT_MACRO_HPP",
    "EXT_RETURN_MACRO_HPP",
]:

    content += textwrap.dedent(f"""\

        #pragma push_macro("{ headerguard }")
        #ifndef MYLIB_{ headerguard }_HEADERGUARD
        #undef { headerguard }
        #endif // #ifndef MYLIB_{ headerguard }_HEADERGUARD
    """)

with open(f"detail/push_headerguards.hh", "w") as f:
    f.write(content)
