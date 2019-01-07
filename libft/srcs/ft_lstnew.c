/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:35:14 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/28 17:04:21 by xmazella         ###   ########.fr       */
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
		malloc_error();
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
