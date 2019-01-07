/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/01 16:20:27 by matteo            #+#    #+#             */
/*   Updated: 2018/02/01 16:20:35 by matteo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_word(const char *s, char c)
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
