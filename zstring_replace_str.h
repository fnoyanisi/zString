/******************************************************************************
* zstring_replace_str.h
* Copyright (c) 2016, Fehmi Noyan ISI fnoyanisi@yahoo.com
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
*  Replaces every occurance of string 'x' with string 'y' within string 'str'.
*
*  Function arguments:
*	char *zstring_replace_str(char *str, const char *x, const char *y)
*      - str is a pointer to a NULL terminated string of charaters
*      - x is a NULL terminated string that is to be replaced 
*      - y is a NULL terminated string that will replace the string 
*	    pointed by 'x'
*
*  Return values
*      - NULL in case any of the arguments is NULL
*      - Modified string is returned 
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

char *zstring_replace_str(char *str, const char *x, const char *y){
    /* to preserve the address of original pointers, tmp_ are used 
     * dummy_ptr enables us to preserve the address of tmp_str when
     * a matching string pattern is found
     * */
    char *tmp_str = str, *tmp_x = x, *dummy_ptr = tmp_x, *tmp_y = y;
    int len_str=0, len_y=0, len_x=0;

    /* NULL pointer check */
    if ((*str && *x && *y)==0)
        return 0;

    /* calculating length of strings */
    for(; *tmp_y; ++len_y, ++tmp_y)
        ;

    for(; *tmp_str; ++len_str, ++tmp_str)
        ;

    for(; *tmp_x; ++len_x, ++tmp_x)
        ;

    /* Bounds check */
    if (len_y >= len_str)
        return str;

    /* reset tmp pointers */
    tmp_y = y;
    tmp_x = x;

    for (tmp_str = str ; *tmp_str; ++tmp_str)
        if(*tmp_str == *tmp_x) {
            /* save tmp_str */
            for (dummy_ptr=tmp_str; *dummy_ptr == *tmp_x; ++tmp_x, ++dummy_ptr)
                if (*(tmp_x+1) == '\0' && ((dummy_ptr-str+len_y) < len_str)){
                    /* Reached at the end of x, we got something to replace 
                     * then!
                     * Copy y only if there is enough room for it
                     */
                    for(tmp_y=y; *tmp_y; ++tmp_y, ++tmp_str)
                        *tmp_str = *tmp_y;
            }
        /* reset tmp_x */
        tmp_x = x;
        }

    return str;
}

#endif
