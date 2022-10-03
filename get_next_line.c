/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:00:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/03 14:14:56 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

/*
 * Cut a line from start to end. Frees the entire line
 * and returns the new line.
 */
static void	*ft_cut_line(char *line, int start, int end)
{
	char	*new_line;

	new_line = malloc(sizeof(char) * (end - start + 1));
	if (!new_line)
		return (NULL);
	while (start <= end)
	{
		new_line[start] = line[start];
		start++;
	}
	new_line[start] = '\0';
	free(line);
	return (new_line);
}

static void	ft_find_line(t_line_info tli, int fd)
{
	int	aux;

	while (tli->*line[fd])
	{
		tli->index[fd] = ft_find_nl(tli);
		if (tli->index[fd] > 0)
			return (ft_cut_line(tli->*line[fd], tli->index[fd]));
		else
		{
			aux = read(fd, tli->*line[fd], BUFFER_SIZE); 
			if (aux == 0)
				break ;
		}
	}
	return (NULL);
}

/*
 * controlar ccaracteres imprimibles?
 * */
char	*get_next_line(int fd)
{
	static t_line_info	*tli;
	int BUFFER_SIZE = 42;//BORRAR
	
	if (fd < 0 || fd >= 256)//controlar memoria line[]?
		return (NULL);
	if (!tli->*line[fd])//si no hay nada asignado
	{
		tli->*line[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tli->*line[fd])
			return (NULL);
		if (read(fd, tli->*line[fd], BUFFER_SIZE) == 0)
		{
			free(tli->*line[fd]);
			return (NULL);
		}
	}
	str = ft_find_line(tli, fd);
	if (!str)
		free(tli->line[fd]);
	return (str);
}
