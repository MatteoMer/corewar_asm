/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:57 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/18 20:49:42 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				asm_usage(void)
{
	ft_putendl_fd("asm: usage: ./asm [file].s", 2);
	return (-1);
}

void			free_asm_p2(t_asm *asm_h)
{
	t_params	*params;
	t_params	*next_param;
	t_list		*next;

	while (asm_h->list_instruction)
	{
		if (asm_h->list_instruction->content)
		{
			ft_strdel(&((t_instruction *)asm_h->\
						list_instruction->content)->name);
			params = ((t_instruction *)asm_h->\
					list_instruction->content)->params;
			while (params)
			{
				ft_strdel(&params->content);
				next_param = params->next;
				ft_memdel((void **)&(params));
				params = next_param;
			}
		}
		ft_memdel(&(asm_h->list_instruction->content));
		next = asm_h->list_instruction->next;
		ft_memdel((void **)&(asm_h->list_instruction));
		asm_h->list_instruction = next;
	}
}

void			free_asm(t_asm *asm_h)
{
	t_list		*next;

	while (asm_h->label_list)
	{
		ft_strdel(&((t_label *)asm_h->label_list->content)->name);
		ft_memdel(&(asm_h->label_list->content));
		next = asm_h->label_list->next;
		ft_memdel((void **)&(asm_h->label_list));
		asm_h->label_list = next;
	}
	free_asm_p2(asm_h);
	ft_strdel(&asm_h->output_name);
}

int				main(int argc, char **argv)
{
	t_asm			asm_h;
	int				err_check;

	asm_h.label_list = NULL;
	if (argc != 2)
		return (asm_usage());
	if ((err_check = check_file(argv[1], &asm_h)) < 0)
		return (asm_error(&asm_h, err_check));
	if ((err_check = init_op_tab(&asm_h)) < 0)
		return (asm_error(&asm_h, err_check));
	if ((err_check = parse(&asm_h)) < 0)
		return (asm_error(&asm_h, err_check));
	if ((err_check = writing(&asm_h)) < 0)
		return (asm_error(&asm_h, err_check));
	ft_putstr("Writing output program to ");
	ft_putendl(asm_h.output_name);
	free_asm(&asm_h);
	return (0);
}
