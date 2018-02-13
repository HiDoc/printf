#include "libftprintf.h"
#include <stdio.h>
#include <locale.h>
#include <wchar.h>
int main(void)
{
	char str;
	wchar_t    s[4];

	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	int c =
		printf("%S", (wchar_t *)'s');
	printf("\n");
	int d =
		printf("%S", (wchar_t *)'s');
	printf("\n%d\n", c);
	printf("%d\n", d);
	return (0);
}
