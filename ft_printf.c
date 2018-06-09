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

char		*ft_convert_base(long num, int base, char letter)
{
	static char 	digit[] = "0123456789ABCDEF";
	static char 		buffer[50];
	char 		*res;
	int i;

	i = 10;
	while(i < 16 && letter == 'x')
	{
		digit[i] = ft_tolower(digit[i]);
		i++;
	}
	res = &buffer[49];
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
	free(new);
	return(0);
}

int		ft_printf(const char * restrict format, ...)
{
	int i;
	char **str_tab;
	va_list va;

	i = 0;
	va_start (va, format);
	str_tab = ft_parse((char *)format);
	while(str_tab[i] != 0)
	{
		printf("%s\n",str_tab[i]);
		i++;
	}
	va_end(va);
	//ft_putstr(buffer);
	return(0);

}
