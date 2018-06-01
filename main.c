#include "libftprintf.h"
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "");
	ft_printf("%-7C %007d%-10.2ls!!\n", 0xd777, 0x45, L"〻");
	printf("%-7C %007d%-10.2ls!!\n", 0xd777, 0x45, L"〻");
}
