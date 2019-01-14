/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:07:53 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/14 17:32:30 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					write_ocp(t_asm *asm_h, t_instruction *instr)
{
	int				ocp;
	int				i;
	t_params		*ptr;

	ocp = 0;
	ptr = instr->params;
	(ptr->type == T_REG) ? ocp |= 0b01000000 : 0;
	(ptr->type == T_DIR) ? ocp |= 0b10000000 : 0;
	(ptr->type == T_IND) ? ocp |= 0b11000000 : 0;
	ptr = ptr->next;
	(ptr->type == T_REG) ? ocp |= 0b00010000 : 0;
	(ptr->type == T_DIR) ? ocp |= 0b00100000 : 0;
	(ptr->type == T_IND) ? ocp |= 0b00110000 : 0;
	ptr = ptr->next;
	(ptr->type == T_REG) ? ocp |= 0b00000100 : 0;
	(ptr->type == T_DIR) ? ocp |= 0b00001000 : 0;
	(ptr->type == T_IND) ? ocp |= 0b00001100 : 0;
	write(asm_h->fd, &ocp, 1);
	return (0);
}

int					write_param(t_asm *asm_h, t_params *param)
{
	char		buf[4];
	int			tmp;
	int			len;
	int			i;

	i = 0;
	ft_bzero(&buf, 4);
	if (param->type != T_IND)
		param->content++;
	tmp = ft_atoi(param->content);
	if (param->type == T_REG)
	{
		if (tmp > REG_NUMBER || tmp < 0)
			return (-1); //do err
		write(asm_h->fd, &tmp, 1);
		return (0);
	}
	while (tmp)
	{
		buf[param->size - i - 1] = tmp % 10;
		i++;
		tmp /= 10;
	}
	write(asm_h->fd, &buf, param->size);
	return (0);
}

uint16_t	rev_endian16(uint16_t i)
{
	return ((i >> 8) | (i << 8));
}

int					write_label(t_asm *asm_h, t_params *param)
{
	int				i;
	int				tmp;

	i = 0;
	tmp = rev_endian16(param->label_addr);
	write(asm_h->fd, &tmp, param->size);
	return (0);
}

int					process_instruction(t_asm *asm_h, t_instruction *instr)
{
	int				i;
	t_params		*params;

	i = -1;
	instr->params = reverse_params(instr->params);
	params = instr->params;
	write(asm_h->fd, &(instr->op->op_code), 1);
	if (instr->op->to_encode == 1)
		write_ocp(asm_h, instr);
	while (++i < instr->op->nb_params)
	{
		if (params->is_label)
			write_label(asm_h, params);
		else
			write_param(asm_h, params);
		params = params->next;
	}
	return (0);
}

int					write_instructions(t_asm *asm_h)
{
	int			err;
	t_list		*lst;

	lst = asm_h->list_instruction;
	lst = reverse_list(lst);
	while (lst)
	{
		if ((err = process_instruction(asm_h, lst->content)) < 0)
			return (err);
		lst = lst->next;
	}
	return (0);
}
