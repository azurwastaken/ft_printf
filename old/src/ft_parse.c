/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 10:49:11 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/07/04 10:57:57 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

static int		count_flag(char *format)
{
	int i;
	int res;
	int flag;

	i = 0;
	flag = 0;
	res = format[0] == '%' ? 1 : 2;
	while (format[i] != '\0')
	{
		if (format[i] == '%' || format[i] == ' ')
		{
			res++;
			flag = format[i] == '%' ? 1 : 0;
			i++;
			while (flag == 1 && format[i] != '\0' && !(is_flag(format[i])))
				i++;
			i++;
			res = (flag == 1 && format[i] != '\0') ? res + 1 : res;
			flag = 0;
		}
		if (format[i] == ' ')
			while (format[i] == ' ')
				i++;
		else
			i++;
	}
	return (res);
}

static int		if_percent(char *format)
{
	int i;

	i = 0;
	i++;
	while (!(is_flag(format[i])) && format[i] != '\0')
		i++;
	i++;
	return (i);
}

static int		if_not_percent(char *format)
{
	int i;

	i = 0;
	if (format[0] == ' ')
	{
		while (format[i] == ' ')
			i++;
	}
	while (format[i] != '%' && format[i] != '\0' && format[i] != ' ')
		i++;
	return (i);
}

static char		*get_str(char *format, int *j)
{
	int		i;
	char	*str;

	i = 0;
	if (format[0] == '%')
		i = if_percent(format);
	else
		i = if_not_percent(format);
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	str[i] = '\0';
	*j = i == 0 ? *j + 1 : *j + i;
	i--;
	while (i >= 0)
	{
		str[i] = format[i];
		i--;
	}
	return (str);
}

char			**ft_parse(char *format)
{
	char	**split;
	int		nb_flag;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nb_flag = count_flag(format);
	if (!(split = (char **)malloc(sizeof(char*) * (nb_flag + 1))))
		return (0);
	//printf("nb+flag %d\n", nb_flag);
	while (i < nb_flag)
	{
		split[i] = get_str(&format[j], &j);
		i++;
	}
	split[i] = NULL;
	return (split);
}
