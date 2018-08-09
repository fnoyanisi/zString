/******************************************************************************
* zstring_remove_chr.h
* Copyright (c) 2012-2016, Fehmi Noyan ISI fnoyanisi@yahoo.com
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
*  C function to remove certain characters provided by a string of characters
*  from string another string
*
*  Function arguments:
*	char *zstring_remove_chr(char *str, char *b)
*      - str is the string of char that is subject to character removal
*      process
*      - b is a string of characters that will be removed from str. If one 
*      wishes to remove comma and underscore from another string, then 
*      b = ",_"
*
*  Return values
*      - the resulting string is returned
*
*  Example Usage
*      char s[]="this is a random string to test the function.";
*      char *b=" .";
*      printf("%s\n",zstring_remove_chr(s,b));
*
*  Example Output
*      thisisarandomstringtotestthefunction
******************************************************************************/
#ifndef ZSTRING_REMOVE_CHR_H
#define ZSTRING_REMOVE_CHR_H

#ifndef ZSTRING_SEARCH_CHR_H
#include "zstring_search_chr.h"
#endif

char *zstring_remove_chr(char *str,const char *b) {
    char *p;
    int i;

    if (str == NULL || b == NULL)
        return NULL;
    
    for(p = str, i = 0; *p; p++) 
        if(zstring_search_chr(b,*p)==0)
            *(str + i++) = *p;

    *(str + i)='\0';
	return str;
}

#endif