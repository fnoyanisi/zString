/*************************************************************************
** zstrrmv.h 
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
**  C function to remove certain characters from another string
**
**  Function argumenents:
**	char *zStrrmv(char *str, char *delim)
**	- str is the string of char that is subject to character removal
**	  process
**  	- token is a string of delimiter characters. If one wishes to use
**	  comma and undescore as delimiter, then delim = ",_"
**
**  Return values
**	- NULL returned in case of an error
**	- On success, the resukting string s returned
**
**  Exmaple Usage
**	- char s[]="this is a trial string to test the function";
**	- char *d=" ";
**	- printf("%s\n",zStrrmv(s,d));
**
**  Example Output
**	- thisisatrialstringtotestthefunction
*************************************************************************/
#ifndef _ZSTRRMV_H
#define _ZSTRRMV_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

/*
* This is an internally deployed function
*/
int zChrSearch(char *token,char s){
	int i=0;
	
	if (!token || s=='\0')
		return 0;

	while(token[i]) {
		if (token[i]==s)
			return 1;
		i++;
	}
	return 0;
}


char *zStrrmv(char *str,char *delim) {
	int index=0;	

	if (str==0 || delim==0)
		return 0;

	while(str[index]){;
		if (zChrSearch(delim,str[index])) {
			memmove (str+index,str+index+1,strlen(str)-index);
			index--;
		}
		index++;
	}
	return str;
}

#endif
