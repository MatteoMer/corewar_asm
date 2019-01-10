/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:50:55 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/10 19:02:11 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						op_exist(char *name, t_asm *asm_h, t_instruction *new)
{
	int				i;

	i = -1;
	while (asm_h->op[++i].name)
	{
		if (!ft_strcmp(asm_h->op[i].name, name))
		{
			new->op = &asm_h->op[i];
			return (0);
		}
	}
	return (-1);
}

int						get_instructions(t_asm *asm_h, char **line)
{
	t_instruction		*new;
	char				*ptr;

	if ((new = (t_instruction *)malloc(sizeof(t_instruction))) == NULL)
		return (malloc_error());
	ptr = ft_strchr(*line, ' ');
	*ptr = 0;
	if ((new->name = ft_strdup(*line)) == NULL)
		return (malloc_error());
	if (op_exist(new->name, asm_h, new) < 0)
		return (-9);
	asm_h->addr += new->op->to_encode + 1;
	*ptr = ' ';
	*line += ft_strlen(*line);
	return (0);
}
