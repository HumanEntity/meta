# Meta

Meta is simple STB-like library for managing meta data in custom file format.
The format supports strings, integers and JSON like objects.
No float support because of possible precision problems.

`meta.h` contains parser (string -> c) and composer (c -> string).
To define implementation define `META_IMPL` preprocessor symbol.

If you prefer different allocator than `malloc` define `META_MALLOC`, `META_FREE`, `META_REALLOC`.
