import typing

def iter_headerguards() -> typing.Iterator[str]:
    yield from  [
        "EXT_DEFINE_MACRO_HPP",
        "EXT_PRINT_MACRO_HPP",
        "EXT_RETURN_MACRO_HPP",
    ]
