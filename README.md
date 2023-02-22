# Bonnor-Ebert

<!-- ALL-CONTRIBUTORS-BADGE:START - Do not remove or modify this section -->
[![All Contributors](https://img.shields.io/badge/all_contributors-1-orange.svg?style=flat-square)](#contributors-)
<!-- ALL-CONTRIBUTORS-BADGE:END -->

![Operating Systems](https://img.shields.io/badge/OS-Linux%20%7C%20MacOS%20%7C%20Windows-lightgrey)
![License](https://img.shields.io/github/license/foglienimatteo/BonnorEbert)
![Pulls](https://img.shields.io/github/issues-pr/foglienimatteo/BonnorEbert)
![Top Language](https://img.shields.io/github/languages/top/foglienimatteo/BonnorEbert)
![Version](https://img.shields.io/github/v/release/foglienimatteo/BonnorEbert)
![Commits](https://img.shields.io/github/commit-activity/m/foglienimatteo/BonnorEbert)
![Size](https://img.shields.io/github/repo-size/foglienimatteo/BonnorEbert)

Bonnor-Ebert is a simple C++ program that solves the Bonnor-Ebert differential equation

![Bonnor-Ebert_equation](rsc/Bonnor-Ebert_equation.svg)

with two possible algorithms: Euler and classic Runge-Kutta. The output file `Bonnor-Ebert_Eulero.dat`/ `Bonnor-Ebert_RK.dat` contains also the values of the first derivate `ψ'(ξ)` , concentration parameter `g_0` and `f_0`.
This data may be easily visualize thanks to the Jupyter Notebook file `Bonnor-Ebert.ipynb`. 

## Table of contents
- [Bonnor-Ebert](#bonnor-ebert)
  - [Table of contents](#table-of-contents)
    - [Requirements](#requirements)
    - [Installation](#installation)
    - [Usage](#usage)
    - [Output file](#output-file)
    - [Visualization of the data](#visualization-of-the-data)
  - [Mathematical treatment](#mathematical-treatment)
  - [License](#license)
  - [Contributors ✨](#contributors-)


### Requirements

In order to build the software from the source code here provided, you will need:
* [`cmake`](https://cmake.org/) (version >= 3.12);
* A `C++17` compiler;

This project uses the header-only [`Argh!`](https://github.com/adishavit/argh) library, which is already included in this repository in `include/argh.h`;therefore, you do not need to install it on your system.

### Installation

First of all, copy the source code provided in this repository on your OS. You may clone the repository where it is built in, running in the command line
```bash
git clone https://github.com/foglienimatteo/BonnorEbert
```
or download the source code from the webpage https://github.com/foglienimatteo/BonnorEbert.


Hereafter, run the following shell commands from the project directory:
```bash
mkdir build
cd build
cmake ..
make
```
The executable file `Bonnor_Ebert` is generated in the `build` directory.

### Usage

In order to execute the `Bonnor_Ebert` file (inside the `build` directory), the syntax is the standar one:
```bash
./Bonnor_Ebert {euler/rungekutta} [options]
```

The command `euler` tells the program to solve the differential equation with the Euler method, while `rungekutta` with the classic Runge-Kutta one. You have to specify which between these two algorithms must be used.

The actual available options, for both `euler` and `rungekutta` commands, are the following:
- `-h, --help`: print the help message;
- `-s <step>, --step=<step>`: set the step measure to be used solving the differential equation;
- `-b <begin>, --begin=<begin>`: set the beginning value of `ξ`, where the algothims starts;
- `-e <end>, --end=<end>`: set the ending value of `ξ`, where the algorithm ends;
- `-c <cut>, --cut=<cut>`: set the  `ξ` value at which we wants to cut the Bonnor-Ebert sphere.

### Output file

Depending on the algorithm choosen, the output file (saved in the `build` directory) will be `Bonnor-Ebert_Eulero.dat` or `Bonnor-Ebert_RK.dat`.
For each of these files, the output data are organized in 6 columns; from left to right, they are:
- the iteration index of the algorithm `i=0,1,2,...`
- the corresponding `ξ` value
- the function value in that point, i.e. `ψ(ξ)`
- the first function derivate in that point, i.e. `ψ'(ξ)`
- the concentration parameter `g_0` if the cut of the Bonnor-Ebert sphere occurs at `ξ_0=ξ`;
-  the parameter `f_0` if the cut of the Bonnor-Ebert sphere occurs at `ξ_0=ξ`;

In a table form, the data are disposed like this: 

|![i](rsc/i.svg)  | ![xi](rsc/xi.svg) |![psi](rsc/psi_of_xi.svg)  | ![psip](rsc/dpsi-dxi_of_xi.svg) | ![g_0](rsc/g_0.svg)  | ![f_0](rsc/f_0.svg) |
|--------------|--------------|-------------|-------------|-------------|-------------|
|0   |    0.0001	| 0	          |0	          |0.9999	|0             |
|1   |	0.00011	| 0	          |1e-05	     |0.99989  |1.21e-13      |
|2   |	0.00012	| 1e-10	     |1.81818e-05	|0.99988	|2.61818e-13   |
|3   |	0.00013	| 2.81818e-10	|2.51515e-05	|0.99987	|4.25061e-13   |
|... |	...       | ...	     | ...	     |...	     |...           |

Here we rememeber the  definition of `g_0` and `f_0`:

|![g_0](rsc/g_0_definition.svg) |  | | |  | ![f_0](rsc/f_0_definition.svg) |
|--------------|-|-|-|-|--------------|


### Visualization of the data

In the main directory, it is provided a JupyterLab Notebook, called `Bonnor-Ebert.ipynb`, where the skeleton of the data plotting and analysis is provided.
Unfortunately, the notous curl in the `p_0/p_s` vs `(R_0/R_s)^3` does not appear clearly, probably for a computational mistake somewhere in the source code.  


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

