/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 13:24:05 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/18 19:41:56 by mmervoye         ###   ########.fr       */
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

char				*get_line_comment_name(char *line,\
		t_asm *asm_h)
{
	char		*tmp;
	char		*ret;

	if (*line != '"')
		return (NULL);
	line++;
	if ((tmp = ft_strjoin(line, "\n")) == NULL)
		return (malloc_error() ? NULL : NULL);
	if (ft_strchr(tmp, '"'))
		return (tmp);
	while (get_next_line(asm_h->fd, &ret))
	{
		if ((ret = ft_strjoinf(ret, "\n")) == NULL)
			return (NULL);
		if ((tmp = ft_strjoinf(tmp, ret)) == NULL)
			return (NULL);
		if (ft_strchr(tmp, '"'))
		{
			ft_strdel(&ret);
			return (tmp);
		}
		ft_strdel(&ret);
	}
	ft_strdel(&ret);
	return (NULL);
}

int					asm_count_word(char *line)
{
	char		*ptr;
	int			ret;

	if ((ptr = ft_strchr(line, COMMENT_CHAR)) != NULL)
		*ptr = 0;
	ret = ft_count_word(line, SEPARATOR_CHAR);
	return (ret);
}
