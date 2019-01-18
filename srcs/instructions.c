/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:50:55 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/18 15:06:20 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						check_type_args(t_asm *asm_h, char **param_tab, t_instruction *new)
{
	int				i;
	int				*arg_type;
	char			*tmp;

	arg_type = new->op->type_param;
	i = -1;
	while (++i < new->op->nb_params)
	{
		tmp = asm_strnext(param_tab[i]);
		if ((arg_type[i] & get_type_param(tmp)) == 0)
		{
			ft_deltab(&param_tab);
			return (-15);
		}
	}
	return (0);
}

t_params				*create_param(char *type)
{
	t_params			*new;

	new = NULL;
	if ((new = (t_params *)malloc(sizeof(t_params))) == NULL)
		return (NULL);
	new->type = get_type_param(type);
	new->content = ft_strtrim(type);
	if (!new->content)
		return (NULL);
	return (new);
}

int						get_params(t_asm *asm_h, char *line, \
		t_instruction *new, int i)
{
	t_params		*tmp;
	char			**param_tab;

	new->params = NULL;
	if (ft_count_word(line, SEPARATOR_CHAR) != new->op->nb_params)
		return (-10);
	if ((param_tab = ft_strsplit(line, SEPARATOR_CHAR)) == NULL)
		return (malloc_error());
	if ((i = check_type_args(asm_h, param_tab, new)) < 0)
		return (i);
	i = -1;
	while (++i < new->op->nb_params)
	{
		if ((tmp = create_param(param_tab[i])) == NULL)
			return (malloc_error());
		if (*(tmp->content) == 0)
			return (free_and_ret_err(tmp->content, tmp, param_tab, 8));
		check_label_and_size(new, &tmp);
		tmp->next = new->params;
		new->params = tmp;
		asm_h->addr += tmp->size;
	}
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
	if ((ptr = asm_get_lastspace(*line)) == NULL)
		return (-12);
	if ((new->name = ft_strdup(*line)) == NULL)
		return (malloc_error());
	if (op_exist(new->name, asm_h, new) < 0)
		return (-8);
	new->addr = asm_h->addr;
	asm_h->addr += new->op->to_encode == 0 ? 1 : 2;
	*ptr = ' ';
	ptr++;
	if ((err = get_params(asm_h, ptr, new, -1)) < 0)
		return (free_and_ret_err(new->name, new, NULL, err));
	asm_h->list_instruction->content = new;
	*line += ft_strlen(*line);
	return (0);
}

int						new_instruction(t_asm *asm_h, char **line)
{
	t_list				*tmp;
	int					err;

	tmp = NULL;
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
