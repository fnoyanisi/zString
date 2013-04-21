/*************************************************************************
** zChrSearch.h
** Copyright (c) 2012, Fehmi Noyan ISI fnoyanisi@yahoo.com
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
** 1. Redistributions of source code must retain the above copyright
**   notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**   notice, this list of conditions and the following disclaimer in the
**   documentation and/or other materials provided with the distribution.
** 3. All advertising materials mentioning features or use of this software
**   must display the following acknowledgement:
**   This product includes software developed by Fehmi Noyan ISI.
** 4. Neither the name of Fehmi Noyan ISI nor the
**   names of its contributors may be used to endorse or promote products
**   derived from this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY Fehmi Noyan ISI ''AS IS'' AND ANY
** EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
** DISCLAIMED. IN NO EVENT SHALL Fehmi Noyan ISI BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
** ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
** Description :
**  C function that searches the existance of a particular character in
**  given character string
**
**  Function argumenents:
**	int zChrSearch(char *token,char s)
**	- token is the string of chars in which s will be searched
**  - s is a single character that will be searched within token
**
**  Return values
**	- Zero will be returned if either of token or s is NULL or s cannot
**	  be found in token
**	- 1 returned if s is found in token
**
**  Exmaple Usage
**	- char *t="zString is cool!";
**	- printf("%d\n",zSChrSearch(t,'t'));
**
**  Example Output
**	- 1
*************************************************************************/
#ifndef _ZCHRSEARCH_H
#define _ZCHRSEARCH_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

inline int zChrSearch(char *token,char s){
	if (!token || s=='\0')
		return 0;

    for (;*token; token++)
        if (*token == s)
            return 1;

	return 0;
}

#endif
