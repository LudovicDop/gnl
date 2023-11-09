/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoppler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:48:33 by ldoppler          #+#    #+#             */
/*   Updated: 2023/11/09 20:18:42 by ldoppler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
	
	fd = open("tests/test1.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("ici : %s", get_next_line(fd));
	printf("ici : %s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
}
