# IAR Embedded Workbench Workspaces for CI
A collection of [IAR Embedded Workbench][url-ew] workspaces (`.eww`) containing example projects (`.ewp`), suitable for experimentation when building pre-existing projects with the [IAR Build Tools][url-bx] within CI (Continuous Integration) scenarios.

This repository is used in many CI-related tutorials available [@IAR][url-gh] where it is mentioned. After going through one of such tutorials, you should have this repository imported into your private Git server.

## Introduction
When working in development teams or on reasonably big code bases it is not uncommon that modifications made on shared sources clashes and the projects start showing coding defects. There are many ways in which this can happen.

A common practice in such environments is to adopt a CI system which will evolve with your projects and will also help you on spotting problems before the production code base gets broken.

## Software requirements
For the widest backward compatibility, the supplied projects were all created using earlier versions of the **IAR Embedded Workbench**:

| __Target Architecture__      | __Version__      |
| :--------------------------- | :--------------- |
| [`arm`][url-ewarm]           | 8.50.6           |
| [`avr`][url-ewavr]           | 8.10.1           |
| [`riscv`][url-ewriscv]       | 1.40.1           |
| [`rh850`][url-ewrh850]       | 2.21.1           |
| [`rl78`][url-ewrl78]         | 4.21.1           |
| [`rx`][url-ewrx]             | 4.20.1           |

So that they can be used with any version of the **IAR Build Tools**. Newer versions will automatically upgrade the project and create a backup copy.


## Description
In this repository source code tree, you will find workspaces with project examples for the target architectures supported in the IAR Build Tools.

### Project structure
In the `workspace` directory you will find a workspace file named after its related product's codename:
```
📁 workspace
 ┣ 📄 ewarm.eww
 ┣ 📄 ewavr.eww
 ┣ 📄 ewriscv.eww
 ┣ 📄 ewrh850.eww
 ┣ 📄 ewrl78.eww
 ┗ 📄 ewrx.eww
```

Those workspaces includes projects found within the `target` directory:
```
📁 targets
 ┣ 📁 arm
 ┃  ┣ 📄 library.ewp 
 ┃  ┣ 📄 test-crc16.ewp
 ┃  ┗ 📄 test-crc32.ewp
 ┣ 📁 avr
 ┣ 📁 riscv
 ┣ 📁 rh850
 ┣ 📁 rl78
 ┗ 📁 rx
```

### Notes regarding the projects source code
The supplied example projects use portable C sources compliant with the C Language Standard. While such sources can be compiled with the IAR C/C++ Compiler without generating any diagnostic messages (warnings/errors), the C Language Standard comes with undefined behaviors which are, in most cases, unsuitable for embedded applications. For that reason it is highly recommended to use static code analyzers which can help in shipping embedded applications with the professional robustness they deserve. **IAR C-STAT** is an static analysis tool which is offered as an add-on to the compiler. The source code in the projects was designed to purposedly generate coding standard violations, for C-STAT demonstration purposes.

### Development Environment (Desktop)
While the IAR Embedded Workbench IDE doesn't come with an embedded Git client, it is possible to use a 3rd party client of your choice. If you need some suggestions:
* [TortoiseGit](https://tortoisegit.org/) -- (article: [TortoiseGit integration for Embedded Workbench IDE users](https://github.com/felipe-iar/ew-tortoise-integration))
* [GitHub Desktop](https://desktop.github.com/)
* [Sourcetree](https://www.sourcetreeapp.com/)
* [Git for Windows](https://gitforwindows.org/)
Alternatively IAR provides a set of [extensions](https://marketplace.visualstudio.com/publishers/iarsystems) for [Visual Studio Code](https://code.visualstudio.com/) which comes with an embedded git client.

### Cloning for development
1. Clone the bx-workspaces-ci from your private repository where you have the __IAR Embedded Workbench__ installed.
2. Select the corresponding `workspaces/ew<target>.eww` workspace for your product's target architecture and open it.
3. Make sure the projects build with no errors: go to __Project__ → __Batch build...__ (<kbd>F8</kbd>) and press the `  Make  ` button.

### A new feature-request has arrived
When a new feature (or bug fix) is scheduled, the Git workflow usually uses what is called a "feature branch". Generally the procedure below should apply.
1. Using your git client, checkout a new  feature branch (e.g., `dev-feat-x`).
2. Perform the required changes to the project to comply with the new feature requeest.
3. Build and test the project locally.
4. Commit the changes to the local cloned repository.
5. Push the `dev-feat-x` branch to the git remote repository (e.g., `origin`).

## Conclusion
This was only one very simple set of example projects. In real applications, as the complexity raises, lurking defects might end up in tragedies if not discovered and remedied during the earliest development stages. Having a CI system will help the whole team in detecting and preventing potentially catastrophic incidents. Conducting tests within automated workflows will certainly reduce costs and raise the overall code quality, from which the whole organization can benefit.


<!-- links -->
[url-ew]:         https://iar.com/products/architectures
[url-bx]:         https://iar.com/bx
[url-gh]:         https://github.com/iarsystems 
[url-git-sub]:    https://git-scm.com/docs/git-submodule 
[url-ewarm]:      https://iar.com/ewarm
[url-ewavr]:      https://iar.com/ewavr
[url-ewarmfs]:    https://iar.com/products/requirements/functional-safety/iar-embedded-workbench-for-arm-functional-safety
[url-ewriscv]:    https://iar.com/ewriscv
[url-ewrh850]:    https://iar.com/ewrh850
[url-ewrl78]:     https://iar.com/ewrl78
[url-ewrx]:       https://iar.com/ewrx
