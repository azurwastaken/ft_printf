/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_flag_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 12:28:53 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/22 12:28:55 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

void	print_flag(int *save, int *i, char *str, t_flag *flag)
{
	*save = ft_strlen(str);
	*i = 0;
	if (flag->right_just)
	{
		ft_putstr(str);
		if (flag->nul_case)
			write(1, "", 1);
		while (*i < flag->width - (*save + flag->nul_case))
		{
			write(1, " ", 1);
			*i += 1;
		}
	}
	else
	{
		while (*i < flag->width - (*save + flag->nul_case))
		{
			write(1, " ", 1);
			*i += 1;
		}
		ft_putstr(str);
		if (flag->nul_case)
			write(1, "", 1);
	}
}

void	delete_str(char **tmp, char **str, t_flag *flag)
{
	if (*str)
		free(*str);
	if ((*tmp && ft_strcmp("(null)", *tmp) && !flag->nul_case &&
		is_charset(flag->specifier, "CS")))
		free(*tmp);
	if (flag->length)
		free(flag->length);
}
