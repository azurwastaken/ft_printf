/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfreedup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 13:35:03 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/07/04 13:35:06 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

char	*ft_strfreedup(char *src)
{
	char *mem_alloc;

	if (!(mem_alloc = (char *)malloc(sizeof(*src) * (ft_strlen(src) + 1))))
		return (0);
	mem_alloc = ft_strcpy(mem_alloc, src);
	free(src);
	return (mem_alloc);
}
