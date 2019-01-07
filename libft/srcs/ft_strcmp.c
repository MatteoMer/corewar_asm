/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:43:26 by mmervoye          #+#    #+#             */
/*   Updated: 2018/05/17 14:39:30 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (-1);
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_strncmp(s1, s2, ft_strlen(s1)));
	return (ft_strncmp(s1, s2, ft_strlen(s2)));
}
