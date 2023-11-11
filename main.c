/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:48:33 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/10 19:30:56 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
	
	fd = open("tests/test1.txt", O_RDONLY);
	char *test = get_next_line(fd);
	while (test)
	{
		printf("ARrr %s",test);
		test = get_next_line(fd);
	}
//	printf("=> %s",get_next_line(fd));
//	printf("=> %s",get_next_line(fd));
//	printf("=> %s",get_next_line(fd));
//	printf("=> %s",get_next_line(fd));
}
