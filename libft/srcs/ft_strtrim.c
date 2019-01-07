/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:07:34 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/28 17:08:54 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char *s)
{
	size_t	i;
	size_t	spaces;
	size_t	len;

	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == 127)
		i++;
	spaces = i;
	if (s[i])
	{
		i = len - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == 127)
		{
			i--;
			spaces++;
		}
	}
	return (len - spaces);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_len((char *)s);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (!str)
		return ((char *)malloc_error());
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == 127)
		i++;
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
