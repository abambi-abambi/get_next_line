/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:41:35 by abambi            #+#    #+#             */
/*   Updated: 2021/01/06 23:25:49 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define MAX_FD 256

char	*ft_strchr_putzero(char *string, int symbol);
char	*ft_strdup_f(char **s, char **x, int i);
char	*ft_strjoinf_putzero(char **s1, char *s2, int len);
int		rm(char **s, char **x, int i);
int		get_next_line(int fd, char **line);

#endif
