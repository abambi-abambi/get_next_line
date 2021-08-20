/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abambi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:35:57 by abambi            #+#    #+#             */
/*   Updated: 2021/01/06 23:24:14 by abambi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr_putzero(char *string, int symbol)
{
	while (*string)
	{
		if (*string == (unsigned char)symbol)
		{
			*string = '\0';
			return ((char *)string);
		}
		string++;
	}
	if (*string == (unsigned char)symbol)
	{
		*string = '\0';
		return ((char *)string);
	}
	return (NULL);
}

char	*ft_strjoinf_putzero(char **s1, char *s2, int len)
{
	int		len_s1;
	int		len_s2;
	char	*ptr;
	char	*s1_copy;

	if (!*s1 || !s2)
		return (NULL);
	s1_copy = *s1;
	len_s1 = 0;
	len_s2 = 0;
	*(s2 + len) = '\0';
	while (s1_copy[len_s1])
		len_s1++;
	while (s2[len_s2])
		len_s2++;
	if (!(ptr = malloc((len_s1 + len_s2 + 1) * sizeof(char))))
		rm(s1, 0x0, 1);
	if (ptr == NULL)
		return (NULL);
	while (*s1_copy)
		*ptr++ = *s1_copy++;
	while (*s2 != '\0')
		*ptr++ = *s2++;
	*ptr = '\0';
	return (ptr - len_s1 - len_s2 - rm(s1, 0x0, 1));
}

char	*ft_strdup_f(char **s, char **x, int num)
{
	int		len;
	int		i;
	char	*ptr;
	char	*s_copy;

	len = 0;
	i = 0;
	s_copy = *s;
	if (*s)
		while (s_copy[len])
			len++;
	if (!(ptr = malloc((len + 1) * sizeof(char))) || !*s)
	{
		rm(s, x, num);
		return (NULL);
	}
	while (len--)
	{
		ptr[i] = s_copy[i];
		i++;
	}
	ptr[i] = '\0';
	rm(s, x, num);
	return (ptr);
}

int		rm(char **s, char **x, int i)
{
	if (i == 0)
		return (42);
	else if (i == 1)
	{
		free(*s);
		*s = 0x0;
		return (0);
	}
	else if (i == 2)
	{
		free(*x);
		*x = 0x0;
		return (1);
	}
	else if (i == 3)
	{
		free(*s);
		*s = 0x0;
		free(*x);
		*x = 0x0;
		return (-1);
	}
	else
		return (-42);
}
