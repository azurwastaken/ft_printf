#include "lib_printf.h"

int		is_charset(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_convert_base(unsigned long long num, int base, char letter)
{
	static char	digit[] = "0123456789ABCDEF";
	static char	buffer[70];
	char		*res;
	int			i;

	i = 10;
	while (i < 16 && letter == 'x')
	{
		digit[i] = ft_tolower(digit[i]);
		i++;
	}
	res = &buffer[70];
	*res = '\0';
	*--res = digit[num % base];
	num = num / base;
	while (num != 0)
	{
		*--res = digit[num % base];
		num = num / base;
	}
	return (res);
}

char	*ft_convert_bde(long long num, int base, char letter)
{
	static char	digit[] = "0123456789ABCDEF";
	static char	buffer[120];
	char		*res;
	int			i;
	unsigned long long nbr;

	nbr = num < 0 ? num * -1 : num;
	i = 10;
	while (i < 16 && letter == 'x')
	{
		digit[i] = ft_tolower(digit[i]);
		i++;
	}
	res = &buffer[70];
	*res = '\0';
	*--res = digit[nbr % base];
	nbr = nbr / base;
	while (nbr != 0)
	{
		*--res = digit[nbr % base];
		nbr = nbr / base;
	}
	if(num < 0)
		*--res = '-'; 
	return (res);
}