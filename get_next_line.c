/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:17:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/04 11:09:37 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * ELIMINAR LINEAS SI ALGUN MALLOC FALLA (REVISAR CADA IF() RETURN NULL)
 * */
static char	*ft_cut_line(char * line, int index)
{
	char	*new_str;
	int	i;

	new_str = ft_calloc(sizeof(char), (ft_strlen(line) - index + 1));//caracter en index se incluye en new_str
	if (!new_str)
		return (NULL);
	i = 0;
	while (line[index + i])
	{
		new_str[i] = line[index + i];
		i++;
	}
	//new_str[i] = '\0';
	free(line);
	return (new_str);
}

static char	*ft_join_str(char	*first_line, char *last_line)
{
	int		f_l_len[2];
	int		i_j[2];
	char	*new_line;

	f_l_len[0] = ft_strlen(first_line);
	f_l_len[1] = ft_strlen(last_line);
	new_line = ft_calloc(sizeof(char), (f_l_len + f_l_len + 1));
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
}

char	*ft_find_line(int fd, char *saved)
{
	char	*str;
	char	*joined_str;
	int		i;

	i = ft_find_nl(saved);
	str = NULL;
	if (i < 0)//si no encuentra salto de linea
	{
		str = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!str)
			return (-1);
		i = read(fd, str, BUFFER_SIZE);
		if (i > 0)
		{
			joined_str = ft_join_str(saved, str);
			return (joined_str)
		}
	}
	else
		str = ft_cut_line(saved, i);
	return (NULL);
}

char	*get_next_line(int fd)
{BUFFER_SIZE = 42;
	static char	*lines[OPEN_MAX];
	char	*line;
	int		readen;

	line = NULL;
	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!lines[fd])
		lines[fd] = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
		if (!lines[fd])
			return (NULL);
	while (!line)//????????/
	{
		line = ft_find_line(fd, lines[fd]);
		if (line == -1)
			return (NULL);
	}
	return (line);
}
