#!/usr/bin/python3.10

from glob import glob
import os
import re
import textwrap
import typing

def iter_header_paths() -> typing.Iterator[str]:
    yield from glob(
        "**/*.hpp",
        recursive=True,
        root_dir="../../third-party/ext",
    )

def setup_one_facade(header_path: str) -> None:
    header_guard = (
        "MYLIB_EXT_"
        + header_path.upper().replace("/", "_").replace(".", "_")
    )
    content = textwrap.dedent(f"""\
        #ifndef {header_guard}
        #define {header_guard}

        #ifdef MYLIB_VENDORIZE_EXT
        #include "detail/push_mylib_ext.hh"
        #endif // #ifdef MYLIB_VENDORIZE_EXT

        #include "../../third-party/ext/{header_path}"

        #ifndef MYLIB_VENDORIZE_EXT
        namespace mylib_ext = ext;
        #endif // #ifndef MYLIB_VENDORIZE_EXT

        #ifdef MYLIB_VENDORIZE_EXT
        #include "detail/pop_mylib_ext.hh"
        #endif // #ifdef MYLIB_VENDORIZE_EXT

        #endif // #ifndef {header_guard}
    """)

    if os.path.dirname(header_path):
        os.makedirs(os.path.dirname(header_path), exist_ok=True)
    with open(header_path, "w") as header_file:
        header_file.write(content)

for header_path in iter_header_paths():
    setup_one_facade(header_path)
