/******************************************************************************
* zstrchr.h
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
*
* Description :
*  C function that searches the existence of a particular character in
*  given character string
*
*  Function arguments:
*	int zstring_search_chr(char *st, char c)
*      - str is the string of chars in which character c will be searched
*      - c is a single character that will be searched within string
*
*  Return values
*      - (-1) will be returned if either of string or c is NULL or c cannot
*      be found in the string
*      - index of c is returned if c is found in string, indexing starts from
*      zero
*
*  Example Usage
*      char *t="zString is cool!";
*      printf("%d\n",zstring_search_chr(t,'t'));
*
*  Example Output
*      1
******************************************************************************/
#ifndef ZSTRING_SEARCH_CHR_H
#define ZSTRING_SEARCH_CHR_H

int 
zstring_search_chr(const char *str, char c){
    const char *p = str;
	do {
        if (*p == c)
            return (p-str);
    } while (*p++);
	return (-1);
}

#endif
