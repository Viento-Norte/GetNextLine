/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdecorte <jdecorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 11:14:11 by jdecorte          #+#    #+#             */
/*   Updated: 2021/10/19 11:32:26 by jdecorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = -1;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

void	*ft_calloc(size_t byte)
{
	char	*res;

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
