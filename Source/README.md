# make

This is the well known *gnu make* for classic Amiga, refactored to build against NDK3.2 and build and run standalone of the ixemul environment.

## [amigazen project](http://www.amigazen.com)

*A web, suddenly*

*Forty years meditation*

*Minds awaken, free*

**amigazen project** uses modern software development tools and methods to update and rerelease classic Amiga open source software. Our upcoming releases include a new AWeb, and a new Amiga Python 2.

Key to our approach is ensuring every project can be built with the same common set of development tools and configurations, so we created the ToolKit project to provide a standard configuration for Amiga development. All *amigazen project* releases will be guaranteed to build against the ToolKit standard so that anyone can download and begin contributing straightaway without having to tailor the toolchain for their own setup.

The original authors of the *gnu make* software are not affiliated with the amigazen project. This software is redistributed on terms described in the documentation.

Our philosophy is based on openness:

*Open* to anyone and everyone	- *Open* source and free for all	- *Open* your mind and create!

PRs for all of our projects are gratefully received at [GitHub](https://github.com/amigazen/). While our focus now is on classic 68k software, we do intend that all amigazen project releases can be ported to other Amiga-like systems including AROS and MorphOS where feasible.

## About ToolKit

**ToolKit** exists to solve the problem that most Amiga software was written in the 1980s and 90s, by individuals working alone, each with their own preferred setup for where their dev tools are run from, where their include files, static libs and other toolchain artifacts could be found, which versions they used and which custom modifications they made. Open source collaboration did not exist as we know it in 2025. 

**ToolKit** from amigazen project is a work in progress to make a standardised installation of not just the Native Developer Kit, but the compilers, build tools and third party components needed to be able to consistently build projects in collaboration with others, without each contributor having to change build files to work with their particular toolchain configuration. 

All *amigazen project* releases will released in a ready to build configuration according to the ToolKit standard.

Each component of **ToolKit** is open source and like *make* here will have it's own github repo, while ToolKit itself will eventually be released as an easy to install package containing the redistributable components, as well as scripts to easily install the parts that are not freely redistributable from archive.

## Requirements

- Amiga or Amiga-compatible computer with latest operating system software
- SAS/C 6.58 setup according to ToolKit standard
- NDK3.2R4

## Installation

- copy SDK/C/Make to SDK:C/Make

## To Do

- Add VBCC build
- Add unittests

## Contact 

- At GitHub https://github.com/amigazen/make-amiga
- on the web at http://www.amigazen.com/toolkit/ (Amiga browser compatible)
- or email toolkit@amigazen.com

## [Aminet.readme](https://www.aminet.net/package/dev/c/make-4.4.1)
----------------------------------------------------------------------------

Update to GNU Make to 4.4.1 - this is the very last commit before all Amiga
support was removed from the code. Therefore this is likely the last update
we will ever see on the Amiga unless someone reinstates all of the changes.

I made a few updates to get everything working again on the Amiga since it
had not been built on the Amiga for some years. My changes are available
here:

https://github.com/dmcoles/gnu_make_amiga

Darren Coles

----------------------------------------------------------------------------

This is a pure Amiga port of GNU Make. It needs no extra libraries or
anything. It has the following features (in addition to any features of
GNU Make):

- Runs Amiga-Commands with SystemTags() (Execute)
- Can run multi-line statements
- Allows to use Device-Names in targets:

        c:make : make.o

    is ok. To distinguish between device-names and target : or ::, MAKE
    looks for spaces. If there are any around :, it's taken as a target
    delimiter, if there are none, it's taken as the name of a device. Note
    that "make:make.o" tries to create "make.o" on the device "make:".
- Replaces @@ by a newline in any command line:

        if exists make @@\
            delete make.bak quiet @@\
            rename make make.bak @@\
        endif @@\
        $(CC) Link Make.o To make

    works. Note that the @@ must stand alone (i.e., "make@@\" is illegal).
    Also be careful that there is a space after the "\" (i.e., at the
    beginning of the next line).
- Can be made resident to save space and time
- Amiga specific wildcards can be used in $(wildcard ...)

BUGS:
- The line

    dummy.h : src/*.c

tries to make dummy.h from "src/*.c" (i.e., no wildcard-expansion takes
place). You have to use "$(wildcard src/*.c)" instead.

COMPILING FROM SCRATCH
----------------------

To recompile, you need SAS/C 6.51.

As of GNU Make 4.3, the build environment has been cleaned up and alternate
make files (including smakefiles) have been removed.  If you have an existing
version of GNU Make available you _should_ be able to run:

   make -f Basic.mk

However this is untested.

If you have an Amiga system and would like to collaborate on getting
bootstrapping to work properly please contact bug-make@gnu.org.

INSTALLATION

Copy make somewhere in your search path (e.g., sc:c or sc:bin).
If you plan to use recursive makes, install make resident:

    Resident make Add

-------------------------------------------------------------------------------
Copyright (C) 1995-2023 Free Software Foundation, Inc.
This file is part of GNU Make.

GNU Make is free software; you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation; either version 3 of the License, or (at your option) any later
version.

GNU Make is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program.  If not, see <https://www.gnu.org/licenses/>.

## Acknowledgements

*Amiga* is a trademark of **Amiga Inc**. 
