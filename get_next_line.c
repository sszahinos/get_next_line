/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:17:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/13 12:52:10 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
/*
 * ELIMINAR LINEAS SI ALGUN MALLOC FALLA (REVISAR CADA IF() RETURN NULL)
 * */
static char	*ft_cut_line(char **line, int index, int end)//devuelve linea
{
	char	*new_str;//resto
	char	*found_line;
	int		i;
	printf("cutline string>%s< index>%d< end>%d<\n", *line, index, end);
//caracter en index se incluye en new_str
	new_str = ft_calloc(sizeof(char), (ft_strlen(*line) - index + 1));
	found_line = ft_calloc(sizeof(char), (index + 2));
	if (!new_str || !found_line)
	{
		return (NULL);
	}
	i = 0;
	while (i <= index)
	{
		found_line[i] = (*line)[i];
		//printf("found line >%c<\n", found_line[i]);
		i++;
	}
//	found_line[i] = (*line)[i];//POR QUE PONE SALTO DE LINEA AL FINAL??
	if (end == 1)
	{
		printf("ENTRA\n");
		found_line[--i] = '\0';
	}
	i = 0;
	index++;
	while ((*line)[index + i])
	{
		new_str[i] = (*line)[index + i];
		i++;
	}
	//new_str[i] = '\0';
	if (*line)
	{
		//printf("LINE \n");
		free(*line);
		*line = NULL;
	}
	*line = new_str;
	/*if (new_str)
	{
	//	printf("ENTRA >%s<\n", new_str);
		//free(new_str);
	}*/
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
	free(aux);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	//free(*src);
	return (1);
}
/*
static char	*ft_find_line(int fd, char **saved)
{
	int	found;
	char	*joined_str;
	char	*aux;

	found = 0;
	while (found == 0)
	{
		found = ft_find_nl(*saved);
	//	printf("found >%d<\n", found);
		if (found < 0) //no hay salto de linea
		{
		//	printf("------------- \n");
			aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
			if (!aux)
			{
				return (NULL);
			}
			found = read(fd, aux, BUFFER_SIZE);
			if (found == 0)
			{
				free(aux);
				//printf("FINAL >%s<\n", *saved);
				return (NULL);//Finaliza str sin encontrar salto de linea
			}
			joined_str = ft_strjoin(*saved, aux);
			ft_strcpy(&*saved, &joined_str);
			found = 0;
		}
		else //hay salto de linea
		{
		//	printf("ELSE >%s<\n", *saved);
			return (ft_cut_line(saved, found, 1));
		}
	}
	return (NULL);
}
*/
static char	*ft_find_line(int fd, char **saved)
{
	char	*aux;
	char	*joined_str;
	int		i;
	//printf("tamanyo >%d<\n", ft_strlen(*saved));
//	printf("pre saved >%s<\n", *saved);

	i = ft_find_nl(*saved);
	printf("FIND LINE >%d<\n", i);
	if (i >= 0)
	{
		return (ft_cut_line(&*saved, i, 0));
	}
	else
	{
		aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!aux)
		{
			return (NULL);
		}
		i = read(fd, aux, BUFFER_SIZE);
		printf("aux , I >%s< >%d<\n", aux, i);
		if (i <= 0)//si no hay mas que leer devuelve lo que hay
		{
	//		printf("tamanyo >%d<\n", ft_strlen(*saved));
			printf("no hay mas saved >%s<\n", *saved);
			//return (*saved);
			return (ft_cut_line(saved, i, 1));
		}
		joined_str = ft_strjoin(*saved, aux);
		//free(aux);
		ft_strcpy(&*saved, &joined_str);
	//	if (joined_str)
	//		free(joined_str);
		//free(saved);
	//	printf("tamanyo >%d<\n", ft_strlen(*saved));
	//	printf("hay mas saved >%s<\n", *saved);
		char *borrar = ft_find_line(fd, saved);
		//printf("---- >%s<\n", borrar);
		return (borrar);
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	//static char	**lines;
	static char	*lines[OPEN_MAX + 1] = {0};
	char	*line;
	if (fd < 0)
		return (NULL);
	/*if (!lines)
	{
		lines = malloc((OPEN_MAX * sizeof(char *)) + 1);
		if (!lines)
		{
			printf("SALE\n");
			return (NULL);
		}
		lines[OPEN_MAX] = NULL;
	}*/
	line = NULL;
	if (!lines[fd])
	{
		lines[fd] = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!lines[fd])
		{
			//if (lines)
			//	free(lines);
			return (NULL);
		}
	}
	printf("guardado >%s<\n", lines[fd]);
	line = ft_find_line(fd, &lines[fd]);
	if (!line || line[0] == '\0') 
	{
		free(line);
		line = NULL;
		//printf("LLEGA >%s<\n", lines[fd]);
	}
	//printf("tamano final>%d<\n", ft_strlen(line));
/*	printf("%d\n", getpid());
	while (1)
		usleep(10);*/
	return (line);
}
