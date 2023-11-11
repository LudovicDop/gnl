/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:40:38 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/11 16:38:51 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*start_read(int fd)
{
	char	*buffer;
	char	*new_line;
	int		read_val;
	char	*tmp;

	read_val = 1;
	new_line = NULL;
	tmp = 0;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (read_val && tmp == 0)
	{
		read_val = read(fd, buffer, BUFFER_SIZE);
		buffer[read_val] = '\0';
		tmp = ft_strchr(buffer, '\n');
		new_line = ft_strjoin(&new_line, &buffer);
		buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	}
	return (free(buffer), buffer = NULL, new_line);
}

char	*save_for_stash(char **buffer2, char **stash)
{
	int		j;
	char	*buffer;

	j = 0;
	buffer = *buffer2;
	buffer = ft_strchr(buffer, '\n');
	if (!(buffer) || ft_strlen(buffer) < 1)
		return (free(*buffer2),*buffer2 = NULL,*stash = NULL, NULL);
	while ((buffer)[j] != '\0')
		j++;
	j++;
	*stash = ft_calloc(sizeof(char), j);
	if (!stash)
		return (free(*buffer2), *buffer2 = NULL, NULL);
	j = 0;
	while ((buffer)[j] != '\0')
	{
		(*stash)[j] = (buffer)[j];
		j++;
	}
	(*stash)[j] = '\0';
	return (NULL);
}

char	*save_for_next(char **buffer, char **stash)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	if (ft_strlen(*buffer) == 0)
		return (NULL);
	while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		i++;
	if ((*buffer)[i] == '\n')
		i = i + 2;
	else
		i++;
	ret = ft_calloc(sizeof(char), i);
	if (!ret)
		return (free(*buffer), *buffer = NULL, NULL);
	while (j < i - 1)
	{
		ret[j] = (*buffer)[j];
		j++;
	}
	ret[j] = '\0';
	save_for_stash(buffer, stash);
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	char		*ret;
	static char	*stash;

	ret = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	tmp = start_read(fd);
	if (stash)
		tmp = ft_strjoin(&stash, &tmp);
	ret = save_for_next(&tmp, &stash);
	free(tmp);
	tmp = NULL;
	return (ret);
}
