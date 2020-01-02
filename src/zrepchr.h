/*!
* \file zrepchr.h
* \brief Header file for zrepchr function.
* \details Functions defined in this file can be distributed under the 
* 2-Clause BSD license.
* \copyright 2016-2019, Fehmi Noyan ISI
*/

/*
* Copyright (c) 2016-2019, Fehmi Noyan ISI fnoyanisi@yahoo.com
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

/*! 
 * \brief Replaces a character with another one.
 *
 * \details Every occurance of the character given by the argument \p x contained 
 *  in the first argument \p str is replaced by the character given by the 
 * argument \p y.
 * 
 * \param str pointer to the input string
 * \param x the character to be replaced
 * \param y the character that will replace the character given by \p x
 * 
 * \b Example
 * \code{.c}
 * #include <stdio.h>
 * #include <zstring.h>
 * 
 * int main() {
 *      char s[]="this is a random string to test the function.";
 *      char x=' ', y='_';
 *      printf("%s\n",zrepchr(s,x,y));
 *      return 0;
 * }
 * \endcode
 * 
 * \b Output 
 * \code{.unparsed}
 * this_is_a_random_string_to_test_the_function.
 * \endcode
 * 
 * \returns zrepchr function returns a pointer to the resulting string.
 * 
 */

#ifndef ZREPCHR_H
#define ZREPCHR_H

#include <stdio.h>

char *
zrepchr(char *str, char x, char y){
    char *i = str;

    while (*i){
        if (*i == x)
            *i = y;
        i++;
    }
    return str;
}

#endif