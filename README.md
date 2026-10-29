# ft_printf

A small reimplementation of formatted output in C, developed as a 42 school project. The library exposes `ft_printf` and writes its output to standard output.

## Features

The format dispatcher handles these conversions:

| Conversion | Value |
| --- | --- |
| `%c` | Character |
| `%s` | String |
| `%d`, `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x`, `%X` | Lowercase or uppercase hexadecimal |
| `%p` | Pointer address |
| `%%` | Literal percent sign |

The function returns the number of characters it counts as printed. This implementation covers the conversions above; width, precision, floating-point conversions, and the full standard `printf` flag syntax are outside its scope.

## Build

Requires GCC, Make, and `ar` on a Unix-like system:

```sh
make    # creates libftprintf.a
```

Available maintenance targets: `make clean`, `make fclean`, and `make re`.

## Usage

Create `example.c` in the repository root:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s: %d%%\n", "42", 100);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror example.c -L. -lftprintf -o example
./example
```

See [ft_printf.c](ft_printf.c) for format dispatch and [ft_printf.h](ft_printf.h) for the interface.

## Concepts practiced

Variadic arguments with `stdarg.h`, format parsing, number conversion, character counting, and reusable static libraries.
