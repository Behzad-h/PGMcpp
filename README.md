# PGMcpp : PRIMED Grid Modelling (in C++)

    Anthony Truelove MASc, P.Eng.
    email:   gears1763@tutanota.com
    github:  gears1763-2

***See license terms***


This is a microgrid modelling code, which can be used to assess the economic and
environmental impacts of integrating renewable energy production and storage assets 
into an otherwise isolated microgrid (presumably reliant on diesel, or other
fuel-based, generation to begin with).

The Pacific Regional Institute for Marine Energy Discovery (PRIMED): <https://onlineacademiccommunity.uvic.ca/primed/><br>
The Institute for Integrated Energy Systems (IESVic): <https://www.uvic.ca/research/centres/iesvic/index.php>

--------


## Contents

In the directory for this project, you should find this README, a LICENSE file, a
makefile, a TODO list, and the following sub-directories:

    data/           to hold sample input data for testing and examples
    docs/           to hold various documentation
    header/         to hold header files
    projects/       to hold PGMcpp projects (ships with some example projects)
    pybindings/     to hold source and setup files for building Python 3 bindings (ships with some pre-compiled bindings)
    source/         to hold source files
    test/           to hold the source files for a suite of tests
    third_party/    to hold third party content used in the development of PGMcpp

--------


## Key Features

  * A time-domain microgrid modelling code that will work with any time series data (can be non-uniform series of arbitrary length).
  * Support for modelling diesel generators. This includes modelling fuel consumption and emissions. Any number of generators can be modelled.
  * Support for modelling solar, wind, tidal, and wave renewable production assets. Any number of assets can be modelled.
  * Any number of renewable resource time series can be modelled, with resources being associated with chosen production assets.
  * Support for modelling lithium ion battery energy storage. This includes modelling use-based battery degradation dynamics.
  * Support for modelling both load following and cycle charging dispatch control.
  * Can be either accessed natively in C++, or accessed in Python 3 by way of the provided bindings.

--------


## Setup

### C++

To build PGMcpp, you can simply

    make PGMcpp

On Windows, this was achieved using the environment provided by the MSYS2 project (see 
<https://www.msys2.org/>).

### Python 3

The `pybindings/` sub-directory contains the infrastructure needed to build Python 3 
bindings for PGMcpp (for more details, see `pybindings/README.md`). In summary, you can 
build the bindings by way of

    python(3) setup.py build_ext --inplace

depending on your setup.

--------


## Documentation

Documentation for this project is auto-generated using Doxygen
(<https://www.doxygen.nl/>). HTML documentation can be found in
`docs/PGMcpp_manual_html.7z`, and LaTeX documentation can be found in
`docs/PGMcpp_manual_LaTeX.pdf`. Additionally, shareable references are included in
`docs/refs/`, and all references are listed in `docs/refs.bib`.

If you do make changes to the code, you can easily generate updated documentation by way
of

    make docs

--------


## Testing

Invoking

    make PGMcpp

will build PGMcpp and then run the suite of tests defined in `test/` (for more details,
see `test/README.md`). Additionally, `pybindings/test.py` is provided to test the Python
3 bindings for PGMcpp (for more details, see `pybindings/README.md`).

The provided makefile and all source code was successfully tested on the following OS
and architectures:

    Operating System: Linux Mint 21.2
              Kernel: Linux 6.5.6-76060506-generic
        Architecture: x86-64

    Operating System: Windows 11 Home
             Version: 22H2
        Architecture: 64-bit OS, x64-based processor


The following compilers were used in testing:

    g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0
    g++ (Rev10, Built by MSYS2 project) 13.2.0
    Microsoft C/C++ Optimizing Compiler Version 19.37.32825


PGMcpp has the following dependencies (by compiler link):

    -lpthread

--------
