/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:00:48 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/16 15:56:13 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdio.h>//

int						is_a_label(char *line)
{
	char			*label;
	int				len;
	int				i;

	if (!(label = ft_strchr(line, LABEL_CHAR)))
		return (0);
	i = 0;
	len = label - line;
	while (i < len)
	{
		if (!ft_strchr(LABEL_CHARS, line[i]))
			return (0);
		i++;
	}
	return (1);
}

int						add_to_list(t_label *new, t_asm *asm_h)
{
	t_list			*tmp;

	if (asm_h->label_list == NULL)
	{
		if ((asm_h->label_list = ft_lstnew(NULL, sizeof(new))) == NULL)
			return (malloc_error());
		asm_h->label_list->content = new;
	}
	else
	{
		if ((tmp = ft_lstnew(NULL, sizeof(new))) == NULL)
			return (malloc_error());
		tmp->content = new;
		ft_lstadd(&(asm_h->label_list), tmp);
	}
	return (0);
}

int						add_label(char **line, t_asm *asm_h)
{
	int			len;
	int			err;
	char		*ptr;
	t_label		*new;

	if ((new = (t_label *)malloc(sizeof(t_label))) == NULL)
		return (malloc_error());
	len = ft_strchr(*line, LABEL_CHAR) - *line;
	ptr = *line + len;
	*ptr = 0;
	if ((new->name = ft_strdup(*line)) == NULL)
		return (malloc_error());
	if (*new->name == 0)
	{
		ft_strdel(&new->name);
		free(new);
		return (-8);
	}
	*ptr = ':';
	ptr = asm_strnext(ptr + 1);
	new->addr = asm_h->addr;
	if ((err = add_to_list(new, asm_h)) < 0)
		return (err);
	*line += len + 1;
	*line = asm_strnext(*line);
	return (0);
}
