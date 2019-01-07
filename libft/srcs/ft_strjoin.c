/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:03:11 by mmervoye          #+#    #+#             */
/*   Updated: 2017/11/09 14:07:24 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s, char const *s2)
{
	char		*str;

	str = ft_strnew(ft_strlen(s) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ft_strcat(str, s);
	ft_strcat(str, s2);
	return (str);
}
