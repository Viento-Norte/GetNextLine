/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legarcia <legarcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:33:49 by legarcia          #+#    #+#             */
/*   Updated: 2022/10/25 19:35:29 by legarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_joinfree(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free_memory(&buffer);
	if (!temp)
		return (NULL);
	return (temp);
}

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free_memory(&buffer));
	line = ft_calloc((ft_strlen(buffer) - i), sizeof(char));
	if (!line)
		return (free_memory(&buffer));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free_memory(&buffer);
	return (line);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(sizeof(char), (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	buffer[BUFFER_SIZE + 1];
	int		b_read;

	if (!res)
	res = ft_calloc(1, 1);
	if (!res)
		return (NULL);
	b_read = 42;
	while (b_read > 0)
	{
		b_read = read(fd, buffer, BUFFER_SIZE);
		if (b_read == -1)
			return (NULL);
		buffer[b_read] = 0;
		res = ft_joinfree(res, buffer);
		if (!res)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;	

	if (BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (buffer[fd])
			free_memory(&buffer[fd]);
		return (NULL);
	}
	if (!buffer[fd] || !ft_strchr(buffer[fd], '\n'))
	{
		buffer[fd] = read_file(fd, buffer[fd]);
		if (!buffer[fd])
			return (NULL);
	}
	line = ft_line(buffer[fd]);
	if (!line)
		return (free_memory(&buffer[fd]));
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
