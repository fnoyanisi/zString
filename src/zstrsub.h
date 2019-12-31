/******************************************************************************
* zstrsub.h
* Copyright (c) 2019, Fehmi Noyan ISI fnoyanisi@yahoo.com
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
*	- Unlike strtok(), zstrtok() returns delim in case of consecutive
*	  delimiters.
*	- Unlike strtok(), zstrtok() accepts only single char delim
*	- strtok() returns NULL if no token is found whereas zstrtok()
*	  returns input str (see Return values section below)
*
*  Function arguments:
*	char *zstrtok(char *str, const char *delim)
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
*      printf("1 %s\n",zstrtok(s,","));
*      printf("2 %s\n",zstrtok(NULL,","));
*      printf("3 %s\n",zstrtok(NULL,","));
*      printf("4 %s\n",zstrtok(NULL,","));
*      printf("5 %s\n",zstrtok(NULL,","));
*      printf("6 %s\n",zstrtok(NULL,","));
*
*  Example Output
*      1 A
*      2 B
*      3 ,
*      4 ,
*      5 C
*      6 (null)
******************************************************************************/
#ifndef ZSTRSUB_H
#define ZSTRSUB_H

#include <stdio.h>
#include <string.h>

char *
zstrsub(char *str, size_t pos, size_t count) {
    return ((pos + count) <= strlen(str))? (strndup((str+pos), count)) : NULL;
}

#endif
