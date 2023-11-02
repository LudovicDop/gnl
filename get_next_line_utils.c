/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:56:06 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/02 07:10:36 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buffer;
	t_list	*next;

	if (!del)
	{	
		return ;
	}
	buffer = *lst;
	next = buffer;
	while (buffer)
	{
		next = buffer->next;
		del(buffer->content);
		del(buffer->tmp);
		free(buffer);
		buffer = next;
	}
	*lst = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_node;
	t_list	*current;

	new_node = new;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

void	save_after_n(t_list **lst, char *content, char *tmp, t_list *str)
{
	if (*content == '\n')
	{
		str->content = tmp;
		printf("C\n");
		ft_lstadd_back(lst, str);
	}
	content++;
	printf("here=%s\n",content);
	if (*content)
	{
		// Objectif reussir a changer le content avec seulement le contenu apres \n
	}
}

int	add_list(t_list **lst, char *content)
{
	int	i;
	char	*tmp;
	t_list	*str;
	
	i = 0;
	str = malloc(sizeof(t_list));
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if(str == NULL || tmp == NULL)
		return (0);
	while (*content)
	{
		tmp[i] = *content;
		printf("tmp[%d] = %c\n",i,tmp[i]);
		if (*content == '\n')
		{
			save_after_n(lst, content, tmp, str);
			printf("A\n");	
			return (1);
		}
		content++;
		i++;
	}
	printf("B\n");
	tmp[i] = '\0';
	str->content = tmp;
	ft_lstadd_back(lst, str);
	//free(tmp);
	//free(str);
	return (0);
}	
