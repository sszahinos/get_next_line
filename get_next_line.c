/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:17:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/04 12:39:47 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
/*
 * ELIMINAR LINEAS SI ALGUN MALLOC FALLA (REVISAR CADA IF() RETURN NULL)
 * */
static char	*ft_cut_line(char * line, int index)//devuelve linea
{
	char	*new_str;//resto
	char	*found_line;
	int		i;
//caracter en index se incluye en new_str
	new_str = ft_calloc(sizeof(char), (ft_strlen(line) - index + 1));
	found_line = ft_calloc(sizeof(char), (index + 1));
	if (!new_str || !found_line)
		return (NULL);
	i = 0;
	while (i < index)
	{
		found_line[i] = line[i];
		i++;
	}
	i = 0;
	while (line[index + i])
	{
		new_str[i] = line[index + i];
		i++;
	}
	//new_str[i] = '\0';
	free(line);
	line = new_str;
	return (found_line);
}

/*static char	*ft_join_str(char	*first_line, char *last_line)
{
	int		f_l_len[2];
	int		i_j[2];
	char	*new_line;

	f_l_len[0] = ft_strlen(first_line);
	f_l_len[1] = ft_strlen(last_line);
	new_line = ft_calloc(sizeof(char), (f_l_len[0] + f_l_len[1] + 1));
	if (!new_line)
		return (NULL);
	i_j[0] = -1;
	while (++i_j[0] < f_l_len[0])
		new_line[i_j[0]] = first_line[i_j[0]];
	i_j[1] = 0;
	while (i_j[0] < (f_l_len[0] + f_l_len[1]))
	{
		new_line[i_j[0]] = last_line[i_j[1]];
		i_j[0]++;
		i_j[1]++;
	}
	//new_line[i_j[0]] = '\0';
	free(first_line);
	free(last_line);
	return (new_line);
}*/

static char	*ft_find_line(int fd, char *saved)
{
	char	*aux;
	char	*joined_str;
	int		i;
	
	i = ft_find_nl(saved);
	if (i >= 0)
		return (ft_cut_line(saved, i));
	else
	{
		aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!aux)
			return (NULL);
		i = read(fd, aux, BUFFER_SIZE);
		if (i == 0)//si no hay mas que leer devuelve lo que hay
			return (saved);
		printf(">%s<\n", saved);
		printf(">%s\n<", aux);
		joined_str = ft_strjoin(saved, aux);
		//saved = joined_str;//strcpy???
		//ft_find_line(fd, saved);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	//int BUFFER_SIZE = 42;//BORRAR!!!
	static char	*lines[OPEN_MAX];
	char	*line;
	//int		readen;

	line = NULL;
	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!lines[fd])
		lines[fd] = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!lines[fd])
			return (NULL);
	line = ft_find_line(fd, lines[fd]);
	return (line);
}
