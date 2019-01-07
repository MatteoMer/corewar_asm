/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:39:00 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/28 17:08:26 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_parts(const char *s, char c)
{
	int		count;
	int		in_word;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (in_word == 1 && *s == c)
			in_word = 0;
		if (in_word == 0 && *s != c)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int		ft_wlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		index;

	index = 0;
	nb_word = ft_count_parts((const char *)s, c);
	t = (char **)malloc(sizeof(*t) * (ft_count_parts((const char *)s, c) + 1));
	if (!t)
		return ((char **)malloc_error());
	while (nb_word--)
	{
		while (*s == c && *s)
			s++;
		t[index] = ft_strsub((const char *)s, 0, ft_wlen((const char *)s, c));
		if (!t[index])
			return (NULL);
		s = s + ft_wlen(s, c);
		index++;
	}
	t[index] = NULL;
	return (t);
}
