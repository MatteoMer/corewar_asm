/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 10:23:40 by mmervoye          #+#    #+#             */
/*   Updated: 2018/03/28 10:27:31 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinf(char const *s, char const *s2)
{
	char		*str;

	str = ft_strnew(ft_strlen(s) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	ft_strcat(str, s);
	ft_strcat(str, s2);
	ft_strdel((char **)&s);
	return (str);
}
