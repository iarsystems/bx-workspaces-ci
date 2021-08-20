# bx-workspaces-ci

A collection of [IAR Embedded Workbench](https://www.iar.com/products/architectures) workspaces for experimentation when building projects with the [IAR Build Tools](https://iar.com/bx) in CI scenarios.

This repository is used as a [git submodule](https://git-scm.com/docs/git-submodule) on the CI-related tutorials available at [https://github.com/IARSystems](https://github.com/IARSystems).


Currently available ready-made projects:

| __Architecture__                              | __Minimum version__     |
| :----------                                   | :---------------        |
| [`arm`](https://www.iar.com/ewarm)            | 8.50.6                  |
| [`riscv`](https://www.iar.com/ewriscv)        | 1.40.1                  |
| [`rh850`](https://www.iar.com/ewrh850)        | 2.21.1                  |
| [`rl78`](https://www.iar.com/ewrl78)          | 4.21.1                  |
| [`rx`](https://www.iar.com/ewrx)              | 4.20.1                  |

All these architecture-wise projects rely on the same portable C codebase found in [portable](portable). 

>:warning: The code was designed to generate compiler warnings and some rule violations for demonstration purposes.
