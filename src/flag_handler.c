/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:45:09 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/07/04 10:45:17 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

char		*space_case(char *str)
{
	if (str[0] != '-')
		str = ft_strjoin(" ", str);
	return (str);
}

char		*create_str(char c, int length, int is_neg)
{
	char	*str;
	int		i;

	length += is_neg;
	if (!(str = (char *)malloc(sizeof(char) * length)))
		return (0);
	i = 0;
	if (is_neg)
		str[i++] = '-';
	while (i < length)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

char		*plus_case(char *str)
{
	if (str[0] != '-')
		str = ft_strjoin("+", str);
	return (str);
}
