/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:56:06 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/07 21:15:03 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)s = 0;
		s++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	total_size;

	total_size = count * size;
	if (count == 0 || size == 0)
		return (ft_calloc(1, 1));
	if ((count >= 2147483647 || size >= 2147483647))
		return (NULL);
	ret = (void *)malloc(total_size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, total_size);
	return ((void *)(ret));
}

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*ret;

	ret = (unsigned char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (ret[i] != '\0' && ret[i] != (char)c)
	{
		i++;
	}
	if (ret[i] == (char)c)
	{
		i++;
		return ((char *)(ret + i));
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	string_size;
	int		i;
	int		j;

	j = 0;
	i = 0;
	string_size = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * (string_size + 1));
	if (ret == NULL)
		return (NULL);
	while (s1[j] != '\0')
	{
		ret[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		ret[i++] = s2[j++];
	}
	ret[i] = '\0';
	return (ret);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}
