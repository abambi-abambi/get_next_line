/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:37:49 by abambi            #+#    #+#             */
/*   Updated: 2021/01/07 16:10:52 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	checkerrors_givememory(int fd, char **line, char **buf, char **tail)
{
	if (!line || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		*line = 0x0;
		return (-1);
	}
	if (!(*buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
	{
		return (-1);
	}
	if (*tail == 0x0)
	{
		if (!(*tail = malloc(1 * sizeof(char))))
		{
			free(*buf);
			return (-1);
		}
		**tail = '\0';
	}
	return (0);
}

int			get_next_line(int fd, char **line)
{
	char		*buf;
	char		*check;
	static char	*tail[MAX_FD];
	int			l;

	if (checkerrors_givememory(fd, line, &buf, &tail[fd]) == -1)
		return (-1);
	while (1)
	{
		if ((check = ft_strchr_putzero(tail[fd], '\n')) && tail[fd])
		{
			*line = ft_strdup_f(&tail[fd], 0x0, 0);
			check++;
			tail[fd] = ft_strdup_f(&check, &tail[fd], 2);
			return (!line || !tail[fd]) ? rm(&tail[fd], &buf, 3) :
			rm(0x0, &buf, 2);
		}
		if ((l = read(fd, buf, BUFFER_SIZE)) > 0 && tail[fd])
			tail[fd] = ft_strjoinf_putzero(&tail[fd], buf, l);
		else
		{
			*line = ft_strdup_f(&tail[fd], &buf, 3);
			return (!line || l < 0) ? rm(&tail[fd], &buf, 3) : rm(&buf, 0x0, 1);
		}
	}
}
