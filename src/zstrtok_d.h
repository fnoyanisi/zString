/******************************************************************************
* zstrtok_d.h
* Copyright (c) 2016, Fehmi Noyan ISI fnoyanisi@yahoo.com
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
*  zstrtok_d() is added into zstring library to be able to comply 
*  with RFC4180 Clause-5 while processing text/csv MIME type.
*  This function extends the operation of zstrtok() function by treating 
*  any text enclosed within 'quote' characters as a single phrase and ignores
*  any 'delim' included in that particular phrase.
*
*  Please refer to the description of zstrtok() function for more details.
*
*  Function arguments:
*	char *zstrtok_d(char *str, const char *delim, const char 
*       quote)
*      - str is a pointer to a NULL terminated string of characters
*      - delim is a NULL terminated character string whose first char
*      is the delimiter
*      - quote is a character constant to identify the quoting character
*
*  Return values
*      - A pointer to next token in the str is returned
*      - If end of str is reached NULL is returned
*      - If delim cannot be found in the str, str is returned
*
*  Example Usage
*      char s[]="aaaa,bbbb,\"ccc,c\",dddd,eeee,\"ff,ff\"";
*
*      printf("1 %s\n",zstrtok_d(s,",",'\"'));
*      printf("2 %s\n",zstrtok_d(NULL,",",'\"'));
*      printf("3 %s\n",zstrtok_d(NULL,",",'\"'));
*      printf("4 %s\n",zstrtok_d(NULL,",",'\"'));
*      printf("5 %s\n",zstrtok_d(NULL,",",'\"'));
*      printf("6 %s\n",zstrtok_d(NULL,",",'\"'));
*
*  Example Output
*      1 aaaa
*      2 bbbb
*      3 "ccc,c"
*      4 dddd
*      5 eeee
*      6 "ff,ff"
******************************************************************************/
#ifndef ZSTRTOK_D_H
#define ZSTRTOK_D_H

char *zstrtok_d(char *str, const char *delim, const char quote) {
    static char *static_str=0;    	/* var to store last address */
    int index=0, strlength=0;       /* integers for indexes */
    int found=0;              	    /* check if delim is found */
    int in_quotes=0;

    /* delimiter cannot be NULL
    * if no more char left, return NULL as well
    */
    if (delim==0 || (str == 0 && static_str == 0))
        return 0;

    if (str == 0)
        str = static_str;

    /* get the string length */
    while(str[strlength])
        strlength++;

    /* find the first occurrence of delim outside of an phrase */
    for (index=0;index<strlength;index++)
        if (quote && str[index]==quote && in_quotes==0)
            in_quotes=1;
        else if (quote && str[index]==quote && in_quotes==1)
            in_quotes=0;
        else if (str[index]==delim[0] && in_quotes==0) {
            found=1;
            break;
        }

    /* At this point, in_quotes should be 0 in normal cases. If not,
    * the behaviour is undefined.
    */
    in_quotes=0;

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
