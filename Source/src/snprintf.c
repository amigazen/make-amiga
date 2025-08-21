/* snprintf implementation for Amiga using VSNPrintf
   Copyright (C) 2024 Free Software Foundation, Inc.
   This file is part of GNU Make.

   GNU Make is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free Software
   Foundation; either version 3 of the License, or (at your option) any later
   version.

   GNU Make is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along with
   this program.  If not, see <https://www.gnu.org/licenses/>.  */

#include "makeint.h"
#include <stdarg.h>
#include <proto/utility.h>

/* Implementation of snprintf using Amiga VSNPrintf
   This function formats output according to the format string and writes
   up to bufsize-1 characters to the buffer, ensuring NUL termination.
   Returns the number of characters that would have been written if
   bufsize had been sufficiently large, not counting the terminating NUL. */

int snprintf(char *buffer, size_t bufsize, const char *fmt, ...)
{
    va_list args;
    LONG result;
    
    /* Check for valid parameters */
    if (buffer == NULL || bufsize == 0) {
        return 0;
    }
    
    /* Initialize variable argument list */
    va_start(args, fmt);
    
    /* Call vsnprintf with the variable arguments */
    result = vsnprintf(buffer, bufsize, fmt, args);
    
    /* Clean up variable argument list */
    va_end(args);
    
    return result;
}

/* Implementation of vsnprintf using Amiga VSNPrintf
   This function formats output according to the format string and writes
   up to bufsize-1 characters to the buffer, ensuring NUL termination.
   Returns the number of characters that would have been written if
   bufsize had been sufficiently large, not counting the terminating NUL. */

int vsnprintf(char *buffer, size_t bufsize, const char *fmt, va_list args)
{
    LONG result;
    
    /* Check for valid parameters */
    if (buffer == NULL || bufsize == 0) {
        return 0;
    }
    
    /* Call VSNPrintf with the variable arguments */
    result = VSNPrintf((UBYTE *)buffer, (ULONG)bufsize, (const UBYTE *)fmt, (APTR)args);
    
    /* VSNPrintf returns the total size needed including NUL,
       but vsnprintf should return the number of characters written
       (excluding NUL) or that would have been written */
    if (result > 0) {
        /* If result is greater than bufsize, we truncated */
        if ((ULONG)result > bufsize) {
            return (int)(bufsize - 1);
        } else {
            /* Return the actual characters written (excluding NUL) */
            return (int)(result - 1);
        }
    }
    
    /* Error case */
    return -1;
}
