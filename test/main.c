/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:36:03 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/05 17:39:17 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>


int	main(void)
{
	char *str;
	int fd, fd2;

	fd = open("./texts_folder/test.txt", O_RDONLY);
	fd2 = open("./texts_folder/lines_around_10.txt", O_RDONLY);
	read(fd, str, 2);
	printf("%s\n", str);
	printf("1----------- main\t>%s<\n", get_next_line(fd));
	printf("next line\n");
	printf("2----------- main\t>%s<\n", get_next_line(fd2));
	printf("next line\n");

	printf("1----------- main\t>%s<\n", get_next_line(fd));
	printf("next line\n");
	printf("1----------- main\t>%s<\n", get_next_line(fd));
	printf("next line\n");
	printf("2----------- main\t>%s<\n", get_next_line(fd2));
	printf("next line\n");
	printf("1----------- main\t>%s<\n", get_next_line(fd));

	close(3);
	return (0);
}
