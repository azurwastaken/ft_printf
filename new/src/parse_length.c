/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 13:07:22 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/22 13:07:25 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

void	h_case(char **format, t_flag *flag)
{
	flag->length = format[0][1] == 'h' ? ft_strdup("hh") : ft_strdup("h");
	*format += ft_strcmp(flag->length, "hh") == 0 ? 2 : 1;
	flag->is_length = 1;
}

char	*parse_length(char *format, t_flag *flag)
{
	if (*format == 'h' && flag->length == NULL)
		h_case(&format, flag);
	else if (*format == 'l' && (flag->length == NULL ||
		is_charset(flag->length[0], "h")))
	{
		flag->length = format[1] == 'l' ? ft_strdup("ll") : ft_strdup("l");
		format += ft_strcmp(flag->length, "ll") == 0 ? 2 : 1;
		flag->is_length = 1;
	}
	else if (*format == 'j' && (flag->length == NULL ||
		is_charset(flag->length[0], "hlz")))
	{
		flag->length = ft_strdup("j");
		format += (flag->is_length = 1);
	}
	else if (*format == 'z' && (flag->length == NULL ||
		is_charset(flag->length[0], "hl")))
	{
		flag->length = ft_strdup("z");
		format += (flag->is_length = 1);
	}
	else
		flag->is_length = 0;
	return (format);
}
