/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:24:15 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/18 15:06:04 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					asm_error(t_asm *asm_h, int err)
{
	char			*err_tab[17];

	err_tab[0] = "file is not valid. usage: ./asm [file].s";
	err_tab[1] = "No such file";
	err_tab[2] = "the file is a directory";
	err_tab[3] = "there is no name !";
	err_tab[4] = "there is no comment !";
	err_tab[5] = "name too long!";
	err_tab[6] = "comment too long!";
	err_tab[7] = "lexing error";
	err_tab[8] = "operator doesn't exist";
	err_tab[9] = "invalid number of parameters";
	err_tab[10] = "there's no name and/or comment";
	err_tab[11] = "invalid instruction";
	err_tab[12] = "invalid label";
	err_tab[13] = "can't create file";
	err_tab[14] = "invalid parameter type";
	err_tab[15] = "register number invalid";
	err_tab[16] = NULL;
	err *= -1;
	ft_putstr_fd("asm: error: ", 2);
	ft_putendl_fd(err_tab[err - 1], 2);
	free_asm(asm_h);
	return (-1);
}

int					malloc_error(void)
{
	ft_putendl_fd("asm: malloc error. Exiting...", 2);
	exit(EXIT_FAILURE);
	return (-1);
}
