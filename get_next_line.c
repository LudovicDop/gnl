/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:40:38 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/03 11:51:16 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void del(void *test)
{
	free(test);
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

char	*join(t_list **lst)
{
	int	i;
	int 	j;
	int	k;
	char	*ret;
	char 	*first;
	i = 0;
	j = 0;
	first = (char *)(*lst);
	while (*lst)
	{
		i = ft_strlen((char *)(*lst)->content) + i;
		(*lst) = (*lst)->next;
	}
	*lst = (t_list *)first;
	ret = malloc(sizeof(char) * i);
	//printf("%d\n",i);
	if (i == 0)
	{
		return (NULL);
	}
	while (*lst)
	{	
		k = 0;
		while (k < i)
		{
			//printf("ret[%d] = %c\n",i, ((char *)(*lst)->content)[k]);
			ret[j] = ((char *)(*lst)->content)[k];
			j++;
			k++;
		}
		*lst = (*lst)->next;
	}
	return (ret);
	
}
char	*get_next_line(int fd)
{
	static t_list	*lst;
	static char		*next;
	int		read_val;
	static int		add_list_val;
	char	*ret;

	read_val = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &next, 0) <= 0)
		return (NULL);
	if (next)
	{
		if (add_list_val == 1)
			add_list_val = add_list(&lst, next);
		while (read_val && add_list_val != 1)
		{
			read_val = read(fd, next, BUFFER_SIZE);
			add_list_val = add_list(&lst, next);
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
	next = lst->tmp;
	}
	ret = join(&lst);
	ft_lstclear(&lst, del);
	//free(next);
	return(ret);
}
