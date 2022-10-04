/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:17:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/04 10:22:58 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * ELIMINAR LINEAS SI ALGUN MALLOC FALLA (REVISAR CADA IF() RETURN NULL)
 * */
char	*ft_cut_line(char * line, int index)
{
	char	*new_str;
	int	i;

	new_str = malloc(sizeof(char) * (ft_strlen(line) - index + 1));//caracter en index se incluye en new_str
	if (!new_str)
		return (NULL);
	i = 0;
	while (line[index + i])
	{
		new_str[i] = line[index + i];
		i++;
	}
	new_str[i] = '\0';
	free(line);
	return (new_str);
}

char	*ft_join_str(char	*first_line, char *last_line)
{
	int		f_l_len[2];
	int		i_j[2];
	char	*new_line;

	f_l_len[0] = ft_strlen(first_line);
	f_l_len[1] = ft_strlen(last_line);
	new_line = malloc(sizeof(char) * (f_l_len + f_l_len + 1));
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
	new_line[i_j[0]] = '\0';
	free(first_line);
	free(last_line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char	**lines[OPEN_MAX];
	char		*str;
	
	if (fd < 0 || fd >= OPEN_MAX)
		return (NULL);
	if (!*lines[fd])
	{
		*lines[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!*lines[fd])
			return (NULL);
	}
	str = ft_find_line(*lines[fd]);
	if (!str)
		free(*lines[fd]);
	return (str);
}
