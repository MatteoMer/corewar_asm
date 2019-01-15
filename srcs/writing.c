/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:28:56 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/15 13:55:35 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int					write_magic(t_asm *asm_h)
{
	int			to_write[4];
	int			i;

	i = -1;
	while (++i < 4)
	{
		to_write[i] = (unsigned char)asm_h->magic;
		asm_h->magic >>= 8;
	}
	while (--i >= 0)
		write(asm_h->fd, &to_write[i], 1);
	return (0);
}

int					write_zero(int fd, int size)
{
	int			i;
	char		c;

	i = -1;
	c = 0;
	while (++i < size)
		write(fd, &c, 1);
	return (0);
}

int					write_uint(int fd, int size, int nb)
{
	char			ret[5];
	unsigned int	len;

	len = nb;
	ft_bzero(ret, 5);
	while (len)
	{
		ret[len - 1] = size % 256;
		size /= 256;
		len--;
	}
	while (len < 4)
	{
		write(fd, &(ret[len]), 1);
		len++;
	}
	return (0);
}

int					writing(t_asm *asm_h)
{
	asm_h->fd = open(asm_h->output_name, O_CREAT | O_TRUNC \
		| O_WRONLY, S_IRUSR | S_IWUSR);
	if (asm_h->fd < 0)
		return (-14);
	write_magic(asm_h);
	write(asm_h->fd, asm_h->prog_name, PROG_NAME_LENGTH);
	write_zero(asm_h->fd, 4);
	write_uint(asm_h->fd, asm_h->addr, 4);
	write(asm_h->fd, asm_h->comment, COMMENT_LENGTH);
	write_zero(asm_h->fd, 4);
	write_instructions(asm_h);
	return (0);
}
