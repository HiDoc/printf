#include "libftprintf.h"
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("mine{% 03d}\n", 0);
	printf("real{% 03d}\n", 0);
	ft_printf("mine% d\n", 9990);
	printf("real% d\n", 9990);
}
