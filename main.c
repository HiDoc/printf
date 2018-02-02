#include "libftprintf.h"
#include "locale.h"
int main(void)
{
	wchar_t	s[4];
	s[0] = 0x53;
	s[1] = 0x3abc;
	s[2] = 0x81000;
	s[3] = '\0';
	
	setlocale(LC_ALL, "");
	ft_printf("premier : %S\n", s);
	printf("second : %S", s);
	return (0);
}
