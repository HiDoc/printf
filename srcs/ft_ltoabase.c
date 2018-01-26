#include "libft.h"

static int		ft_getlen(unsigned long long n, int c, int baseto)
{
	return ((n != 0 ? ft_getlen(n / baseto, c + 1, baseto) : c));
}

char			*ft_ltoabase(long long n, int baseto, char *basetofrom)
{
	char				*nbr;
	int					count;
	int					ispos;
	unsigned long long	uint;

	if (n == 0)
		return (ft_strdup("0"));
	ispos = (n >= 0 || baseto != 10);
	if (n < 0 && baseto != 10)
		uint = LONG_MAX + n + 1;
	else
		uint = ABS(n);
	count = ft_getlen(uint, 0, baseto) + (n < 0 && baseto == 10);
	if ((nbr = (char *)malloc((sizeof(char) * (count + 1)))) == NULL)
		return (NULL);
	nbr[count] = '\0';
	count--;
	while (count >= 0)
	{
		nbr[count] = basetofrom[ABS((uint % baseto))];
		count--;
		uint /= baseto;
	}
	if (!ispos)
		nbr[0] = '-';
	return (nbr);
}
