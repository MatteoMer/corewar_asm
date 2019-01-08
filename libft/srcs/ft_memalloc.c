/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:42:04 by mmervoye          #+#    #+#             */
/*   Updated: 2019/01/08 10:34:43 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char		*str;

	str = (char *)malloc(sizeof(str) * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
