/*!
* \file zsubstr.h
* \brief Header file for zsubstr function.
* \details Functions defined in this file can be distributed under the 
* 2-Clause BSD license.
* \copyright 2019, Fehmi Noyan ISI
*/

/*
* Copyright (c) 2019, Fehmi Noyan ISI fnoyanisi@yahoo.com
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
#ifndef ZSUBSTR_H
#define ZSUBSTR_H

#include <stdio.h>
#include <string.h>

/*! 
 * \brief Returns a substring [pos, pos+count).
 *
 * \details The function returns the \p count number of characters from the
 * string \p str starting from the location \p pos.
 * 
 * \param str pointer to the input string
 * \param pos position of the first character to include
 * \param count lenght of the substring
 * 
 * \b Example
 * \code{.c}
 * #include <stdio.h>
 * #include <zstring.h>
 * 
 * int main() {
 *      char str[] = "zString is cool!";
 *      printf("%s\\n",zsubstr(s, 8, 8));
 *      return 0;
 * }
 * \endcode
 * 
 * \b Output 
 * \code{.unparsed}
 * is cool!
 * \endcode
 * 
 * \returns zstrchr function returns a pointer to the resulting substring or 
 * NULL if the \p pos + \p count exceeds the bounds of the string \p str. 
 * The caller must free the buffer allocated by zsubstr.
 * 
 */

char *
zsubstr(const char *str, size_t pos, size_t count) {
    return ((pos + count) <= strlen(str))? (strndup((str+pos), count)) : NULL;
}

#endif
