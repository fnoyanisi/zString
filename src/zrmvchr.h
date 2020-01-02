/*!
* \file zrmvchr.h
* \brief Header file for zstrchr function.
* \details Functions defined in this file can be distributed under the 
* 2-Clause BSD license.
* \copyright 2012-2019, Fehmi Noyan ISI
*/

/* Copyright (c) 2012-2019, Fehmi Noyan ISI fnoyanisi@yahoo.com
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*
* 1. Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the distribution.
*
* THIS SOFTWARE IS PROVIDED BY Fehmi Noyan ISI ''AS IS'' AND ANY
* EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL Fehmi Noyan ISI BE LIABLE FOR ANY
* DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
* LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
* SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef ZRMVCHR_H
#define ZRMVCHR_H

#include <stdio.h>
#include "zstrchr.h"

/*! 
 * \brief Remove characters from a string.
 *
 * \details All characters contained in the string argument \p b are removed 
 *  from the string given with the argument \p str.
 * 
 * \param str pointer to the input string
 * \param b string containing characters to be removed
 * 
 * \b Example
 * \code{.c}
 * #include <stdio.h>
 * #include <zstring.h>
 * 
 * int main() {
 *      char s[]="this is a random string to test the function.";
 *      char *b=" .";
 *      printf("%s\\n",zrmvchr(s,b));
 *      return 0;
 * }
 * \endcode
 * 
 * \b Output 
 * \code{.unparsed}
 * thisisarandomstringtotestthefunction
 * \endcode
 * 
 * \returns zrmvchr function returns a pointer to the resulting string.
 * 
 */

char *
zrmvchr(char *str, const char *b) {
    char *p;
    char *i;
    p = i = str;

    while(*i){
        if (zstrchr(b,*i) == -1)
            *p++ = *i;
        i++;
    }
    *p = '\0';

    return str;
}

#endif