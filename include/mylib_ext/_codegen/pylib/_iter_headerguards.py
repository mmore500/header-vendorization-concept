from glob import glob
import re
import typing

def iter_headerguards() -> typing.Iterator[str]:
    header_paths = glob("../../third-party/ext/**/*.hpp", recursive=True)
    for header_path in header_paths:
        with open(header_path) as header_file:
            yield from re.findall(
                r"^#ifndef ([A-Z_]+_HPP)$",
                header_file.read(),
                re.MULTILINE,
            )
