/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:07:53 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/18 16:59:15 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					write_ocp(t_asm *asm_h, t_params *params, t_instruction *instr)
{
	int				ocp;
	t_params		*ptr;

	ocp = 0;
	ptr = params;
	(ptr->type == T_REG) ? ocp |= 0b01000000 : 0;
	(ptr->type == T_DIR) ? ocp |= 0b10000000 : 0;
	(ptr->type == T_IND) ? ocp |= 0b11000000 : 0;
	ptr = ptr->next;
	if (ptr && instr->op->nb_params >= 1)
	{
		(ptr->type == T_REG) ? ocp |= 0b00010000 : 0;
		(ptr->type == T_DIR) ? ocp |= 0b00100000 : 0;
		(ptr->type == T_IND) ? ocp |= 0b00110000 : 0;
		ptr = ptr->next;
		if (ptr && instr->op->nb_params >= 2)
		{
			(ptr->type == T_REG) ? ocp |= 0b00000100 : 0;
			(ptr->type == T_DIR) ? ocp |= 0b00001000 : 0;
			(ptr->type == T_IND) ? ocp |= 0b00001100 : 0;
		}
	}
	write(asm_h->fd, &ocp, 1);
	return (0);
}

int					write_param(t_asm *asm_h, t_params *param)
{
	char				buf[4];
	unsigned int		tmp;
	int					i;
	char				*content;

	i = 0;
	ft_bzero(&buf, 4);
	content = (param->type != T_IND) ? param->content + 1 : param->content;
	tmp = ft_atoi(content);
	if (param->type == T_REG)
	{
		if (tmp > REG_NUMBER)
			return (-16);
		write(asm_h->fd, &tmp, 1);
		return (0);
	}
	while (tmp)
	{
		buf[param->size - i - 1] = tmp % 256;
		i++;
		tmp /= 256;
	}
	write(asm_h->fd, &buf, param->size);
	return (0);
}

int					write_label(t_asm *asm_h, t_params *param)
{
	int							i;
	unsigned int				tmp;

	i = 0;
	tmp = 0;
	tmp = rev_endian16(param->label_addr);
	write(asm_h->fd, &tmp, param->size);
	return (0);
}

int					process_instruction(t_asm *asm_h, t_instruction *instr)
{
	int				i;
	int				err;
	t_params		*params;
	t_params		*ptr;

	i = -1;
	params = reverse_params(instr->params);
	ptr = params;
	write(asm_h->fd, &(instr->op->op_code), 1);
	if (instr->op->to_encode == 1)
		write_ocp(asm_h, ptr, instr);
	while (++i < instr->op->nb_params)
	{
		if (params->is_label)
			err = write_label(asm_h, params);
		else
			err = write_param(asm_h, params);
		if (err < 0)
			return (err);
		params = params->next;
	}
	instr->params = ptr;
	return (0);
}

int					write_instructions(t_asm *asm_h)
{
	int					err;
	t_list				*lst;
	t_list				*ptr;

	lst = asm_h->list_instruction;
	lst = reverse_list(lst);
	ptr = lst;
	while (lst)
	{
		if ((err = process_instruction(asm_h, lst->content)) < 0)
			return (err);
		lst = lst->next;
	}
	asm_h->list_instruction = ptr;
	return (0);
}
