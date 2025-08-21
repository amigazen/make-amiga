/* Definitions for amiga specific things
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
this program.  If not, see <https://www.gnu.org/licenses/>.  */

#include <stdarg.h>

int MyExecute (char ** argv);
char * wildcard_expansion (char * wc, char * o);
int snprintf(char *buffer, size_t bufsize, const char *fmt, ...);
int vsnprintf(char *buffer, size_t bufsize, const char *fmt, va_list args);
