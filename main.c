/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 13:46:38 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/01/29 14:10:00 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"
#include <stdio.h>
int	 main(void)
{ 
	int a = 15;

	ft_printf("%d\n",42);
	printf("%d\n",42);
	ft_printf("%i\n",42);
	printf("%i\n",42);
	ft_printf("%x\n",15);
	printf("%x\n",15);
	ft_printf("%c\n",'A');
	printf("%c\n",'A');
	ft_printf("%o\n",77);
	printf("%o\n",77);
	ft_printf("%u\n",42);
	printf("%u\n",42);
	ft_printf("%p\n",&a);
	printf("%p\n",&a);
	ft_printf("%s\n","zalu");
	printf("%s\n","zalu");
	return(0);
}
