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
*  Returns a substring [pos, pos+count). 
*
*  Function arguments:
*	char *zstrsub(const char *str, size_t pos, size_t count)
*      - str is a pointer to a NULL terminated string of characters
*      - pos is the position of the first character to include
*      - count is the length of the substring
*
*  Return values
*      - A pointer to the start of the NULL terminated substring
*      - NULL if pos + count exceeds the bounds of the string str
*
*  Example Usage
*      char str[] = "zString is cool!";
*      printf("1 %s\n",zstrsub(s, 8, 8));
*
*  Example Output
*      is cool!
******************************************************************************/
#ifndef ZSTRSUB_H
#define ZSTRSUB_H

#include <stdio.h>
#include <string.h>

char *
zstrsub(const char *str, size_t pos, size_t count) {
    return ((pos + count) <= strlen(str))? (strndup((str+pos), count)) : NULL;
}

#endif
