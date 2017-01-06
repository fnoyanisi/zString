/******************************************************************************
* zstring_strtok.h
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
*  Description :
*  C function alternative to Standard C Library's strtok() call with
*  differences given below
*	- Unlike strtok(), zstring_strtok() returns delim in case of consecutive
*	  delimiters.
*	- Unlike strtok(), zstring_strtok() accepts only single char delim
*	- strtok() returns NULL if no token is found whereas zstring_strtok()
*	  returns input str (see Return values section below)
*
*  Function arguments:
*	char *zstring_strtok(char *str, const char *delim)
*      - str is a pointer to a NULL terminated string of characters
*      - delim is a NULL terminated character string whose first char
*      is the delimiter
*
*  Return values
*      - A pointer to next token in the str is returned
*      - If end of str is reached NULL is returned
*      - If delim cannot be found in the str, str is returned
*
*  Example Usage
*      char str[] = "A,B,,,C";
*      printf("1 %s\n",zstring_strtok(s,","));
*      printf("2 %s\n",zstring_strtok(NULL,","));
*      printf("3 %s\n",zstring_strtok(NULL,","));
*      printf("4 %s\n",zstring_strtok(NULL,","));
*      printf("5 %s\n",zstring_strtok(NULL,","));
*      printf("6 %s\n",zstring_strtok(NULL,","));
*
*  Example Output
*      1 A
*      2 B
*      3 ,
*      4 ,
*      5 C
*      6 (null)
******************************************************************************/
#ifndef ZSTRING_STRTOK_H
#define ZSTRING_STRTOK_H

char *zstring_strtok(char *str, const char *delim) {
    static char *static_str=0;    	/* var to store last address */
    int index=0, strlength=0;      	/* integers for indexes */
    int found = 0;              	/* check if delim is found */

    /* delimiter cannot be NULL
    * if no more char left, return NULL as well
    */
    if (delim==0 || (str == 0 && static_str == 0))
        return 0;

    if (str == 0)
        str = static_str;

    /* get length of string */
    while(str[strlength])
        strlength++;

    /* find the first occurrence of delim */
    for (index=0;index<strlength;index++)
        if (str[index]==delim[0]) {
            found=1;
            break;
        }

    /* if delim is not contained in str, return str */
    if (!found) {
        static_str = 0;
        return str;
    }

    /* check for consecutive delimiters
    *if first char is delim, return delim
    */
    if (str[0]==delim[0]) {
        static_str = (str + 1);
        return (char *)delim;
    }

    /* terminate the string
    * this assignment requires char[], so str has to
    * be char[] rather than *char
    */
    str[index] = '\0';

    /* save the rest of the string */
    if ((str + index + 1)!=0)
        static_str = (str + index + 1);
    else
        static_str = 0;

        return str;
}

#endif
