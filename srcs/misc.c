/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 11:29:46 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/15 12:17:35 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*asm_strnext(char *str)
{
	while (*str && ft_isspace(*str))
		str++;
	return (str);
}

int				init_op_tab(t_asm *asm_h)
{
	asm_h->op[0] = (t_op){"live", 1, {T_DIR}, 1, 0, 4};
	asm_h->op[1] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG}, 2, 1, 4};
	asm_h->op[2] = (t_op){"st", 2, {T_REG, T_IND | T_REG}, 3, 1, 2};
	asm_h->op[3] = (t_op){"add", 3, {T_REG, T_REG, T_REG}, 4, 1, 4};
	asm_h->op[4] = (t_op){"sub", 3, {T_REG, T_REG, T_REG}, 5, 1, 4};
	asm_h->op[5] = (t_op){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 1, 4};
	asm_h->op[6] = (t_op){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 1, 4};
	asm_h->op[7] = (t_op){"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 1, 4};
	asm_h->op[8] = (t_op){"zjmp", 1, {T_DIR}, 9, 0, 2};
	asm_h->op[9] = (t_op){"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 1, 2};
	asm_h->op[10] = (t_op){"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 1, 2};
	asm_h->op[11] = (t_op){"fork", 1, {T_DIR}, 12, 0, 2};
	asm_h->op[12] = (t_op){"lld", 2, {T_DIR | T_IND, T_REG}, 13, 1, 4};
	asm_h->op[13] = (t_op){"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 1, 2};
	asm_h->op[14] = (t_op){"lfork", 1, {T_DIR}, 15, 0, 2};
	asm_h->op[15] = (t_op){"aff", 1, {T_REG}, 16, 1, 2};
	asm_h->op[16] = (t_op){0, 0, {0}, 0, 0, 0};
	return (0);
}

t_params		*reverse_params(t_params *lst)
{
	t_params *a;
	t_params *b;
	t_params *c;

	a = NULL;
	b = lst;
	c = (lst)->next;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);

}

t_list			*reverse_list(t_list *lst)
{
	t_list *a;
	t_list *b;
	t_list *c;

	a = NULL;
	b = lst;
	c = (lst)->next;
	while (b)
	{
		c = b->next;
		b->next = a;
		a = b;
		b = c;
	}
	return (a);
}

char				*asm_get_lastspace(char *str)
{
	char		*ptr1;
	char		*ptr2;
	char		*ret;

	ret = NULL;
	ptr1 = NULL;
	ptr2 = NULL;
	ptr1 = ft_strchr(str, ' ');
	ptr2 = ft_strchr(str, '\t');
	if (!ptr1 && !ptr2)
		return (NULL);
	else if (!ptr2)
		ret = ptr1;
	else if (!ptr1)
		ret = ptr2;
	else if (ptr2 < ptr1)
		ret = ptr2;
	else
		ret = ptr1;
	if (ret)
		*ret = 0;
	return (ret);
}
