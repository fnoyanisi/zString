/******************************************************************************
* zrepchr.h
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
*
* Description :
*  C function to replace every occurrence of character 'x' within string 'str'
*  with character 'y'.
*
*  Function arguments:
*	char *zrepchr((char *str, char x,char y)
*      - str is the string of chars that is subject to character replacement
*      process
*      - x is the character to be replaced
*      - y is the replacement of x
*
*  Return values
*      - the resulting string is returned
*
*  Example Usage
*        char s[]="this is a random string to test the function.";
*        char x=' ', y='_';
*        printf("%s\n",zrepchr(s,x,y));
*
*  Example Output
*        this_is_a_random_string_to_test_the_function.
******************************************************************************/
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