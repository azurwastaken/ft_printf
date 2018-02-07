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
	char *buffer;
	int i;
	va_list va;

	buffer = NULL;
	i = 0;
	va_start (va, format);
	if(!(buffer = (char *)malloc(sizeof(char) * ft_strlen(format)))) // idk si je doit mettre + 1
		return(0);
	while(*format != '\0')
	{
		while(*format != '%' && *format != '\0')
		{
			buffer[i] = *format;
			i++;
			format++;
		}
		format++;
		if(*format == 'c')
		{
			buffer[i] = (char) va_arg(va, int);
			format++;
			i++;
		}
	}
	
	va_end(va);
	ft_putstr(buffer);
	return(0);
}
