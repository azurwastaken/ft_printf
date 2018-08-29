/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <mcaseaux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:43:11 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/23 14:47:35 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

char		*ft_print_unis(va_list va)
{
	wchar_t		*s;
	int 		i;
	char 		*to_print;
	char		*tmp;

	s = va_arg(va, wchar_t*);
	if (s)
	{
		to_print = ft_strnew(ft_wcslen(s));
		i = -1;
		while (s[++i])
		{
			tmp = ft_wctostr(s[i]);
			ft_strcat(to_print, tmp);
			free(tmp);
		}
		return (to_print);
	}
	return (NULL);
}

char		*s_case(char *str, va_list va, t_flag *flag)
{
	if (flag->length == NULL)
		str = va_arg(va, char*);
	else if (ft_strcmp(flag->length, "l") == 0)
		str = ft_print_unis(va);
	if (str == NULL)
	{
		str = ft_strdup("(null)");
		return (str);
	}
	if (str[0] != '\0' && str[0])
		flag->spacef = 0;
	return (str);
}

char		*ft_print_unic(va_list va)
{
	wint_t		c;
	char		*str;

	c = va_arg(va, wchar_t);
	if(!(str = ft_wctostr(c)))
		return(NULL);
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
		str = ft_print_unic(va);
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
		str = ft_convert_bde((long long)((signed short)va_arg(va, int)),
			10, 'd');
	else if (ft_strcmp(flag->length, "hh") == 0)
		str = ft_convert_bde((long long)((char)va_arg(va, int)), 10, 'd');
	else if (ft_strcmp(flag->length, "j") == 0)
		str = ft_convert_bde((long long)va_arg(va, intmax_t), 10, 'd');
	else if (ft_strcmp(flag->length, "z") == 0)
		str = ft_convert_bde((long long)va_arg(va, size_t), 10, 'd');
	if (str[0] == '0' && flag->isprec && flag->precision == 0)
		return ("");
	return (str);
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
