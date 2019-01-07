/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmervoye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:00:58 by mmervoye          #+#    #+#             */
/*   Updated: 2018/08/28 17:02:33 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*malloc_error(void)
{
	ft_putendl_fd("21sh: malloc error: going to exit...", 2);
	exit(EXIT_FAILURE);
	return (NULL);
}
