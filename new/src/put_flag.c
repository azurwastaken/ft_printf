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

	i = 0;
	tmp = func_hub(va, flag);
	flag->nul_case = flag->specifier == 'c' && tmp[0] == 0 ? 1 : 0;
	save = ft_strlen(tmp);
	if (!(str = (char *)malloc(sizeof(char) * (calc_len(flag, save)))))
		return ;
	if (flag->en_sign && tmp[0] != '-' && is_charset(flag->specifier, "dDi"))
		str[i++] = '+';
	i = put_ddi_sign(flag, &tmp, str, &save);
	put_ooxxp_prefix(flag, str, &i, &save);
	handle_prec_num(flag, &save, &i, str);
	if (flag->isprec && flag->specifier == 's')
		save = handle_prec_str(flag, &i, tmp, str);
	handle_fill_zero(flag, &save, &i, str);
	while (*tmp && !(flag->isprec && flag->specifier == 's'))
		str[i++] = *tmp++;
	str[i] = '\0';
	print_flag(&save, &i, str, flag);
	flag->res += flag->nul_case ? i + ft_strlen(str) + 1 : i + ft_strlen(str);
	delete_str(&tmp, &str, flag);
}
