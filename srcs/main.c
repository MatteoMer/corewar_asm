/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:59:57 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/14 13:23:50 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				asm_usage(void)
{
	ft_putendl_fd("asm: usage: ./asm [file].s", 2);
	return (-1);
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
	ft_putstr("Writing output program to ");
	ft_putendl(asm_h.output_name);
	return (0);
}
