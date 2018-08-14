/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:43:11 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/14 16:43:13 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

char	*s_case(char *str, va_list va, t_flag *flag)
{
	//if(ft_strcmp(flag->length,"l"))
	//	str = ft_strdup(va_arg(va, wchar_t *));
	/*else*/ if (flag->length == NULL)
		str = va_arg(va, char*);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		return (str);
	}
	if (str[0] != '\0' && str[0])
		flag->spacef = 0;
	return (str);
}

char *ft_print_unicode(wchar_t c, char *str)
{
	char tab[4];
	char tmp[4];
	int i;
	int j;

	i = 0;
	while (i < 4)
		tab[i++] = 0;
	i = 0;
	while (c > 0)
	{
		tab[i] = c & 0xff;
		c = c >> 8;
		i++;
	}
	j = 0;
	while (i >= 0)
	{
		tmp[j++] = tab[i--];
	}
	str = ft_strdup((char *)tmp);
	return (str);
}

char		*c_case(char *str, va_list va, t_flag *flag)
{
	char c[2];

	c[1] = '\0';
	flag->spacef = 0;
	if (flag->length == NULL)
	{
		c[0] = (char)va_arg(va, int);
		str = ft_strdup((char *)c);
	}
	else if (ft_strcmp(flag->length, "l") == 0)
			str = ft_print_unicode(va_arg(va, wint_t), str);
	return (str);
}

char		*d_case(char *str, va_list va, t_flag *flag)
{

	if (flag->length == NULL)
		str = ft_convert_bde((long long)va_arg(va, int), 10, 'd');
	else if (ft_strcmp(flag->length, "l") == 0)
		str = ft_convert_bde((long long)va_arg(va, long), 10, 'd');
	else if (ft_strcmp(flag->length, "ll") == 0)
		str = ft_convert_bde(va_arg(va, long long), 10, 'd');
	else if (ft_strcmp(flag->length, "h") == 0)
		str = ft_convert_bde((long long)((signed short)va_arg(va, int)), 10, 'd');
	else if (ft_strcmp(flag->length, "hh") == 0)
		str = ft_convert_bde((long long)((char)va_arg(va, int)), 10,'d');
	else if (ft_strcmp(flag->length, "j") == 0)
		str = ft_convert_bde((long long)va_arg(va, intmax_t), 10, 'd');
	else if (ft_strcmp(flag->length, "z") == 0)
		str = ft_convert_bde((long long)va_arg(va, size_t), 10, 'd');
	if (str[0] == '0' && flag->isprec && flag->precision == 0)
		return ("");
	return (str);
}

char		*oux_case(char *str, va_list va, t_flag *flag)
{
	int base;

	if (flag->specifier == 'x' || flag->specifier == 'X')
		base = 16;
	else if (flag->specifier == 'o' || flag->specifier == 'O')
		base = 8;
	else if (flag->specifier == 'u' || flag->specifier == 'U')
		base = 10;
	if (flag->length == NULL)
		str = ft_convert_base((long)va_arg(va, unsigned int), base, flag->specifier);
	else if (ft_strcmp(flag->length, "l") == 0)
		str = ft_convert_base((unsigned long long)va_arg(va, unsigned long), base, flag->specifier);
	else if (ft_strcmp(flag->length, "ll") == 0)
		str = ft_convert_base((long)va_arg(va, unsigned long long), base, flag->specifier);
	else if (ft_strcmp(flag->length, "hh") == 0)
		str = ft_convert_base((long)((unsigned char)va_arg(va, int)), base, flag->specifier);
	else if (ft_strcmp(flag->length, "h") == 0)
		str = ft_convert_base((long)((unsigned short)va_arg(va, int)), base, flag->specifier);
	else if (ft_strcmp(flag->length, "j") == 0)
		str = ft_convert_base((unsigned long long)va_arg(va, uintmax_t), base, flag->specifier);
	else if (ft_strcmp(flag->length, "z") == 0)
		str = ft_convert_base((long)va_arg(va, size_t), base, flag->specifier);
	else if (flag->length == NULL)
		str = ft_convert_base((long)va_arg(va, unsigned int), base, flag->specifier);
	flag->put_prefix = str[0] == '0' && is_charset(flag->specifier,"xX") ? 0 : flag->put_prefix;
	if (str[0] == '0' && (flag->isprec || (flag->specifier == 'o' && flag->put_prefix)))
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
