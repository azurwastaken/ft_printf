/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:46:21 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/07/04 13:46:28 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

char	*parse_flag(char *str, t_flag *flag, va_list va)
{
	int i;

	i = 0;
	while (is_charset(str[i], "-+ 0%#"))
	{
		flag->is_flag = 1;
		if (str[i] == '-')
			flag->right_just = 1;
		else if (str[i] == '+')
			flag->en_sign = 1;
		else if (str[i] == ' ')
			flag->spacef = 1;
		else if (str[i] == '0')
			flag->fill_zero = 1;
		else if (str[i] == '#')
			flag->put_prefix = 1;
		i++;
		if (str[i] == '%')
			return(parse_specifier(str, flag, i));
	}
	if (flag->right_just == 1)
		flag->fill_zero = 0;
	if (flag->en_sign == 1)
		flag->spacef = 0;
	return (parse_width(str, flag, i, va));
}

int		get_end_nb(char *str)
{
	int i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == '*')
		i++;
	return (i);
}

char	*parse_width(char *str, t_flag *flag, int i, va_list va)
{
	char **split;

	flag->precision = 0;
	if ((flag->isprec = is_prec(str)))
	{
		split = ft_strsplit(str, '.');
		if (split[1][0] == '*')
			flag->precision = va_arg(va, int);
		else
			flag->precision = ft_atoi(split[1]);
		flag->width = ft_atoi(&split[0][i]);
		i = ft_strlen(split[0]) + get_end_nb(split[1]) + 1;
		free(split[1]);
		free(split[0]);
		free(split);
	}
	else
	{
		flag->width = ft_atoi(&str[i]);
		i += get_end_nb(&str[i]);
	}
	return (parse_length(str, flag, i));
}

char	*parse_length(char *str, t_flag *flag, int i)
{
	if (str[i] == 'h')
	{
		flag->length = str[i + 1] == 'h' ? ft_strdup("hh") : ft_strdup("h");
		i += ft_strcmp(flag->length, "hh") == 0 ? 2 : 1;
		flag->is_length = 1;
	}
	else if (str[i] == 'l')
	{
		flag->length = str[i + 1] == 'l' ? ft_strdup("ll") : ft_strdup("l");
		i += ft_strcmp(flag->length, "ll") == 0 ? 2 : 1;
		flag->is_length = 1;
	}
	else if (str[i] == 'j')
	{
		flag->length = ft_strdup("j");
		flag->is_length = 1;
	}
	else if (str[i] == 'z')
	{
		flag->length = ft_strdup("z");
		flag->is_length = 1;
	}
	else
		flag->is_length = 0;
	return (parse_specifier(str, flag, i));
}

char	*parse_specifier(char *str, t_flag *flag, int i)
{
	flag->specifier = str[i];
	return (str);
}
