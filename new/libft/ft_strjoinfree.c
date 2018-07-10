/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 11:57:23 by mcaseaux          #+#    #+#             */
/*   Updated: 2018/06/18 11:57:41 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}
