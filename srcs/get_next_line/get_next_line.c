/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yliao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 12:27:06 by yliao             #+#    #+#             */
/*   Updated: 2022/03/14 19:20:23 by yliao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *stash)
{
	char	*buff;
	int		status;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (0);
	status = 1;
	while (status > 0 && ft_strchr(stash, '\n') == 0)
	{
		status = read(fd, buff, BUFFER_SIZE);
		if (status == -1)
		{
			free(buff);
			return (0);
		}
		buff[status] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

char	*get_line(char *s)
{
	char	*line;
	char	*ptr_n;
	int		size;
	size_t	i;

	if (!s || ft_strlen(s) == 0)
		return (0);
	ptr_n = ft_strchr(s, '\n');
	size = ft_strlen(s);
	if (ptr_n)
		size = ptr_n - s + 1;
	line = malloc(sizeof(char) * (size + 1));
	if (!line)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*remove_line(char *s, size_t size_line)
{
	char	*dst;
	size_t	i;

	if (ft_strlen(s) == size_line)
	{
		free(s);
		return (0);
	}
	dst = malloc(sizeof(char) * (ft_strlen(s) - size_line + 1));
	if (!dst || !s)
		return (0);
	i = 0;
	while (s[size_line])
		dst[i++] = s[size_line++];
	dst[i] = '\0';
	free(s);
	return (dst);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1026)
		return (0);
	stash[fd] = ft_read(fd, stash[fd]);
	line = get_line(stash[fd]);
	stash[fd] = remove_line(stash[fd], ft_strlen(line));
	return (line);
}
