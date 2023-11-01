/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:56:06 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/01 15:37:32 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
		ft_lstadd_back(lst, str);
	}
	content++;
	if (*content)
	{
		printf("alpha\n");
		(*lst)->tmp = content;
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
	if(str == NULL)
		return (0);
	while (*content)
	{
		tmp[i] = *content;
		printf("tmp[%d] = %c\n",i,tmp[i]);
		if (*content == '\n')
		{
			save_after_n(lst, content, tmp, str);		
			return (1);
		}
		content++;
		i++;
	}
	tmp[i] = '\0';
	str->content = tmp;
	ft_lstadd_back(lst, str);
	return (0);
}	
