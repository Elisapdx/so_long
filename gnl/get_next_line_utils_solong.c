/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_solong.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 12:31:38 by elisa             #+#    #+#             */
/*   Updated: 2023/01/15 17:55:27 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_solong.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[sizetotal] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	char	*chr;

	chr = (char *)s;
	while (*chr != c)
	{
		if (!*chr)
			return (NULL);
		chr++;
	}
	return (chr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dst;
	size_t			i;

	dst = s;
	i = 0;
	while (i++ < n)
		*dst++ = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0)
		if (SIZE_MAX / count <= size)
			return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	e;

	e = 0 ;
	while (s[e] != '\0')
		e++;
	return (e);
}
