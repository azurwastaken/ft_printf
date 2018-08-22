/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:18:54 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/14 16:19:00 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

char	*parse_main(char *format, t_flag *flag)
{
	format = parse_flag(format, flag);
	format = parse_width(format, flag);
	format = parse_prec(format, flag);
	format = parse_length(format, flag);
	return (format);
}

char	*parse_flag(char *format, t_flag *flag)
{
	while (is_charset(*format, "-+ 0#"))
	{
		flag->is_flag = 1;
		if (*format == '-')
			flag->right_just = 1;
		else if (*format == '+')
			flag->en_sign = 1;
		else if (*format == ' ')
			flag->spacef = 1;
		else if (*format == '0')
			flag->fill_zero = 1;
		else if (*format == '#')
			flag->put_prefix = 1;
		format++;
	}
	if (flag->right_just == 1)
		flag->fill_zero = 0;
	if (flag->en_sign == 1)
		flag->spacef = 0;
	return (format);
}

char	*parse_width(char *format, t_flag *flag)
{
	flag->width = ft_atoi(format) == 0 ? flag->width : ft_atoi(format);
	while (is_charset(*format, "0123546789"))
		format++;
	return (format);
}

char	*parse_prec(char *format, t_flag *flag)
{
	if (*format == '.')
	{
		format++;
		flag->isprec = 1;
		flag->precision = ft_atoi(format);
		while (is_charset(*format, "0123546789"))
			format++;
		while (*format == '.')
			format++;
	}
	return (format);
}
