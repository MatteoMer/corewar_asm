/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:21:18 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/10 18:52:29 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					get_name(char *line, t_asm *asm_h)
{
	line += ft_strlen(NAME_CMD_STRING);
	line = asm_strnext(line);
	if (*line == 0 || *line == COMMENT_CHAR)
		return (-4);
	if (ft_strlen(line) > PROG_NAME_LENGTH)
		return (-6);
	ft_bzero(asm_h->prog_name, PROG_NAME_LENGTH);
	ft_strcat(asm_h->prog_name, line);
	return (0);
}

int					get_comment(char *line, t_asm *asm_h)
{
	line += ft_strlen(COMMENT_CMD_STRING);
	line = asm_strnext(line);
	if (*line == 0 || *line == COMMENT_CHAR)
		return (-5);
	if (ft_strlen(line) > COMMENT_LENGTH)
		return (-7);
	ft_bzero(asm_h->comment, COMMENT_LENGTH);
	ft_strcat(asm_h->comment, line);
	return (0);
}

int					line_parse(char *line, t_asm *asm_h)
{
	int			err;

	if (!ft_strncmp(NAME_CMD_STRING, line, ft_strlen(NAME_CMD_STRING)))
		err = get_name(line, asm_h);
	else if (!ft_strncmp(COMMENT_CMD_STRING, line, ft_strlen(COMMENT_CMD_STRING)))
		err = get_comment(line, asm_h);
	else
	{
		while ((err = is_a_label(line)))
		{
			if (err < 0)
				return (err);
			err = add_label(&line, asm_h);
		}
		if (*line && *line != COMMENT_CHAR)
			err = get_instructions(asm_h, &line);
	}
	if (err < 0)
		return (err);
	return (0);
}

int					parse(t_asm *asm_h)
{
	int				ret;
	int				err;
	char			*line;
	char			*tmp;

	while ((ret = get_next_line(asm_h->fd, &line)) > 0)
	{
		tmp = asm_strnext(line);
		if (!(*tmp == COMMENT_CHAR || *tmp == 0))
			err = line_parse(tmp, asm_h);
		if (err < 0)
			return (err);
		ft_strdel(&line);
	}
	if (ret < 0)
		return (malloc_error());
	return (0);
}
