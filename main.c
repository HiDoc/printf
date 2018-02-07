#include "libftprintf.h"
#include <locale.h>
int main(void)
{
	wchar_t s[4];

	s[0] = 0x53;
	s[1] = 0x0F;
	s[2] = 0x0F;
	s[3] = '\0';
	int a = ft_printf("hello%Shello", s);
	printf("\n");
	int b = printf("hello%Shello", s);
	printf("\n");
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}
