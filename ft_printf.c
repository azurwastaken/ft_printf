/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:26:38 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/01/29 14:10:02 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"
#include <stdio.h>

char		*ft_convert_base(long long num, int base, char letter)
{
	static char	digit[] = "0123456789ABCDEF";
	static char	buffer[70];
	char 		*res;
	int			i;

	i = 10;
	while (i < 16 && letter == 'x')
	{
		digit[i] = ft_tolower(digit[i]);
		i++;
	}
	res = &buffer[70];
	*res = '\0';
	*--res = digit[num % base];
	num = num / base;
	while(num != 0)
	{
		*--res = digit[num % base];
		num = num / base;
	}
	return(res);
}

static t_flag		*init_t_flag(void)
{
	t_flag *flag;

	if(!(flag = malloc(sizeof(t_flag))))
		return(0);
	flag->is_flag = 0;
	flag->right_just = 0;
	flag->en_sign = 0;
	flag->spacef = 0;
	flag->fill_zero = 0;
	flag->precision = 0;
	flag->isprec = 0;
	flag->width = 0;
	flag->length = NULL;
	flag->is_length = 0;
	flag->specifier = 0;
	flag->nb_percent = 0;
	flag->put_prefix = 0;

	return(flag);
}

char	*set_array(char *str, va_list va, t_flag *flag)
{
	if(flag->specifier == '%')	
		str = percent_case(str);
	else if(flag->specifier == 's')
		str = s_case(str, va, flag);
	else if(flag->specifier == 'c')
		str = c_case(str, va, flag);
	else if(flag->specifier == 'p')
		str = p_case(str, va, flag);
	else if(flag->specifier == 'd')
		str = d_case(str, va, flag);
	else if(flag->specifier == 'i')
		str = d_case(str, va, flag);
	else if(flag->specifier == 'o')
		str = oux_case(str, va, flag);
	else if(flag->specifier == 'u')
		str = oux_case(str, va, flag);
	else if(flag->specifier == 'x')
		str = oux_case(str, va, flag);

	return(str);
}

char	*printf_hub(char *str, t_flag *flag)
{
	if(flag->isprec)
		str = precision_handler(str, flag);
	if(flag->width > 0)
		str = width_handler(str, flag);
	return(str);
}

char	*ft_buff_test(char *str, va_list va)
{
	t_flag *flag;
	//char *tmp;

	if(!(flag = init_t_flag()))
		return (0);
	str = parse_flag(str, flag, va);
	special_case(flag);
	str = set_array(str, va, flag);
	str = printf_hub(str, flag);
	free(flag);
	return(str);
}

int 	ft_print_str(char *str)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(str);
	while(j < i)
	{
		write(1, &str[j], 1);
		j++;
	}
	return(i);
}

int		ft_printf(const char * restrict format, ...)
{
	int i;
	int res;
	char **str_tab;
	va_list va;

	i = 0;
	res = 0;
	va_start (va, format);
	str_tab = ft_parse((char *)format);
	while(str_tab[i] != 0)
	{
		if(str_tab[i][0] == '%')
				str_tab[i] = ft_buff_test(str_tab[i], va);
		res += ft_print_str(str_tab[i]);
		i++;
	}
	free(str_tab);
	va_end(va);
	//ft_putstr(buffer);
	return(res);
}
