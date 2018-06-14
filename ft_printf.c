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
	flag->width = 0;
	flag->length = NULL;
	flag->is_length = 0;
	flag->specifier = 0;
	flag->nb_percent = 0;
	flag->put_prefix = 0;

	return(flag);
}

void	ft_buff_test(char *str)
{
	t_flag *flag;

	if(!(flag = init_t_flag()))
		return ;
	str = parse_flag(str, flag);
	printf("%s\n",str);
	printf("is_flag = %d\n",flag->is_flag);
	printf("right_just = %d\n",flag->right_just);
	printf("en_sign = %d\n",flag->en_sign);
	printf("space_f = %d\n",flag->spacef);
	printf("fill_zero = %d\n",flag->fill_zero);
	printf("put_prefix = %d\n",flag->put_prefix);
	printf("precision = %d\n",flag->precision);
	printf("width = %d\n",flag->width);
	printf("length = %s\n",flag->length);
	printf("is_length = %d\n",flag->is_length);
	printf("specifier = %c\n",flag->specifier);
	printf("nb_percent = %d\n\n\n",flag->nb_percent);
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
		printf("i = %d strtab = %s\n", i, str_tab[i]);
		if(str_tab[i][0] == '%')
			ft_buff_test(str_tab[i]);
		//printf("%s\n",str_tab[i]);
		i++;
	}
	va_end(va);
	//ft_putstr(buffer);
	return(0);

}
