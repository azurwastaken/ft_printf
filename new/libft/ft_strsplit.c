/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 11:48:48 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/23 11:51:00 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_set_array(char **str, char *c, size_t *size, char ***array)
{
	while (**str)
	{
		while (**str == *c && **str)
			*str = *str + 1;
		if (**str)
			*size = *size + 1;
		while (**str != *c && **str)
			*str = *str + 1;
	}
	if (!(*array = (char **)malloc(sizeof(char *) * (*size + 1))))
		return (0);
	return (1);
}

static size_t	ft_copy_strings(char **str, char *c, size_t *len, char ***array)
{
	while (**str == *c && **str)
		*str = *str + 1;
	while (**str != *c && **str)
	{
		*str = *str + 1;
		*len = *len + 1;
	}
	if (!(**array = (char *)malloc(sizeof(char) * (*len + 1))))
		return (0);
	*str = *str - *len;
	while (**str != *c && **str)
	{
		***array = **str;
		**array = **array + 1;
		*str = *str + 1;
	}
	***array = '\0';
	**array = **array - *len;
	return (1);
}

char			**ft_strsplit(const char *s, char c)
{
	size_t		size;
	char		**array;
	char		*str;
	size_t		len;
	size_t		count;

	if (!s)
		return (NULL);
	str = (char *)s;
	size = 0;
	if (!(ft_set_array(&str, &c, &size, &array)))
		return (NULL);
	str = (char *)s;
	count = size;
	while (count--)
	{
		len = 0;
		if (!(ft_copy_strings(&str, &c, &len, &array)))
			return (NULL);
		array++;
	}
	*array = NULL;
	array = array - size;
	return (array);
}