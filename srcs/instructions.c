/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:50:55 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/14 12:14:28 by mmervoye         ###   ########.fr       */
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

int						get_type_param(char *param)
{
	param = asm_strnext(param);
	if (*param == DIRECT_CHAR)
		return (T_DIR);
	else if (*param == 'r')
		return (T_REG);
	return (T_IND);
}

int						get_size_param(t_instruction *i, t_asm *asm_h, t_params *param)
{
	if (param->type == T_DIR)
		param->size = i->op->dir_size;
	else if (param->type == T_REG)
		param->size = 1;
	else
		param->size = 2;
	return (0);
}

int						check_label_and_size(t_instruction *i, t_asm *asm_h, t_params **param)
{
	get_size_param(i, asm_h, *param);
	if (ft_strchr((*param)->content, LABEL_CHAR))
		(*param)->is_label = 1;
	else
		(*param)->is_label = 0;
	return (0);
}

int						get_params(t_asm *asm_h, char *line, t_instruction *new)
{
	t_params		*params;
	t_params		*tmp;
	char			**param_tab;
	int				i;

	i = -1;
	params = NULL;
	if (ft_count_word(line, SEPARATOR_CHAR) != new->op->nb_params)
		return (-10);
	if ((param_tab = ft_strsplit(line, SEPARATOR_CHAR)) == NULL)
		return (malloc_error());
	while (++i < new->op->nb_params)
	{
		if ((tmp = (t_params *)malloc(sizeof(t_params))) == NULL)
			return (malloc_error());
		tmp->type = get_type_param(param_tab[i]);
		tmp->content = ft_strtrim(param_tab[i]);
		check_label_and_size(new, asm_h, &tmp);
		tmp->next = params;
		params = tmp;
		asm_h->addr += tmp->size;
	}
	new->params = params;
	ft_deltab(&param_tab);
	return (0);
}

int						get_instructions(t_asm *asm_h, char **line)
{
	t_instruction		*new;
	char				*ptr;
	int					err;

	if ((new = (t_instruction *)malloc(sizeof(t_instruction))) == NULL)
		return (malloc_error());
	if ((ptr = ft_strchr(*line, ' ')) == NULL)
		return (-12);
	*ptr = 0;
	if ((new->name = ft_strdup(*line)) == NULL)
		return (malloc_error());
	if (op_exist(new->name, asm_h, new) < 0)
		return (-9);
	new->addr = asm_h->addr;
	asm_h->addr += new->op->to_encode == 0 ? 1 : 2;
	*ptr = ' ';
	ptr++;
	if ((err = get_params(asm_h, ptr, new)) < 0)
		return (err);
	asm_h->list_instruction->content = new;
	*line += ft_strlen(*line);
	return (0);
}

int						new_instruction(t_asm *asm_h, char **line)
{
	t_list				*tmp;
	int					err;

	if (asm_h->list_instruction == NULL)
	{
		if ((asm_h->list_instruction = ft_lstnew(NULL, 0)) == NULL)
			return (0);
	}
	else
	{
		if ((tmp = ft_lstnew(NULL, 0)) == NULL)
			return (0);
		tmp->next = asm_h->list_instruction;
		asm_h->list_instruction = tmp;
	}
	if ((err = get_instructions(asm_h, line)))
		return (err);
	return (0);
}
