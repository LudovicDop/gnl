/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:40:38 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/08 16:22:08 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buffer)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	ret = buffer;
	k = 0;
	j = 0;
	i = 0;
	if (!buffer || *buffer == '\0')
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
	{
		i++;
		ret = ft_calloc(i + 1, sizeof(char));
		if (!ret)
			return (NULL);
		while (j < i)
			ret[j++] = buffer[k++];
		ret[j] = '\0';
	}
	return (ret);
}

char	*concat_prev(char *stash, char	*ret)
{
	ret = ft_strjoin(ret, stash);
	return (ret);
}

char	*next(char **stash, int fd, char *ret)
{
	int		read_val;
	char	*buffer;

	read_val = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_val && ft_strchr(buffer, '\n') == 0)
	{
		if (ft_strchr(*stash, '\n') == 0)
		{
			read_val = read(fd, buffer, BUFFER_SIZE);
			*stash = ft_strchr(buffer, '\n');
		}
		else
		{
			read_val = 0;
			*stash = ft_strchr(*stash, '\n');
		}
		ret = ft_strjoin(ret, buffer);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	ret = ft_calloc(1, 1);
	if (!ret)
		return (NULL);
	if (stash)
	{
		ret = concat_prev(stash, ret);
	}
	else
	{
		stash = ft_calloc(1, 1);
		if (!stash)
			return (NULL);
	}
	ret = next(&stash, fd, ret);
	ret = get_line(ret);
	return (ret);
}
