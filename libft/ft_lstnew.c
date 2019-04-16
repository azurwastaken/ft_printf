/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcaseaux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 14:54:57 by mcaseaux          #+#    #+#             */
/*   Updated: 2017/11/24 17:15:59 by mcaseaux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = NULL;
	new->content_size = 0;
	new->next = NULL;
	if (!content || content_size <= 0)
		return (new);
	new->content = malloc(content_size);
	if (!new->content)
		return (NULL);
	ft_memcpy(new->content, content, content_size);
	new->content_size = content_size;
	return (new);
}
