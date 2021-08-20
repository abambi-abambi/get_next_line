/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:37:49 by abambi            #+#    #+#             */
/*   Updated: 2021/01/04 16:36:05 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	checkerrors_givememory(int fd, char **line, char **buf, char **tail)
{
	if (!line || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (-1);
	if (!(*buf = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		return (-1);
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
	static char	*tail;
	int			len;

	if (checkerrors_givememory(fd, line, &buf, &tail) == -1)
		return (-1);
	while (1)
	{
		if ((check = ft_strchr_putzero(tail, '\n')) && tail)
		{
			*line = ft_strdup_f(&tail, 0x0, 0);
			check++;
			tail = ft_strdup_f(&check, &tail, 2);
			return (!line || !tail) ? freex(&tail, &buf, 3) : freex(0, &buf, 2);
		}
		if ((len = read(fd, buf, BUFFER_SIZE)) > 0 && tail)
			tail = ft_strjoinf_putzero(&tail, buf, len);
		else
		{
			*line = ft_strdup_f(&tail, &buf, 3);
			return (!line || len < 0) ? freex(&tail, &buf, 3) :
			freex(&buf, 0x0, 1);
		}
	}
}
