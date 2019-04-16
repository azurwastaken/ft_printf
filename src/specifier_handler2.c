/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:35:09 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/09/03 14:35:11 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

char		*p_case(char *str, va_list va, t_flag *flag)
{
	str = ft_convert_base((long)va_arg(va, void *), 16, 'x');
	flag->put_prefix = 1;
	if (str[0] == '0' && flag->isprec)
		return ("");
	return (str);
}

char		*percent_case(t_flag *flag)
{
	flag->isprec = 0;
	flag->precision = 0;
	return ("%\0");
}

char		*get_oux_str(char *str, va_list va, t_flag *flag, int base)
{
	if (flag->length == NULL)
		str = ft_convert_base((long)va_arg(va, unsigned int),
			base, flag->specifier);
	else if (ft_strcmp(flag->length, "l") == 0)
		str = ft_convert_base((unsigned long long)va_arg(va, unsigned long),
			base, flag->specifier);
	else if (ft_strcmp(flag->length, "ll") == 0)
		str = ft_convert_base((long)va_arg(va, unsigned long long),
			base, flag->specifier);
	else if (ft_strcmp(flag->length, "hh") == 0)
		str = ft_convert_base((long)((unsigned char)va_arg(va, int)),
			base, flag->specifier);
	else if (ft_strcmp(flag->length, "h") == 0)
		str = ft_convert_base((long)((unsigned short)va_arg(va, int)),
			base, flag->specifier);
	else if (ft_strcmp(flag->length, "j") == 0)
		str = ft_convert_base((unsigned long long)va_arg(va, uintmax_t),
			base, flag->specifier);
	else if (ft_strcmp(flag->length, "z") == 0)
		str = ft_convert_base((long)va_arg(va, size_t), base, flag->specifier);
	else if (flag->length == NULL)
		str = ft_convert_base((long)va_arg(va, unsigned int),
			base, flag->specifier);
	return (str);
}

char		*oux_case(char *str, va_list va, t_flag *flag)
{
	int base;

	base = 10;
	if (flag->specifier == 'x' || flag->specifier == 'X')
		base = 16;
	else if (flag->specifier == 'o' || flag->specifier == 'O')
		base = 8;
	str = get_oux_str(str, va, flag, base);
	flag->put_prefix = str[0] == '0' && is_charset(flag->specifier, "xX") ?
	0 : flag->put_prefix;
	if (str[0] == '0' && (flag->isprec ||
		(flag->specifier == 'o' && flag->put_prefix)))
		str[0] = '\0';
	return (str);
}
