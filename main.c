#include "libftprintf.h"
#include <locale.h>
int main(void)
{
	wchar_t s[4];

	setlocale(LC_ALL, "");
	s[0] = 0x53;
	s[1] = 0xD800;
	s[2] = 0x81000;
	s[3] = '\0';
	int a = ft_printf("%S", s);
	printf("\n");
	int b = printf("%S", s);
	printf("\n");
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}
