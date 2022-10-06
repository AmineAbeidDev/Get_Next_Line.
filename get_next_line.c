/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabeid <aabeid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:22:09 by aabeid            #+#    #+#             */
/*   Updated: 2021/12/02 14:52:14 by aabeid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strnlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*after_nl(char *line)
{
	if (ft_strchr(line, '\n'))
		return (ft_strdup(line + ft_strnlen(line) + 1));
	else if (ft_strchr(line, '\0'))
		return (ft_strdup(line + ft_strlen(line)));
	return (NULL);
}

char	*printer(char *save)
{
	char	*ret;

	if (save == NULL)
		return (0);
	if (ft_strchr(save, '\n'))
	{
		ret = ft_substr(save, 0, ft_strnlen(save) + 1);
		free(save);
		return (ret);
	}
	return (save);
}

char	*liner(int fd, char	*save)
{
	int			ret;
	char		*buf;

	ret = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (0);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (0);
		}
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
		if (ft_strchr(buf, '\0') && ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	buf = NULL;
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = liner(fd, save);
	if (ft_strlen(save) == 0)
	{
		free(save);
		save = NULL;
		return (0);
	}
	line = printer(save);
	save = after_nl(save);
	return (line);
}
