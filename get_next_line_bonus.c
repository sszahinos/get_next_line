/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:15:35 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/26 16:15:43 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
	return (NULL);
}

static char	*ft_cut_saved(char *saved)
{
	char	*new_saved;
	int		i;

	i = 0;
	while (saved[i])
	{
		if (saved[i++] == '\n')
			break ;
	}
	if (!saved[i])
	{
		return (ft_free(&saved));
	}
	new_saved = ft_substr(saved, i, ft_strlen(saved) - i);
	ft_free(&saved);
	if (!new_saved)
		return (NULL);
	return (new_saved);
}

static char	*ft_find_line(char *saved)
{
	int	i;

	i = 0;
	while (saved[i])
	{
		if (saved[i++] == '\n')
			break ;
	}
	return (ft_substr(saved, 0, i));
}

static char	*ft_read_line(char *saved, int fd)
{
	char	*aux;
	int		bytes;

	bytes = 1;
	aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!aux)
	{
		ft_free(&saved);
		return (NULL);
	}
	while (!ft_strchr(aux, (int) '\n') && (bytes > 0))
	{
		bytes = read(fd, aux, BUFFER_SIZE);
		if (bytes > 0)
		{
			aux[bytes] = '\0';
			saved = ft_strjoin(saved, aux);
		}
	}
	free(aux);
	if (bytes == -1)
	{
		return (ft_free(&saved));
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*fd_list[OPEN_MAX] = {0};
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	if ((fd_list[fd] && !ft_strchr(fd_list[fd], '\n')) || !fd_list[fd])
		fd_list[fd] = ft_read_line(fd_list[fd], fd);
	if (!fd_list[fd])
		return (NULL);
	line = ft_find_line(fd_list[fd]);
	if (!line)
	{
		ft_free(&fd_list[fd]);
		return (NULL);
	}
	fd_list[fd] = ft_cut_saved(fd_list[fd]);
	return (line);
}
