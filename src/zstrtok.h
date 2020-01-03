/*!
* \file zstrtok.h
* \brief Header file for zstrtok function.
* \details Functions defined in this file can be distributed under the 
* 2-Clause BSD license.
* \copyright 2012-2019, Fehmi Noyan ISI
*/

/*
* Copyright (c) 2012-2019, Fehmi Noyan ISI fnoyanisi@yahoo.com
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
#ifndef ZSTRTOK_H
#define ZSTRTOK_H

#include <stdio.h>
#include <string.h>

/*! 
 * \brief zstrtok function is used to tokenize the string \p str.
 *
 * \details This function uses a static buffer and argument \p delimd to isolate
 * requential tokens in a null terminated string \p str. Some notable differences
 * between \a zstrtok() and \a strtok() function from standard library are;
 *  - Unlike \a strtok(), \a zstrtok() returns \p delim in case of consecutive
 *	  delimiters.
 *	- Unlike \a strtok(), \a zstrtok() accepts only a single char delim
 *	- \a strtok() returns NULL if no token is found whereas \a zstrtok()
 *	  returns input str (see Return values section below)
 * 
 * \param str pointer to the input string
 * \param delim a string with strlen = 1 and containing only the char to be
 * used as the delimiter for tokenising
 * 
 * \b Example
 * \code{.c}
 * #include <stdio.h>
 * #include <zstring.h>
 * 
 * int main() {
 *      char str[] = "A,B,,,C";
 *      printf("1 %s\n",zstrtok(s,","));
 *      printf("2 %s\n",zstrtok(NULL,","));
 *      printf("3 %s\n",zstrtok(NULL,","));
 *      printf("4 %s\n",zstrtok(NULL,","));
 *      printf("5 %s\n",zstrtok(NULL,","));
 *      printf("6 %s\n",zstrtok(NULL,","));
 *      return 0;
 * }
 * \endcode
 * 
 * \b Output 
 * \code{.unparsed}
 *      1 A
 *      2 B
 *      3 ,
 *      4 ,
 *      5 C
 *      6 (null)
 * \endcode
 * 
 *  \warning Since a static buffer is used, nested calls may give unexpected 
 * results and the function is not thread safe.
 * 
 * \returns zstrtok function returns a pointer to the next token in \p str
 * or NULL if end of the string is reached. If there is no tokens founds, 
 * \p str is returned.
 * 
 */

char *
zstrtok(char *str, const char *delim) {
    static char *s_str = NULL;   /* var to store last address */
    char *p;

    if (delim == NULL || (str == NULL && s_str == NULL)){
        return NULL;
    }

    if (str == NULL){
        str = s_str;
    }

    /* if delim is not contained in str, return str */
    if ((p = strstr(str,delim)) == NULL) {
        s_str = NULL;
        return str;
    }

    /* 
    * check for consecutive delimiters
    * if first char is delim, return delim
    */
    if (str[0] == delim[0]) {
        s_str++;
        return (char *)delim;
    }

    /* terminate the string */
    *p = '\0';

    /* save the rest of the string */
    if ((p+1) != NULL) {
        s_str = (p + 1);
    } else {
        s_str = NULL;
    }

        return str;
}

#endif
