# Bonnor-Ebert

<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
[![All Contributors](https://img.shields.io/badge/all_contributors-1-orange.svg?style=flat-square)](#contributors-)
<!-- ALL-CONTRIBUTORS-BADGE:END -->

![Operating Systems](https://img.shields.io/badge/OS-Linux%20%7C%20MacOS%20%7C%20Windows-lightgrey)
![License](https://img.shields.io/github/license/cosmofico97/BonnorEbert)
![Pulls](https://img.shields.io/github/issues-pr/cosmofico97/BonnorEbert)
![CI](https://img.shields.io/github/workflow/status/cosmofico97/BonnorEbert/CMake)
![Top Language](https://img.shields.io/github/languages/top/cosmofico97/BonnorEbert)
![Version](https://img.shields.io/github/v/release/cosmofico97/BonnorEbert)
![Commits](https://img.shields.io/github/commit-activity/m/cosmofico97/BonnorEbert)
![Size](https://img.shields.io/github/repo-size/cosmofico97/BonnorEbert)

Bonnor-Ebert is a simple C++ program that solves the Bonnor-Ebert differential equation

![Bonnor-Ebert_equation](rsc/Bonnor-Ebert_equation.svg)

with two possible algorithms: Euler and classic Runge-Kutta. The output file `Bonnor-Ebert_Eulero.dat`/ `Bonnor-Ebert_RK.dat` contains also the values of the first derivate `ψ'(ξ)` , concentration parameter `g_0` and `f_0`.
This data may be easily visualize thanks to the Jupyter Notebook file `Bonnor-Ebert.ipynb`. 

## Table of contents
- [Bonnor-Ebert](#bonnor-ebert)
  - [Table of contents](#table-of-contents)
  - [Requirements](#requirements)
  - [Mathematical treatment](#mathematical-treatment)
  - [License](#license)
  - [Contributors ✨](#contributors-)


## Requirements

In order to build the software from the source code here provided, you will need:
* [`cmake`](https://cmake.org/) (version >= 3.12);
* A `C++17` compiler;

This project uses the header-only [`Argh!`](https://github.com/adishavit/argh) library, which is already included in this repository in `include/argh.h`;therefore, you do not need to install it on your system.

## Mathematical treatment

The original equation can be rewrited in this simple system:

![BE_system](rsc/BE_system.svg)

So, with the basic treatment of the differential equation numerical solutions:

![BE_system](rsc/BE_num-system.svg)

## License

Bonnor-Ebert is free software, and it is released under version 3 of the [GNU General Public License](https://www.gnu.org/licenses/gpl-3.0.html).



## Contributors ✨

Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tr>
    <td align="center"><a href="https://github.com/teozec"><img src="https://avatars.githubusercontent.com/u/44500371?v=4" width="100px;" alt=""/><br /><sub><b>Matteo Zeccoli Marazzini</b></sub></a><br /><a href="#ideas-Matteo-Zeccoli-Marazzini" title="Ideas, Planning, & Feedback">🤔</a> <a href="#tool-Matteo-Zeccoli-Marazzini" title="Tools">🔧</a></td>
  </tr>
</table>

<!-- markdownlint-restore -->
<!-- prettier-ignore-end -->

<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!

