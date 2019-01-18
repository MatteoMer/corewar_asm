/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:19:02 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/18 13:22:50 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						get_label_addr(t_list *labels,\
		t_instruction *instruction, t_params *param)
{
	char			*label;

	label = ft_strchr(param->content, LABEL_CHAR) + 1;
	while (labels)
	{
		if (!ft_strcmp(((t_label *)labels->content)->name, label))
		{
			param->label_addr = ((t_label *)labels->content)->addr \
								- instruction->addr;
			return (0);
		}
		labels = labels->next;
	}
	return (-13);
}

int						parse_labels(t_asm *asm_h)
{
	t_list			*list_instructions;
	t_params		*ptr_param_list;
	int				err;

	list_instructions = asm_h->list_instruction;
	ptr_param_list = NULL;
	while (list_instructions)
	{
		ptr_param_list = ((t_instruction *)list_instructions->content)->params;
		while (ptr_param_list)
		{
			if (ptr_param_list->is_label == 1)
				err = get_label_addr(asm_h->label_list, \
						list_instructions->content, ptr_param_list);
			if (err < 0)
				return (err);
			ptr_param_list = ptr_param_list->next;
		}
		list_instructions = list_instructions->next;
	}
	return (0);
}
