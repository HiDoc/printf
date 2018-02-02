#include "libft.h"

static int				ft_getlen(unsigned long long int n, int c, int baseto)
{
	return ((n != 0 ? ft_getlen(n / baseto, c + 1, baseto) : c));
}

unsigned long long int	get_max(int sign)
{
	if (sign == 1)
		return (UCHAR_MAX);
	else if (sign == 2)
		return (UINT_MAX);
	else if (sign == 3)
		return (LONG_MAX);
	else if (sign == 4)
		return (ULONG_MAX);
	else if (sign == 5)
		return (LLONG_MAX);
	else if (sign == 6)
		return (ULLONG_MAX);
	return (INT_MAX);
}

char					*ft_ltoabase(long long int n, int baseto, char *basefrom, int sign)
{
	char					*nbr;
	int						count;
	int						ispos;
	unsigned long long int	uint;

	if (n == 0)
		return (ft_strdup("0"));
	ispos = ((n >= 0 || baseto != 10) || sign);
	if (n < 0 && (baseto != 10 || sign))
		uint = get_max(sign) + n + 1;
	else
		uint = ABS(n);
	count = ft_getlen(uint, 0, baseto) + (n < 0 && baseto == 10 && !sign);
	if ((nbr = (char *)malloc((sizeof(char) * (count + 1)))) == NULL)
		return (NULL);
	nbr[count] = '\0';
	while (--count >= 0)
	{
		nbr[count] = basefrom[ABS((uint % baseto))];
		uint /= baseto;
	}
	if (!ispos)
		nbr[0] = '-';
	return (nbr);
}
