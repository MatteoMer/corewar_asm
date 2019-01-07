/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:42:23 by mmervoye          #+#    #+#             */
/*   Updated: 2017/11/13 15:03:49 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned long long		i;
	char					*c_dst;
	char					*c_src;

	c_src = (char *)src;
	c_dst = (char *)dst;
	i = 0;
	while (i < (unsigned long long)n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return (dst);
}
