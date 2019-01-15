/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:57 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/15 17:05:49 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				asm_usage(void)
{
	ft_putendl_fd("asm: usage: ./asm [file].s", 2);
	return (-1);
}

void			del_params(t_params *params)
{
	t_params		*tmp;

	while (params)
	{
		tmp = params;
		ft_strdel(&params->content);
		params = params->next;
		ft_memdel((void **)&tmp);
	}
}

void			free_asm(t_asm *asm_h)
{
	t_list		*lst;
	t_list		*tmp;

	lst = asm_h->label_list;
	while (lst)
	{
		tmp = lst;
		ft_strdel(&(((t_label *)lst->content)->name));
		free(lst->content);
		lst = lst->next;
		free(tmp);
	}
	lst = asm_h->list_instruction;
	while (lst)
	{
		tmp = lst;
		ft_strdel(&(((t_instruction *)lst->content)->name));
		del_params(((t_instruction *)lst->content)->params);
		lst = lst->next;
		free(tmp);
	}
}

int				main(int argc, char **argv)
{
	t_asm			asm_h;
	int				err_check;

	asm_h.label_list = NULL;
	if (argc != 2)
		return (asm_usage());
	if ((err_check = check_file(argv[1], &asm_h)) < 0)
		return (asm_error(err_check));
	if ((err_check = init_op_tab(&asm_h)) < 0)
		return (asm_error(err_check));
	if ((err_check = parse(&asm_h)) < 0)
		return (asm_error(err_check));
	if ((err_check = writing(&asm_h)) < 0)
		return (asm_error(err_check));
//	free_asm(&asm_h); //TODO
	ft_putstr("Writing output program to ");
	ft_putendl(asm_h.output_name);
	ft_strdel(&(asm_h.output_name));
	return (0);
}
