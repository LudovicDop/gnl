/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:48:33 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/10 15:23:42 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
	
	fd = open("tests/multiple_line_no_nl", O_RDONLY);
	char *test = get_next_line(fd);
	while (test)
	{
		printf("%s",test);
		test = get_next_line(fd);
	}
//	get_next_line(fd);
//	get_next_line(fd);
//	get_next_line(fd);
}
