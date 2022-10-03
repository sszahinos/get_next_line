/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:01:27 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/03 15:32:15 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
/*
# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 1
# endif
*/

#include <limits.h>

typedef struct line_info
{
	char	*line;
	int		index;
}	t_line_info;

char	*get_next_line(int fd);

/*UTILS*/
int		ft_find_char(char *str, char c);

#endif
