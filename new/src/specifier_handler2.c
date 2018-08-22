/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:39:46 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/22 13:39:51 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

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

char		*p_case(char *str, va_list va, t_flag *flag)
{
	str = ft_convert_base((long)va_arg(va, void *), 16, 'x');
	flag->put_prefix = 1;
	if (str[0] == '0' && flag->isprec)
		return ("");
	return (str);
}

char		*percent_case(char *str, t_flag *flag)
{
	str = ft_strdup("%\0");
	flag->isprec = 0;
	flag->precision = 0;
	return (str);
}
