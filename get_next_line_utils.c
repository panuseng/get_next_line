/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plaophit <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:23:46 by plaophit          #+#    #+#             */
/*   Updated: 2024/02/19 22:57:07 by plaophit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	char	*str;
	size_t	i;

	i = count * size;
	p = (void *)malloc(count * size);
	if (!p)
		return (NULL);
	str = (char *)p;
	while (i)
	{
		*str = '\0';
		str++;
		i--;
	}
	return (p);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (*s == '\0' || s == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*res;

	i = 0;
	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * len);
	if (!res)
		return (0);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		res[i] = *s2;
		s2++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (char) c)
		str++;
	if (*str == (char) c)
		return ((char *)str);
	return (0);
}

char	*ft_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}
