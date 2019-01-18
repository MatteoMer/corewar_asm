/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:24:05 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/18 13:51:36 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char				*asm_strtrim(char *line)
{
	char			*tmp;
	char			*comment_ptr;

	tmp = NULL;
	if (!ft_strchr(line, COMMENT_CHAR))
	{
		if ((tmp = ft_strtrim(line)) == NULL)
			return (NULL);
		else
			return (tmp);
	}
	else
	{
		comment_ptr = ft_strchr(line, COMMENT_CHAR);
		*comment_ptr = 0;
		if ((tmp = ft_strtrim(line)) == NULL)
			return (NULL);
		*comment_ptr = COMMENT_CHAR;
		return (tmp);
	}
}

int					free_and_ret_err(void *to_free1, void *to_free2, \
		char **tab_to_free, int ret)
{
	ft_memdel(&to_free1);
	ft_memdel(&to_free2);
	if (tab_to_free)
		ft_deltab(&tab_to_free);
	return (ret);
}

uint16_t			rev_endian16(uint16_t i)
{
	return ((i >> 8) | (i << 8));
}
