/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legarcia <legarcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 19:24:14 by legarcia          #+#    #+#             */
/*   Updated: 2022/10/25 19:26:15 by legarcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_memory(char **s1)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	i = -1;
	res = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[++i] != 0)
		res[i] = s1[i];
	j = -1;
	while (s2[++j] != 0)
		res[i + j] = s2[j];
	res[i + j] = 0;
	return (res);
}

char	*ft_strchr(const char *str, int searchar)
{
	char	*strout;

	strout = (char *)str;
	while (*strout != searchar && *strout != 0)
		strout++;
	if (*strout == searchar)
		return (strout);
	else
		return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	byte;

	byte = count * size;
	res = malloc(byte);
	if (!res)
		return (NULL);
	while (byte > 0)
		res[--byte] = '\0';
	res[byte] = '\0';
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
