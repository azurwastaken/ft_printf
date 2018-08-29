/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:09:11 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/23 12:50:57 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

void	ft_putflagfree(t_flag *flag)
{
	write(1, flag->buffer, ft_strlen(flag->buffer));
	free(flag);
}

char	*normal_case(t_flag *flag, char *format, va_list va)
{
	flag->specifier = *format++;
	if (flag->isprec && flag->specifier == '%')
		flag->isprec = 0;
	else if (flag->isprec)
		flag->fill_zero = 0;
	put_flag(flag, va);
	return (format);
}

void	full_buff(t_flag *flag)
{
	write(1, flag->buffer, 4096);
	flag->res += 4096;
	flag->i = 0;
}

char	*process(char *format, t_flag *flag, va_list va)
{
	char *save;

	flag->buffer[flag->i] = '\0';
	write(1, flag->buffer, flag->i);
	flag->i = 0;
	format++;
	format = parse_main((char *)format, flag);
	while (!is_charset(*format, "sSpdDioOuUxXcC%") && *format != '\0' &&
		is_charset(*format, "sSpdDioOuUxXcC%hljz 0+-#123456789"))
	{
		save = (char *)format;
		format = parse_main((char *)format, flag);
		if (!ft_strcmp(format, save))
			format++;
	}
	if (is_charset(*format, "sSpdDioOuUxXcC%"))
		format = normal_case(flag, (char *)format, va);
	return (format);
}

int		ft_printf(const char *restrict format, ...)
{
	t_flag	*flag;
	va_list va;

	flag = init_t_flag();
	va_start(va, format);
	flag->res = 0;
	if (!format)
		return (0);
	while (*format != '\0')
	{
		flag = reset_flag(flag);
		while (*format != '%' && flag->i < 4095 && *format != '\0')
		{
			flag->buffer[flag->i++] = *format++;
			flag->res++;
		}
		if (flag->i == 4095)
			full_buff(flag);
		if (*format == '%')
			format = process((char *)format, flag, va);
	}
	flag->buffer[flag->i] = '\0';
	ft_putflagfree(flag);
	va_end(va);
	return (flag->res);
}
