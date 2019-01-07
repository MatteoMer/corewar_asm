/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matteo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 15:24:44 by matteo            #+#    #+#             */
/*   Updated: 2018/06/22 18:54:18 by mmervoye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			gnl_reader(const int fd, char **tab)
{
	char			*buff;
	char			*tmp;
	int				ret;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	ret = 1;
	while (!ft_strchr(tab[fd], '\n') && ((ret = read(fd, buff, BUFF_SIZE)) > 0))
	{
		buff[ret] = '\0';
		tmp = tab[fd];
		if (!(tab[fd] = ft_strjoin(tmp, buff)))
			return (-1);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static char		*tab[OPEN_MAX];
	char			*tmp;
	int				ret;

	if ((fd < 0) || (fd > OPEN_MAX) || (line == NULL))
		return (-1);
	if (tab[fd] == NULL && !(tab[fd] = ft_strnew(0)))
		return (-1);
	if ((ret = gnl_reader(fd, tab)) == -1)
		return (-1);
	if (ret == 0)
	{
		if (!(*line = ft_strdup(tab[fd])))
			return (-1);
		ft_strdel(&tab[fd]);
		return (!!ft_strlen(*line));
	}
	if (!(*line = ft_strsub(tab[fd], 0, ft_strchr(tab[fd], '\n') - tab[fd])))
		return (-1);
	tmp = tab[fd];
	if (!(tab[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1)))
		return (-1);
	ft_strdel(&tmp);
	return (1);
}
