#include "libftprintf.h"
#include <locale.h>
int main(void)
{
	int a = ft_printf("hello\n");
	printf("\n");
	int b = printf("hello\n");
	printf("\n");
	printf("%d\n", a);
	printf("%d\n", b);
	return (0);
}
