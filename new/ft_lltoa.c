/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:46:56 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/07/04 10:48:10 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

static int		ft_count_digit(long long nbr)
{
	int		len;
	long	nb;

	len = 0;
	if (nbr < 0)
		len = len + 1;
	nb = nbr < 0 ? (long)nbr * -1 : nbr;
	while (nb != 0)
	{
		nb = nb / 10;
		len = len + 1;
	}
	return (len);
}

char			*ft_lltoa(long long n)
{
	char		*str;
	int			i;
	long long	nb;

	if (n == 0)
	{
		if (!(str = malloc(sizeof(char) * 2)))
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	i = ft_count_digit(n) - 1;
	if (!(str = malloc(sizeof(char) * (ft_count_digit(n) + 1))))
		return (NULL);
	nb = n < 0 ? n * -1 : n;
	while (nb != 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (i == 0)
		str[i] = '-';
	str[ft_count_digit(n)] = '\0';
	return (str);
}
