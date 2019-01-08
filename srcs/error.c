/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:24:15 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/08 15:08:03 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					asm_error(int err)
{
	char			*err_tab[] = 
	{
		"file is not valid. usage: ./asm [file].s",
		"No such file",
		"the file is a directory",
		"there is no name !",
		"there is no comment !",
		"name too long!",
		"comment too long!",
		"lexing error",
		""
	};
	err *= -1;
	ft_putstr_fd("asm: error: ", 2);
	ft_putendl_fd(err_tab[err - 1], 2);
	return (-1);
}

int					malloc_error(void)
{
	ft_putendl_fd("asm: malloc error. Exiting...", 2);
	exit(EXIT_FAILURE);
	return (-1);
}