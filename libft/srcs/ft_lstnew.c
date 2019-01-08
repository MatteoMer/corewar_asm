/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:35:14 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/08 10:36:16 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*new;
	void		*ncontent;
	size_t		ncsize;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		ncontent = ft_memalloc(content_size);
		ncsize = content_size;
		ncontent = ft_memcpy(ncontent, content, ncsize);
		new->content = ncontent;
		new->content_size = ncsize;
	}
	new->next = NULL;
	return (new);
}
