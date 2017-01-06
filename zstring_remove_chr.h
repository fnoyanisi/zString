/******************************************************************************
* zstring_remove_chr.h
* Copyright (c) 2012-2016, Fehmi Noyan ISI fnoyanisi@yahoo.com
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright
*   notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*   notice, this list of conditions and the following disclaimer in the
*   documentation and/or other materials provided with the distribution.
* 3. All advertising materials mentioning features or use of this software
*   must display the following acknowledgement:
*   This product includes software developed by Fehmi Noyan ISI.
* 4. Neither the name of Fehmi Noyan ISI nor the
*   names of its contributors may be used to endorse or promote products
*   derived from this software without specific prior written permission.
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
*	char *zstring_remove_chr(char *str, char *bad)
*      - str is the string of char that is subject to character removal
*      process
*      - bad is a string of characters that will be removed from str. If one 
*      wishes to remove comma and underscore from another string, then 
*      bad = ",_"
*
*  Return values
*      - the resulting string is returned
*
*  Example Usage
*      char s[]="this is a trial string to test the function.";
*      char *d=" .";
*      printf("%s\n",zstring_remove_chr(s,d));
*
*  Example Output
*      thisisatrialstringtotestthefunction
******************************************************************************/
#ifndef ZSTRING_REMOVE_CHR_H
#define ZSTRING_REMOVE_CHR_H

#ifndef ZSTRING_SEARCH_CHR_H
#include "zstring_search_chr.h"
#endif

char *zstring_remove_chr(char *str,const char *bad) {
    char *src = str , *dst = str;
    
    /* validate input */
    if (!(str && bad))
        return NULL;
    
    while(*src)
        if(zstring_search_chr(bad,*src))
            src++;
        else
            *dst++ = *src++;  /* assign first, then increment */

    *dst='\0';
	return str;
}

#endif
