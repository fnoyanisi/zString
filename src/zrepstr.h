/******************************************************************************
* zrepstr.h
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
*
*  Description :
*  Replaces every occurrence of string 'x' with string 'y' within string 'str'.
*
*  Function arguments:
*	char *zstring_replace_str(char *str, const char *x, const char *y)
*      - str is a pointer to a NULL terminated string of characters
*      - x is a NULL terminated string that is to be replaced 
*      - y is a NULL terminated string that will replace the string 
*	    pointed by 'x'
*
*  Return values
*      - NULL in case any of the arguments is NULL
*      - Modified string is returned 
*  
*  Notes
*      This function only replaces part of the first string with the
*      second one until end of the current buffer. If replacement exceeds
*      bounds of the existing buffer, the secon string is truncated and
*      only a part of it copied over.
*      
*  Example Usage
*      char str[] = "'free' as in 'free speech', not as in 'free beer'";
*      printf("%s\n",zstring_replace_str(str,"free","KLMN"));
*
*  Example Output
*      'KLMN' as in 'KLMN speech', not as in 'KLMN beer'";
******************************************************************************/
#ifndef ZSTRING_REPLACE_STR_H
#define ZSTRING_REPLACE_STR_H

#include <stdio.h>
#include <string.h>

char *
zstring_replace_str(char *str, const char *x, const char *y){
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
