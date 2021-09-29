# bx-workspaces-ci

A collection of [IAR Embedded Workbench][url-ew] workspaces for experimentation when building projects with the [IAR Build Tools][url-bx] in CI scenarios.

This repository is used as a [git submodule][url-git-sub] on the CI-related tutorials available at [https://github.com/IARSystems][url-gh].


Currently available ready-made projects:

| __Architecture__                          | __Minimum version__     |
| :----------                               | :---------------        |
| [`arm`][url-ewarm]                        | 8.50.6                  |
| [`armfs`][url-ewarmfs]                    | 8.50.10                 |
| [`riscv`][url-ewriscv]                    | 1.40.1                  |
| [`rh850`][url-ewrh850]                    | 2.21.1                  |
| [`rl78`][url-ewrl78]                      | 4.21.1                  |
| [`rx`][url-ewrx]                          | 4.20.1                  |

All these architecture-wise projects rely on the same portable C codebase found in [portable](portable). 

>:warning: The code was designed to generate compiler warnings and some rule violations for demonstration purposes.

<!-- links -->
[url-ew]:         https://iar.com/products/architectures
[url-bx]:         https://iar.com/bx
[url-gh]:         https://github.com/iarsystems 
[url-git-sub]:    https://git-scm.com/docs/git-submodule 
[url-ewarm]:      https://iar.com/ewarm
[url-ewarmfs]:    https://iar.com/products/requirements/functional-safety/iar-embedded-workbench-for-arm-functional-safety
[url-ewriscv]:    https://iar.com/ewriscv
[url-ewrh850]:    https://iar.com/ewrh850
[url-ewrl78]:     https://iar.com/ewrl78
[url-ewrx]:       https://iar.com/ewrx
