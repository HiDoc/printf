#include "libftprintf.h"
#include <locale.h>
int main(void)
{
	setlocale(LC_ALL, "");
	wchar_t w = 2047;
	int e;
	int a;
	int b;
	int c;
	int d;
	e = w;
	a = 0;
	b = 0;
	c = 0;
	d = 0;
	if (e > 2047)
	{
		e = 	
	}
	else if (e > 127)
	{
		e = ((w << 2) & 0xFF00) + (w & 0x3F) + 0xc080;
		a = e >> 8;
		b = e & 0x00FF;
	}
	printf("e : %d\n", e);
	printf("a : %d\n", a);
	printf("a : %d\n", b);
	write(1, &a, 1);
	write(1, &b, 1);
	printf("\n%lc", w);
	return (0);
}
