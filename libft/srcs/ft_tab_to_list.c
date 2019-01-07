/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <mmervoye@student.42.fd>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 11:44:05 by mmervoye          #+#    #+#             */
/*   Updated: 2018/06/22 18:54:18 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_tab_to_list(char **tab)
{
	t_list		*lst;
	t_list		*tmp;
	int			i;
	int			j;

	i = -1;
	j = -1;
	lst = ft_lstnew(0, 0);
	while (tab[++i])
	{
		tmp = ft_lstnew(NULL, 0);
		tmp->content = ft_strdup(tab[i]);
		ft_lstadd(&lst, tmp);
	}
	return (lst);
}
