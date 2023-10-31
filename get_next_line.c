/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:40:38 by ldoppler          #+#    #+#             */
/*   Updated: 2023/10/30 17:34:35 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	char		*buffer;
	static int	search_n;
	char		*ret;
	static int	read_value;
	static char	*prev;
	
	read_value = 1;
	ret = ft_calloc(1, 1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (search_n != 0)
	{
		ret = ft_strjoin(prev, buffer);
		search_n = 0;
	}
	while (search_n == 0 && read_value)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		ret = ft_strjoin(ret, buffer);
		search_n = ft_strchr(ret, '\n');
	}
	free(buffer);
	if (search_n != 0)
		prev = ft_substr(ret, search_n + 1, ft_strlen(ret));
	return (ft_substr(ret, 0, search_n + 1));
}
