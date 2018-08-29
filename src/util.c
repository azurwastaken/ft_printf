/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 11:15:49 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/17 11:15:52 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

int				is_charset(char c, char *str)
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

void			ft_putnstr(char const *s, int n)
{
	write(1, s, n);
}

static	char	*init_tab(void)
{
	char	*digit;

	if (!(digit = (char *)malloc(sizeof(char) * 16)))
		return (0);
	digit[0] = '0';
	digit[1] = '1';
	digit[2] = '2';
	digit[3] = '3';
	digit[4] = '4';
	digit[5] = '5';
	digit[6] = '6';
	digit[7] = '7';
	digit[8] = '8';
	digit[9] = '9';
	digit[10] = 'A';
	digit[11] = 'B';
	digit[12] = 'C';
	digit[13] = 'D';
	digit[14] = 'E';
	digit[15] = 'F';
	return (digit);
}

char			*ft_convert_base(unsigned long long num, int base, char letter)
{
	char		*digit;
	static char	buffer[70];
	char		*res;
	int			i;

	digit = init_tab();
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
	free(digit);
	return (res);
}

char			*ft_convert_bde(long long num, int base, char letter)
{
	char				*digit;
	static char			buffer[120];
	char				*res;
	int					i;
	unsigned long long	nbr;

	digit = init_tab();
	nbr = num < 0 ? num * -1 : num;
	i = 9;
	while (i++ < 16 && letter == 'x')
		digit[i] = ft_tolower(digit[i]);
	res = &buffer[70];
	*res = '\0';
	*--res = digit[nbr % base];
	nbr = nbr / base;
	while (nbr != 0)
	{
		*--res = digit[nbr % base];
		nbr = nbr / base;
	}
	if (num < 0)
		*--res = '-';
	free(digit);
	return (res);
}
