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

int		ft_printf(const char * restrict format, ...)
{
	int c;
	int i = 0;
	va_list va;
	va_start (va, format);

	while(*format++)
	{
		if(*format == '%')
			i++;
	}

	while(i--)
	{
		c = va_arg(va, int);
		printf("%d\n",c);
	}

	va_end(va);
	return(0);
}
