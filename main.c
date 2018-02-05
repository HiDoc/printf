#include "libftprintf.h"
#include <locale.h>
int main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("%8C", 3250);
	ft_printf("\n%8C et coco %C", 3250, 0x11ffff);
	printf("\n%8C et coco %C", 3250, 0x11ffff);
	return (0);
}
