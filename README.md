# bx-workspaces-ci

### Description

A collection of [IAR Embedded Workbench][url-ew] workspaces (`.eww`) containing example projects (`.ewp`), suitable for experimentation when building with the [IAR Build Tools][url-bx] within CI (Continuous Integration) scenarios.

This repository is used in many CI-related tutorials available [@IARSystems][url-gh] where it is mentioned.

For each supported target architecture, there are 3 projects:
- library.ewp
- componentA.ewp
- componentB.ewp

All the projects rely on the same portable C sources found in [portable](portable). 

>:bulb: The portable C code should build with no errors and no warnings according to the __C Language Standard__.

>:warning: The portable C code was intentionaly designed to generate certain violations when performing __Static Code Analysis with the IAR C-STAT__, for demonstration purposes.


### Required versions
The minimum versions for the IAR Build Tools in which the projects (`.ewp`) will build when using __iarbuild__ are:

| __Target Architecture__       | __Minimum version__ |
| :----------                   | :---------------    |
| [`arm`][url-ewarm]            | 8.50.6              |
| [`riscv`][url-ewriscv]        | 1.40.1              |
| [`rh850`][url-ewrh850]        | 2.21.1              |
| [`rl78`][url-ewrl78]          | 4.21.1              |
| [`rx`][url-ewrx]              | 4.20.1              |


## Preventing build breakages
When working with bigger teams on bigger code bases it is not uncommon that modifications on shared resources clashes and the build becomes broken. There are many ways in which this can happen.

After finishing a CI-related tutorial from [@IARSystems][url-gh], you should have this repository imported into your Git server. Now you can simulate an event where newly introduced code breaks the build and in which CI system will help you on spotting where it got broken.

### Development Environment
For a project that is developed using Git for its version control, an external Git client (e.g. [Git for Windows](https://gitforwindows.org/), [TortoiseGit](https://tortoisegit.org/), [GitHub Desktop](https://desktop.github.com/), [Sourcetree](https://www.sourcetreeapp.com/), etc.) can be used alongside the __IAR Embedded Workbench IDE__.

>:bulb: Alternatively it is possible to use [Visual Studio Code](https://code.visualstudio.com/) which comes with an integrated Git client alongisde the [iar-vsc-build]() and the [iar-vsc-debug]() extensions.

### Preparing the projects for development

1. Use the Git client of your choice to clone the repository from your private Git server which is monitored by your CI controller to your Windows Desktop where there is an instance of the corresponding __IAR Embedded Workbench IDE__ installed.
2. In the __IAR Embedded Workbench__, open the corresponding `<arch>/workspace.eww` file for the target architecture in use.
3. Right-click on each project in the workspace and choose __Make__. All the 3 projects should build with no errors.

### Creating a new feature for component B
At some point the __componentB__ required a change in which its `DATATYPE` had to change from `int32_t` to `uint32_t` for holding values greater than `0x7FFF_FFFF`.

1. Using your git client, checkout a feature branch. (e.g. __dev-componentB__).
2. Right-click on the __componentB__ project and __Set as Active__.
3. Unfold the __componentB__ project tree and double-click on its __componentB.c__ file so it will open in the code editor.
4. On the line that reads `#include "library.h"`, right-click kand choose __Open "library.h"__.
5. Find `#define DATATYPE int32_t` and replace it with `#define DATATYPE uint32_t`.
6. Rebuild the __library__ project. It should build with no errors.
7. Rebuild the __componentB__. It should build with no errors.

>:bulb: Optionally you can use the IAR C-SPY Debugger to debug __componentB__.

### Pushing the changes to the project's repository
Once we're satisfied with the changes
1. Commit all changes to the local git repository.
2. Push the __dev-componentB__ branch back to the git origin.

### What happened?
Going back to the CI controller, changes performed to the git origin repository should have been automatically detected.

Has the pipeline succeeded?

The change we have performed worked for __componentB__ although, as the __library__ was a shared asset, this change compromised __componentA__. As we were focused on developing __componentB__, we completely forgot about other parts of a bigger system.

From the reports provided by automated pipeline in the CI controller, it is possible to spot which changes might cause the build to break, preventing them from being merged into the production branch.

## Conclusion
This was only one very simple example. There are so many other ways for breaking builds. You're going to naturally discover them during your actual development journey. The CI infrastructure of your choice should help you to be focused on your work and then to figure out if anything else gets broken upon changes to the code. With a proper infrastructure for automated workflows, your organization will be able to spot issues in the broader spectrum faster, while delivering better results in the long run.


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
