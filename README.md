# Custom STRING.H

This is a study project.

## Objective:
* Reimplement the standard functions from the `<string.h>`
* Raise flags for GCC to check conversion for the types to be precise
* ~~Maintain two main files including standard or custom headers with similar functionality~~
* ~~Compile both main files to binaries that must result in identical behaviour~~
> &nbsp;&nbsp; _Since GCC will not allow to use reserved names for the custom functions:_
* Selectively include the custom `"string.h"` header with the custom functions
* Maintain Makefile scenarios for using both the standard and the custom header
* Achieve identical byte-for-byte behaviour in both scenarios
## Additions:
* Learn to arrange a complex project with external header/source files
* Learn to maintain a Makefile
* Train using Git commands
* Learn to maintain a GitHub repo
---
## Notes:
* The names of standard functions are reserved in **GCC**, so it will throw an error if you try to name your custom function same way, no matter if the corresponding header is included or not.
* There is **Section 3 of manpages** that is dedicated to the standard C functions, so with a command like `man 3 strlen` you get a synopsis of such a function.
* Dangerous usage of two enum counters, if DEMO_COUNT and NUMBER mismatch, it will cause segmentation fault.
* Require refactoring to put all enums, counters and function pointers in order.
