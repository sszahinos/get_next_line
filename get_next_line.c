/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:17:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/05 16:41:20 by sersanch         ###   ########.fr       */
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
	printf("entra cut\n");
	//printf("index >%d< len>%d<\n", index,  ft_strlen(line) - index + 1);
	new_str = ft_calloc(sizeof(char), (ft_strlen(*line) - index + 1));
	found_line = ft_calloc(sizeof(char), (index + 1));
	if (!new_str || !found_line)
	{
		printf("error\n");
		return (NULL);
	}
	i = 0;
	printf("index\t>%d<\n", index);
	while (i < index)
	{
		found_line[i] = (*line)[i];
		printf("char found line>%c<\n", found_line[i]);
		i++;
	}
	printf("palabra encontrada >%s<\n", found_line);
	i = 0;
	index++;
	printf("lineIndexI >%s<>%c<\n", *line, (*line)[index + i]);
	while ((*line)[index + i])
	{
		new_str[i] = (*line)[index + i];
		printf("CHAR new str>%c<\n", new_str[i]);
		i++;
	}
	//new_str[i] = '\0';
	//free(line);
	*line = new_str;
	//free(new_str);
	printf("linea renovada >%s<\n", *line);
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

static int	ft_strcpy(char **dest, char **src)
{
	int		len;
	char	*aux;
	int		i;
	printf("dest\t>%s<\n", *dest);
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
	printf("dest-2\t>%s<\n", *dest);
	return (1);
}

static char	*ft_find_line(int fd, char **saved)
{
	char	*aux;
	char	*joined_str;
	int		i;
	
	i = ft_find_nl(*saved);
	printf("entra findline i>%d<\n", i);
	if (i >= 0)
	{
		printf("???????? cut\n");
		return (ft_cut_line(&*saved, i));
	}
	else
	{
		aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!aux)
			return (NULL);
		i = read(fd, aux, BUFFER_SIZE);
		//printf("i\t>%d<\n", i);
		if (i <= 0)//si no hay mas que leer devuelve lo que hay
			return (*saved);
		printf("saved\t>%s<\n", *saved);
		printf("aux\t>%s<\n", aux);
		joined_str = ft_strjoin(*saved, aux);
		printf("joined\t>%s<\n", joined_str);
		ft_strcpy(&*saved, &joined_str);//strcpy???
		//free(joined_str);
		printf("saved2\t>%s<\n", *saved);
		return (ft_find_line(fd, saved));
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
	printf(">>>> linesFD  >%s<\n", lines[fd]);
	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!lines[fd])
		lines[fd] = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!lines[fd])
			return (NULL);
	line = ft_find_line(fd, &lines[fd]);
	return (line);
}
