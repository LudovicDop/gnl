/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:40:38 by ldoppler          #+#    #+#             */
/*   Updated: 2023/10/31 17:29:37 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char		*next;
	int		read_val;
	int		add_list_val;
	
	add_list_val = 0;
	read_val = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next, 0) > 0)
		return (NULL);
	next = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (read_val && add_list_val != 1)
	{
		read_val = read(fd, next, BUFFER_SIZE);
		add_list_val = add_list(&lst, next);
	}
	while (lst)
	{
		printf("%s",(char *)lst->content);
		lst = lst->next;
	}
	return(NULL);
}
