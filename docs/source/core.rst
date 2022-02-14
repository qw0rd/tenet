
libcore - the core freestanding kernel library
----------------------------------------------

This library contains core functions that make kernel development easy.

Utilities it provides:

* Memory related functions (memcpy, memcmp, memmove, ...)
* String related functions (strcpy, strlen, ...)
* Formatting functions (sprintf, printk)

All the provided functions are freestanding except printk.

`printk` assumes that `putchar` symbol exists.

The definition of `putchar` should be provided by the library user.

.. doxygenfunction:: memcpy
.. doxygenfunction:: sprintf
.. doxygenfunction:: printk

.. toctree::
    core/core


