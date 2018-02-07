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

int		ft_scase(char** buffer,const char* format, char *str)
{
	char	*new;
	int	size;

	size = ft_strcmp(*buffer, format) > 0 ? ft_strlen(format) : ft_strlen(*buffer);
	if(!(new = (char *)malloc(sizeof(char) * size + ft_strlen(str))))
		return(1);
	ft_strcpy(new, *buffer);
	free(*buffer);
	ft_strcat(new, str);
	*buffer = new;
	return(0);
}

int		ft_printf(const char * restrict format, ...)
{
	char *buffer;
	int i;
	char *str;
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
		if(*format != '\0')
		{
			format++;
			if(*format == 'c')
			{
				buffer[i] = (char) va_arg(va, int);
				format++;
				i++;
			}
			else if(*format == 's')
			{
				str = va_arg(va, char *);
				if(ft_scase(&buffer, format, str) != 0)
					return(0);
				format++;
				i += ft_strlen(str);
			}
			else if(*format == 'd')
			{
				str = ft_itoa(va_arg(va, int));
				if(ft_scase(&buffer, format, str) != 0)
					return(0);
				format++;
				i += ft_strlen(str);
			}
			else if(*format == '%')
			{
				buffer[i] = *format;
				i++;
				format++;
			}
			else
			{
				ft_printf("error \"%c\" after \"%%\" is undefined\n", *format);
				return(0);
			}
		}
	}
	va_end(va);
	ft_putstr(buffer);
	return(0);

}
