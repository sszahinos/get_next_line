/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:00:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/03 10:35:12 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

/*
 * Cut a line from 0 to index. Frees the entire line
 * and returns the new line.
 */
static void	*ft_cut_line(char *line, int index)
{
	int		i;
	char	*new_line;

	new_line = malloc(sizeof(char) * (index + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i <= index)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

/*
 * controlar ccaracteres imprimibles?
 * */
char	*get_next_line(int fd)
{
	static t_line_info	*lf;
	int BUFFER_SIZE = 42;//BORRAR
	
	if (fd < 0 || fd >= 256)//controlar memoria line[]?
		return (NULL);
	if (!lf->line[fd])
	{
		lf->line[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!line[fd])
			return (NULL);
	}
	if (read(fd, line[fd], BUFFER_SIZE) > 0)
	{//hay texto
		index = ft_find_char((char *)line[fd], '\n');
		if (index > 0) //encuentra \n o EOF
		{
			return (ft_cut_line((char *)line[fd], index));
		}
		else //else no hace falta
		{//No ha encontrado \n ni EOF. aumenta la linea
			//ft_reset_	
		}
	}
	free(line[fd]);
//	free(line);
	return (NULL);
}
