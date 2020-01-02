/*!
* \file zrepstr.h
* \brief Header file for zrepstr function.
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

#ifndef ZREPSTR_H
#define ZREPSTR_H

#include <stdio.h>
#include <string.h>

/*! 
 * \brief Replaces a string with another one.
 *
 * \details Every occurance of the string given by the argument \p x contained 
 *  in the first argument \p str is replaced by the string given by the 
 * argument \p y.
 * 
 * \param str pointer to the input string
 * \param x a NULL terminated string that is to be replaced 
 * \param y a NULL terminated string that will replace the string pointed 
 * by \p x
 * 
 * \b Example
 * \code{.c}
 * #include <stdio.h>
 * #include <zstring.h>
 * 
 * int main() {
 *      char str[] = "free as in free speech, not as in free beer";
 *      printf("%s\\n",zrepstr(str,"free","KLMN"));
 *      return 0;
 * }
 * \endcode
 * 
 * \b Output 
 * \code{.unparsed}
 * KLMN as in KLMN speech, not as in KLMN beer
 * \endcode
 * 
 * \returns zrepstr function returns a pointer to the resulting string.
 * 
 */

char *
zrepstr(char *str, const char *x, const char *y){
	char *p = str;
	size_t tlen = strlen(str);	/* total length of the buffer */
	size_t clen, ylen = strlen(y);	/* clen - copy length */

	while ((p = strstr(str, x))!= NULL) {
		/* litte bit of pointer arithmetic
		 *
		 *		     tlen       (str + tlen)
		 *   |-----------------------|
		 *   |                 |     |           |
		 *  str................p.............(p + ylen)
		 *   |<--------------->|<---->
		 *         (p - str)     (str + tlen - p)
		 */ 
		clen = ((p - str + ylen) <= tlen) ? ylen : (str + tlen - p);			
		p = strncpy(p, y, clen);
		p += clen;
	}
	return str;
}

#endif
