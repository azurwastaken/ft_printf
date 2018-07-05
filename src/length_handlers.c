/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:35:27 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/07/04 13:35:34 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*hashtag_case(char *str, t_flag *flag)
{
	char *tmp;

	tmp = str;
	if (flag->specifier == 'x' || flag->specifier == 'p')
		str = ft_strjoin("0x", tmp);
	else if (flag->specifier == 'X')
		str = ft_strjoin("0X", tmp);
	else if (flag->specifier == 'o' && str[0] != 0)
		str = ft_strjoin("0", tmp);
	return (str);
}

char	*precision_handler(char *str, t_flag *flag)
{
	int		str_len;
	char	*pre;

	str_len = ft_strlen(str);
	if (is_charset(flag->specifier, "diouxX"))
	{
		if (str[0] == '-')
		{
			str_len--;
			if ((pre = create_str('0', flag->precision - str_len, 1)))
				str = ft_strjoin(pre, &str[1]);
		}
		else
		{
			if ((pre = create_str('0', flag->precision - str_len, 0)))
				str = ft_strjoin(pre, &str[0]);
		}
	}
	else if (flag->specifier == 's')
	{
		if ((int)ft_strlen(str) > flag->precision)
			str[flag->precision] = '\0';
	}
	return (str);
}

char	*width_handler(char *str, t_flag *flag)
{
	char	*pre;
	int		str_len;

	if (flag->fill_zero == 1)
	{
		flag->precision = str[0] == '-' ? flag->width - 1 : flag->width;
		flag->width = 0;
		if(flag->put_prefix == 1 && is_charset(flag->specifier, "oxXp"))
				flag->precision = flag->specifier == 'o' ? flag->precision - 1 : flag->precision - 2;
		str = precision_handler(str, flag);
		if(flag->put_prefix == 1 && is_charset(flag->specifier, "oxXp"))
			str = hashtag_case(str, flag);

	}
	else
	{
		if(flag->put_prefix == 1 && is_charset(flag->specifier, "oxXp"))
			str = hashtag_case(str, flag);
		str_len = ft_strlen(str);
		if ((pre = create_str(' ', flag->width - str_len, 0)))
		{
			str = flag->right_just == 0 ?
				ft_strjoin(pre, &str[0]) : ft_strjoin(&str[0], pre);
		}
	}
	return (str);
}