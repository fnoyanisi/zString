About zString
-----------------------
 zString is a C library providing "slightly" different functionality compared to standard string processing functions in C.

 zString does not aim to replace standard library string processing functions but introduce new functions with different functionalities (like zStrtok() does)

 zString was created by Fehmi Noyan ISI

Version History
----------------------
v1.0	-	Initial version
v1.1	-	Performance improvements for zStrrmv()
		Added zFileToMemory()
		Added zReadMemoryFile()

Functions 
-----------------------
zCharSearch(char *token, char s)
This function searches for a particular character in a given string.

zStrrmv(char *str,char *bad)
This function removes any string of characters from a given string str. Each
char in bad is searched seperately. 

zStrtok(char *str, const char *delim)
An alternative to standrd libraries strtok() function that is also capable of
handling successive delimiters.

zFileToMemory(char **fileBuffer, char *filePath)
Reads the content of file located at filePath into a character buffer pointed 
by fileBuffer. fileBuffer has to be free()'ed after done with this function.

zReadMEmoryFile(char *fileBuffer, char *line)
Reads the file previously imported by zFileToMemory() line by line and stores
each line into a character buffer pointed by second argument. 

License
-----------------------
 zString can be distributed/modified under the terms of BSD license (4-clause, old the old/original BSD license)

Fehmi Noyan ISI
fnoyanisi@yahoo.com 
