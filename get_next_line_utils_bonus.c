/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:42:44 by aabeid            #+#    #+#             */
/*   Updated: 2021/12/02 14:51:46 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(char *str, int c)
{
	while ((char)*str != (char)c && *str != '\0')
		str++;
	if ((char)*str == (char)c)
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	p = (char *) malloc(sizeof(char) * (len + 1));
	if (p == NULL)
		return (0);
	while (src[i] != '\0')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	l;

	i = 0;
	if (s == NULL)
		return (NULL);
	l = ft_strlen(s);
	if (l > len)
		l = len;
	p = malloc(l + 1);
	if (p == NULL)
		return (NULL);
	while (i < l)
	{
		p[i] = s[(size_t)start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;

	if (!s1)
		s1 = malloc(1);
	i = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(s1_len + s2_len + 1);
	if (str == NULL)
		return (NULL);
	while (++i < s1_len)
		str[i] = s1[i];
	s1_len = 0;
	while (s1_len < s2_len)
	{
		str[i] = s2[s1_len];
		i++;
		s1_len++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

//will contain the functions that are needed for your get_next_line to work.