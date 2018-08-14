/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:31:06 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/14 16:31:10 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

int		calc_len(t_flag *flag, int str_len)
{
	int res;

	res = str_len + 1;
	if (is_charset(flag->specifier, "pdDioOuUxX%"))
	{
		res += flag->en_sign ? 1 : 0;
		res += flag->spacef ? 1 : 0;
		res += flag->isprec ? flag->precision : 0;
		if (flag->put_prefix && is_charset(flag->specifier, "oOxX"))
			res += is_charset(flag->specifier, "xX") ? 2 : 1;
		return (flag->width > res ? flag->width : res);
	}
	else if (flag->specifier == 'c')
		return (flag->width > res ? flag->width : res);
	else if (is_charset(flag->specifier, "s"))
	{
		res = res > flag->precision ? flag->precision : res;
		return (flag->width > res ? flag->width : res);
	}
	return (res);
}

void	put_flag(t_flag *flag, va_list va)
{
	char	*str;
	char	*tmp;
	int		save;
	int		i;
	int		nul_case;

	i = 0;
	tmp = func_hub(va, flag);
	//test_t_flag(flag);
	nul_case = flag->specifier == 'c' && tmp[0] == 0 ? 1 : 0;
	save = ft_strlen(tmp);
	if (!(str = (char *)malloc(sizeof(char) * (calc_len(flag, save)))))
		return ;
	if (flag->en_sign && tmp[0] != '-' && is_charset(flag->specifier, "dDi"))
		str[i++] = '+';
	// s'occuper des 0;
	if (is_charset(flag->specifier, "dDi"))
	{
		if (tmp[0] == '-')
		{
			str[0] = *tmp;
			i = 1;
			tmp++;
			save -= 2;
		}
		else if (flag->en_sign || flag->spacef)
		{
			str[0] = flag->en_sign && !(flag->spacef) ? '+' : ' ';
			i = 1;
			save--;
		}
	}
	if (is_charset(flag->specifier, "oOxXp") && flag->put_prefix)
	{
		str[i++] = '0';
		if (is_charset(flag->specifier, "xXp"))
			str[i++] = flag->specifier == 'X' ? 'X' : 'x';
		if (flag->specifier == 'p')
			save -= 2;
	}
	if (flag->isprec && is_charset(flag->specifier, "pdDioOuUxX"))
	{
		if (is_charset(flag->specifier, "xX") && flag->put_prefix)
			save -= 2;
		while (i < (flag->precision - save))
			str[i++] = '0';
	}
	else if (flag->isprec && flag->specifier == 's')
	{
		while (i < flag->precision)
		{
			str[i] = tmp[i];
			i++;
		}
		save = i;
	}
	else if ((!flag->isprec) && flag->fill_zero == 1)
	{
		if (flag->en_sign || str[0] == '-' || flag->spacef)
			save++;
		while (i < (flag->width - (save + nul_case)))
			str[i++] = '0';
	}
	// add str
	while (*tmp && !(flag->isprec && flag->specifier == 's'))
		str[i++] = *tmp++;
	str[i] = '\0';
	//print width
	save = ft_strlen(str);
	i = 0;
	if (flag->right_just)
	{
		ft_putstr(str);
		if (nul_case)
			write(1, "", 1);
		while (i < flag->width - (save + nul_case))
		{
			write(1, " ", 1);
			i++;
		}
	}
	else
	{
		while (i < flag->width - (save + nul_case))
		{
			write(1, " ", 1);
			i++;
		}
		ft_putstr(str);
		if (nul_case)
			write(1, "", 1);
	}
	flag->res += nul_case ? i + ft_strlen(str) + 1 : i + ft_strlen(str);
	if (str[0] != '\0')
		ft_strdel(&str);
	if (tmp[0] != '\0' && flag->specifier != 's')
		ft_strdel(&tmp);
}
