/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 15:00:48 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/08 15:43:25 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int						add_label(char **line, t_asm *asm_h)
{
	int			len;

	len = ft_strchr(*line, LABEL_CHAR) - *line;
	*line += ft_strlen(*line);
	return (0);
}
