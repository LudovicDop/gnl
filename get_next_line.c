/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:40:38 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/02 15:33:19 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void del(void *test)
{
	free(test);
}
char	*get_next_line(int fd)
{
	static t_list	*lst;
	static char		*next;
	int		read_val;
	static int		add_list_val;
	
	read_val = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next, 0) < 0)
		return (NULL);
	if (next)
	{
		//printf("AXA %s",next);
		//printf("oui\n");
		add_list_val = add_list(&lst, next);
		while (read_val && add_list_val != 1)
		{
			printf("okkk");
			add_list_val = add_list(&lst, next);
			read_val = read(fd, next, BUFFER_SIZE);
		}
		next = lst->tmp;
	}
	else
	{
	add_list_val = 0;
	next = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (read_val && add_list_val != 1)
	{
		read_val = read(fd, next, BUFFER_SIZE);
		add_list_val = add_list(&lst, next);
	}
	//printf("hereee = %s",(char *)lst->tmp);
	next = lst->tmp;
	//printf("hereXee = %s",next);
	}
	while (lst)
	{
		printf("%s",(char *)lst->content);
		lst = lst->next;
	}
	ft_lstclear(&lst, del);
	//free(next);
	return(NULL);
}
