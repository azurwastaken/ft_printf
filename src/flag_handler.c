/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:02:06 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/14 15:02:18 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

static char		*ft_strfreecopy(char *src)
{
	if (src)
		ft_strdel(&src);
	src = ft_strdup("l\0");
	return (src);
}

char			*func_hub(va_list va, t_flag *flag)
{
	char *str;

	str = NULL;
	if (flag->specifier == 'D' || flag->specifier == 'O' ||
		flag->specifier == 'U' || flag->specifier == 'C' || flag->specifier == 'S')
	{
		flag->specifier = ft_tolower(flag->specifier);
		flag->length = ft_strfreecopy(flag->length);
	}
	if (flag->specifier == '%')
		str = percent_case(str, flag);
	else if (flag->specifier == 's')
		str = s_case(str, va, flag);
	else if (flag->specifier == 'c')
		str = c_case(str, va, flag);
	else if (flag->specifier == 'p')
		str = p_case(str, va, flag);
	else if (flag->specifier == 'd' || flag->specifier == 'i')
		str = d_case(str, va, flag);
	else if (flag->specifier == 'o' || flag->specifier == 'u' ||
		flag->specifier == 'x' || flag->specifier == 'X')
		str = oux_case(str, va, flag);
	return (str);
}
