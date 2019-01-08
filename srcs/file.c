/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 10:27:51 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/08 13:57:33 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int						check_file(char *file_name, t_asm *asm_h)
{
	int				len;
	char			*tmp;

	len = ft_strlen(file_name);
	tmp = file_name + (len - 2);
	if (ft_strcmp(tmp, ".s"))
		return (-1);
	*tmp = 0;
	if ((asm_h->output_name = ft_strjoin(file_name, ".cor")) == NULL)
		return (malloc_error());
	asm_h->magic = COREWAR_EXEC_MAGIC;
	*tmp = '.';
	if ((asm_h->fd = open(file_name, O_RDONLY)) == -1)
		return (-2);
	if (read(asm_h->fd, NULL, 0) == -1)
		return (-3);
	return (0);
}
