/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:00:34 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/08/17 13:02:31 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_printf.h"

int				ft_wclen(wchar_t c)
{
	if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (0);
}

int				ft_wcslen(wchar_t *s)
{
	int			len;
	int			i;

	len = 0;
	i = 0;
	if (!s)
		return (-1);
	while (s[i] != L'\0')
	{
		len += ft_wclen(s[i]);
		i++;
	}
	return (len);
}

char			*ft_wctostr(wchar_t c)
{
	char		*str;

	if (!(str = ft_strnew(ft_wclen(c))))
		return (NULL);
	if (c <= 0x7F)
		str[0] = (unsigned char)c;
	else if (c <= 0x7FF)
	{
		str[0] = (c >> 6) | 0xC0;
		str[1] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0xFFFF)
	{
		str[0] = (c >> 12) | 0xE0;
		str[1] = (c >> 6 & 0x3F) | 0x80;
		str[2] = (c & 0x3F) | 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = (c >> 18) | 0xF0;
		str[1] = (c >> 12 & 0x3F) | 0x80;
		str[2] = (c >> 6 & 0x3F) | 0x80;
		str[3] = (c & 0x3F) | 0x80;
	}
	return (str);
}
