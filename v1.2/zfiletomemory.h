/*************************************************************************
** zFileToMemory.h
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
**  C function that reads the content of a file into a char*. The buffer used to
**  store the content of the file has to be free()'ed manually after done with the
**  buffer to avoid possible memory leaks.
**
**  Function argumenents:
**	long zFileToMemory(char **fileBuffer,char *filePath)
**	- fileBuffer a pointer to a character string pointer. This parameter points the
**    memory location where the contents of the file will be stored in.
**  - filePath is a character string for the containing the path of the file to be
**    read.
**
**  Return values
**	- Number of read bytes will be returned as long.
**	- Neagtive value is returned on failure
**
**  Exmaple Usage
**  int main(int argc, char *argv[]){
**      char *buf;
**	    printf("%ld\n",zFileToMemory(&buf,argv[1]));
**	    free(buf);
**	    return 0;
**  }
**
**  Example Output
**	- filesize in bytes
*************************************************************************/
#ifndef _ZFILETOMEMORY_H
#define _ZFILETOMEMORY_H

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STDLIB_H
#include <stdlib.h>
#endif

long zFileToMemory(char **fileBuffer,char *filePath) {
	FILE *f;
	long fileSize;

	if((f=fopen(filePath,"r"))==NULL)
		return -1;

	if (fseek(f,0,SEEK_END)==-1)
		return -4;
	if ((fileSize = ftell(f))==-1)
		return -4;
	if (fseek(f,0,SEEK_SET)==-1)
		return -4;

	if (((*fileBuffer)=malloc(fileSize))==NULL)
		return -2;

	if (fread((*fileBuffer),1,fileSize,f)==0)
		return -3;

	fclose(f);
	return fileSize;
}

#endif
