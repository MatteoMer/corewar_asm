/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:32:17 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/14 16:34:47 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_numlen(int nb)
{
	int			len;

	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (nb == 0 ? 1 : len);
}
