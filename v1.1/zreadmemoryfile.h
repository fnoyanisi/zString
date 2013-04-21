/*************************************************************************
** zReadMemoryFile.h
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
**  Description :
**  C function alternative to Standard C Library's strtok() call with
**  differences given below
**	- Unlike strtok(), zStrtok() returns delim in case of consecutive
**	  delimiters.
**	- Unlike strtok(), zStrtok() accepts only single char delim
**	- strtok() returns NULL if no token is found whereas zStrtok()
**	  returns input str (see Return values section below)
**
**  Function arguments:
**	char *zReadMemoryFile(char *fileBuffer, char *line)
**  - fileBuffer is a pointer to character string that contains '\n' terminated
**    strings in it. This can be obtained by using zFileToMemory() to store contents
**    of a file into a char* pointed memory address.
**	- line is a pointer to a character string (either a char[] or malloc()'ed memory
**    location) that will hold the fetched line from the fileBuffer. Size of line has to
**    be enough to accomodate a line fetched from fileBuffer
**
**  Return values
**	- On successful operation, a pointer to line will be returned
**	- In case of end of string, null is returned
**
**  Exmaple Usage
**  int main(int argc, char *argv[]){
**	    char *buf;
**	    char line[128]={'\0'};
**	    printf("%ld\n",zFileToMemory(&buf,argv[1]));
**	    printf("%s\n",zReadMemoryFile(buf,line));
**	    printf("%s\n",zReadMemoryFile(0,line));
**	    printf("%s\n",zReadMemoryFile(0,line));
**	    printf("%s\n",zReadMemoryFile(0,line));
**	    printf("%s\n",zReadMemoryFile(0,line));
**	    printf("%s\n",zReadMemoryFile(0,line));
**	    free(buf);
**	    return 0;
**  }
**
**  Content of TXT file
**    this is trial
**    trial line two
**    trial line three
**    last trial line
**
**  Example Output
**  - 62
**  - this is trial
**  - trial line two
**  - trial line three
**  - last trial line
**	- (null)
**	- (null)
*************************************************************************/
#ifndef _ZREADMEMORYFILE_H
#define _ZREADMEMORYFILE_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

char *zReadMemoryFile(char *fileBuffer, char *line) {
	static char *lastPos;
	int index;

	if (fileBuffer==0 && lastPos==0)
		return 0;

	if (fileBuffer==0)
		fileBuffer = lastPos;

	for(index=0 ; *fileBuffer != '\0' && *fileBuffer != '\n' ; index++)
		*(line + index) = *fileBuffer++;

	*(line + index) = '\0';
	lastPos = (fileBuffer+1);

	return line;
}

#endif
