#include <stdio.h>
#include <locale.h>
#include <wchar.h>
int main(void)
{
	setlocale(LC_ALL, "");
	printf("%S", (wchar_t *)'a');
	return (0);
}
