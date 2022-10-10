/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:36:03 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/10 17:51:28 by sersanch         ###   ########.fr       */
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
//	fd = open("./texts_folder/41_no_nl", O_RDONLY);

//	fd2 = open("./texts_folder/lines_around_10.txt", O_RDONLY);
	//read(fd, str, 2);
	//printf("%s\n", str);
	
	str = get_next_line(fd);
	printf("1.1----------- main\t>%s<\n", str);
	free(str);
	printf("next line\n");

//	printf("2----------- main\t>%s<\n", get_next_line(fd2));
//	printf("next line\n");
//
	str = get_next_line(fd);
	printf("1.2----------- main\t>%s<\n", str);
	free(str);
	printf("next line\n");

	str = get_next_line(fd);
	printf("1.3----------- main\t>%s<\n", str);
	free(str);
	printf("next line\n");

//	printf("2----------- main\t>%s<\n", get_next_line(fd2));
//	printf("next line\n");
//
	str = get_next_line(fd);
	printf("1.4----------- main\t>%s<\n", str);
	free(str);

	printf("END");
	close(fd);
//	check_leaks();
	printf("%d\n", getpid());
	/*while (1)
		usleep(10);*/
	return (0);
}
