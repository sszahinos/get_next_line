/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:17:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/13 15:55:07 by sersanch         ###   ########.fr       */
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
/*	if (end == 1)
	{
		printf("ENTRA\n");
		found_line[--i] = '\0';
	}*/
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

static char	*ft_find_line(int fd, char **saved)
{
	int	found;
	char	*joined_str;
	char	*aux;

	aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	found = 0;
	while (found == 0)
	{
		found = ft_find_nl(*saved);
	//	printf("found >%d<\n", found);
		if (found < 0) //no hay salto de linea
		{
		//	printf("------------- \n");
			if (!aux)
			{
				free(*saved);
				return (NULL);
			}
			found = read(fd, aux, BUFFER_SIZE);
			if (found == 0)
			{
				free(aux);
				//printf("FINAL >%s<\n", *saved);
				return (*saved);//Finaliza str sin encontrar salto de linea
			}
			joined_str = ft_strjoin(*saved, aux);
			ft_strcpy(&*saved, &joined_str);
			found = 0;
		}
		else //hay salto de linea
		{
		//	printf("ELSE >%s<\n", *saved);
			free(aux);
			return (ft_cut_line(saved, found));
		}
	}
	return (NULL);
}
/*
static char	*ft_find_line(int fd, char **saved)
{
	char	*aux;
	char	*joined_str;
	int		i;
//	printf("pre saved >%s<\n", *saved);
	aux = ft_calloc(sizeof(char), buffer_size + 1);
	i = ft_find_nl(*saved);
	if (i >= 0)
	{
		return (ft_cut_line(&*saved, i));
	}
	else
	{
		if (!aux)
		{
			free(*saved);
			return (NULL);
		}
		i = read(fd, aux, BUFFER_SIZE);
		if (i <= 0)//si no hay mas que leer devuelve lo que hay
		{
			free(aux);
			return (*saved);
		}
		joined_str = ft_strjoin(*saved, aux);
		free(*saved);
		free(aux);
		ft_strcpy(&*saved, &joined_str);
	//	if (joined_str)
	//		free(joined_str);
		//free(saved);
	//	printf("tamanyo >%d<\n", ft_strlen(*saved));
		return(ft_find_line(fd, saved));
	}
	return (NULL);
}
*/
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
//	printf("guardado >%s<\n", lines[fd]);
	line = ft_find_line(fd, &lines[fd]);
	if (!line || line[0] == '\0') 
	{
//		printf("pointer1 >%p< ponter2 >%p<\n", line, lines[fd]);
		free(line);
		line = NULL;
	//	free(lines[fd]);
//		lines[fd] = NULL;
	//	printf("LLEGA >%s<\n", lines[fd]);
	}
/*	printf("%d\n", getpid());
	while (1)
		usleep(10);*/
	return (line);
}
