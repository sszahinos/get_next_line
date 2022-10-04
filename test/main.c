/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:36:03 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/04 12:24:07 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>


int	main(void)
{
	openat(3, "./texts_folder/lines_around_10.txt", O_RDONLY);
	printf(">%s<", get_next_line(3));
	close(3);
	return (0);
}
