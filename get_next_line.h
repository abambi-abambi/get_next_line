/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:41:35 by abambi            #+#    #+#             */
/*   Updated: 2021/01/04 17:45:20 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*ft_strchr_putzero(char *string, int symbol);
char	*ft_strdup_f(char **s, char **x, int i);
char	*ft_strjoinf_putzero(char **s1, char *s2, int len);
int		freex(char **s, char **x, int i);
int		get_next_line(int fd, char **line);

#endif
