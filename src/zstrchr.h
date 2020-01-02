/*!
* \file zstrchr.h
* \brief Header file for zstrchr function.
* \details Functions defined in this file can be distributed under the 
* 2-Clause BSD license.
* \copyright 2016-2019, Fehmi Noyan ISI
*/

/*
* Copyright (c) 2012-2018, Fehmi Noyan ISI fnoyanisi@yahoo.com
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
#ifndef ZSTRCHR_H
#define ZSTRCHR_H

/*! 
 * \brief Locates the first occurance of a character in a string.
 *
 * \details The function looks for the first occurance of the character given
 * by the argument \p c in the string given by the argument \p str.
 * 
 * \param str pointer to the input string
 * \param c character to be located
 * 
 * \b Example
 * \code{.c}
 * #include <stdio.h>
 * #include <zstring.h>
 * 
 * int main() {
 *      char *t="zString is cool!";
 *      printf("%d\n",zstrchr(t,'t'));
 *      return 0;
 * }
 * \endcode
 * 
 * \b Output 
 * \code{.unparsed}
 * index = 1
 * \endcode
 * 
 * \returns zstrchr function returns the index of the first occurance of the
 * character \p c inside the string \p str, or -1 if the character cannot be 
 * found.
 * 
 */

int 
zstrchr(const char *str, char c){
    const char *p = str;
	do {
        if (*p == c)
            return (p-str);
    } while (*p++);
	return (-1);
}

#endif
