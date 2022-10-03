/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:00:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/03 16:15:16 by sersanch         ###   ########.fr       */
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
	char	*tmp;

	while (1)
	{
		tli.index = ft_find_nl(tli);
		if (tli.index > 0)
			return (ft_cut_line(tli));//devuelve de 0 a indice
		else//no encuentra \n
		{
			aux = read(fd, tmp, BUFFER_SIZE); 
			if (aux <= 0)
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
	static t_line_info	tli[OPEN_MAX];
	int	aux;
	int BUFFER_SIZE = 42;//BORRAR
	
	if (fd < 1 || fd >= OPEN_MAX)//controlar memoria line[]?
		return (NULL);
	if (!tli[fd].line)//si no hay nada asignado
	{
		tli[fd].line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tli[fd].line[fd])
			return (NULL);
		/*aux = read(fd, tli[fd].line, BUFFER_SIZE);
		if (aux == 0)
		{
			free(tli[fd].line);
			return (NULL);
		}*/
	}
//	tli[fd].line[aux] = '\0';
	str = ft_find_line(tli[fd], fd);
	//if (!str)
	//	free(tli.line[fd]);
	return (str);
}
