/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:17:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/05 17:46:09 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
/*
 * ELIMINAR LINEAS SI ALGUN MALLOC FALLA (REVISAR CADA IF() RETURN NULL)
 * */
static char	*ft_cut_line(char **line, int index)//devuelve linea
{
	char	*new_str;//resto
	char	*found_line;
	int		i;
//caracter en index se incluye en new_str
	new_str = ft_calloc(sizeof(char), (ft_strlen(*line) - index + 1));
	found_line = ft_calloc(sizeof(char), (index + 1));
	if (!new_str || !found_line)
	{
		return (NULL);
	}
	i = 0;
	while (i < index)
	{
		found_line[i] = (*line)[i];
		i++;
	}
	i = 0;
	index++;
	while ((*line)[index + i])
	{
		new_str[i] = (*line)[index + i];
		i++;
	}
	//new_str[i] = '\0';
	//free(line);
	*line = new_str;
	//free(new_str);
	return (found_line);
}

static int	ft_strcpy(char **dest, char **src)
{
	int		len;
	char	*aux;
	int		i;
	len = ft_strlen(*src);
	aux = ft_calloc(sizeof(char), (len + 1));
	if (!aux)
		return (0);
	//free(dest);
	*dest = aux;
	//free(aux)??
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (1);
}

static char	*ft_find_line(int fd, char **saved)
{
	char	*aux;
	char	*joined_str;
	int		i;
	
	i = ft_find_nl(*saved);
	if (i >= 0)
	{
		return (ft_cut_line(&*saved, i));
	}
	else
	{
		aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!aux)
			return (NULL);
		i = read(fd, aux, BUFFER_SIZE);
		if (i <= 0)//si no hay mas que leer devuelve lo que hay
			return (*saved);
		joined_str = ft_strjoin(*saved, aux);
		//free(aux);
		ft_strcpy(&*saved, &joined_str);
	//	if (joined_str)
	//		free(joined_str);
		//free(saved);
		return (ft_find_line(fd, saved));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*lines[OPEN_MAX];
	char	*line;

	line = NULL;
	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!lines[fd])
		lines[fd] = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!lines[fd])
			return (NULL);
	line = ft_find_line(fd, &lines[fd]);
	return (line);
}
