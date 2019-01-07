/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:50:54 by mmervoye          #+#    #+#             */
/*   Updated: 2017/11/13 19:00:02 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t		i;

	if (!*n)
		return ((char *)h);
	i = ft_strlen(n);
	while (*h && len-- >= i)
	{
		if (*h == *n && !ft_memcmp(h, n, i))
			return ((char *)h);
		h++;
	}
	return (NULL);
}
