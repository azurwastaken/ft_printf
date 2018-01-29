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

static int		ft_find_next_word(char const *str, int i, char c)
{
	while (str[i] == c && str[i] != '\0')
		i = i + 1;
	return (i);
}

static int		ft_count_words(char const *str, char c)
{
	int		i;
	int		words;

	i = 0;
	words = 0;
	while (str[i] != '\0')
	{
		i = ft_find_next_word(str, i, c);
		words = str[i] != '\0' ? words + 1 : words;
		while (str[i] != c && str[i] != '\0')
			i = i + 1;
	}
	return (words);
}

static int		ft_length_act_wrd(char const *str, int i, char c)
{
	int		j;

	j = i;
	while (str[j] != c && str[j] != '\0')
		j = j + 1;
	return ((j - i) + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**wd;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (0);
	if (!(wd = (char **)malloc(sizeof(char*) * ft_count_words(s, c) + 1)))
		return (NULL);
	while (j < ft_count_words(s, c))
	{
		i = ft_find_next_word(s, i, c);
		if (!(wd[j] = (char *)malloc(sizeof(char) *
						(ft_length_act_wrd(s, i, c) + 1))))
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			wd[j][k++] = s[i++];
		wd[j++][k] = '\0';
		k = 0;
	}
	wd[j] = 0;
	return (wd);
}
