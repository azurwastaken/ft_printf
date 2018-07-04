/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 14:02:04 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/07/04 14:02:08 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

void	special_case(t_flag *flag)
{
	if (flag->specifier == 'D' || flag->specifier == 'O' ||
		flag->specifier == 'U')
	{
		ft_tolower(flag->specifier);
		flag->length = "l";
	}
}

int		is_flag(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' ||
			c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' ||
			c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

t_flag	*init_t_flag(void)
{
	t_flag *flag;

	if (!(flag = malloc(sizeof(t_flag))))
		return (0);
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
	return (flag);
}

int		ft_print_str(char *str)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(str);
	while (j < i)
	{
		write(1, &str[j], 1);
		j++;
	}
	return (i);
}

int		is_prec(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}
