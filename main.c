#include "libftprintf.h"
#include <locale.h>

int main(void)
{
	ft_printf("mine{% 03d}\n", 0);
	printf("real{% 03d}\n", 0);
	ft_printf("mine{% d}\n", 9990);
	printf("real{% d}\n", 9990);
	ft_printf("mine:{%.4ld}\n", 0);
	printf("real:{%.4ld}\n", 0);
	ft_printf("mine:{%.2hd}\n", -1);
	printf("real:{%.2hd}\n", -1);
	ft_printf("mine:{%.0zd}\n", 0);
	printf("real{%.0zd}\n", 0);
	ft_printf("mine{%1.0zd}\n", 0);
	printf("real{%1.0zd}\n", 0);
	ft_printf("mine{% 1.0zd}\n", 0);
	printf("real{% 1.0zd}\n", 0);
	ft_printf("mine{% d}\n", 0);
	printf("real{% d}\n", 0);
	
	ft_printf("mine{%2zd}\n", 0);
	printf("real{%2zd}\n", 0);
	ft_printf("mine{% 2.2hd}\n", -1);
	printf("real{% 2.2hd}\n", -1);
	ft_printf("mine{%+10.10jd}\n", -1);
	printf("real{%+10.10jd}\n", -1);
	ft_printf("mine{%+1.10jd}\n", 0);
	printf("real{%+1.10jd}\n", 0);
	ft_printf("mine{%+1.0jd}\n", 0);
	printf("real{%+1.0jd}\n", 0);
	ft_printf("mine{% -4.1hhd}\n", 2);
	printf("real{% -4.1hhd}\n",(char)2);
}
