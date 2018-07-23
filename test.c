#include <stdio.h>
#include "zstring.h"

int main(int argc, char **argv) {
	char s[] = "     Free software is a matter of liberty.    ";
	char *p = NULL;
	printf("%sLike free speech\n",zstring_ltrim(p));

	return 0;
}
