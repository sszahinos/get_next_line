/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:17:26 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/03 16:34:53 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_find_line(char * line)
{
	int	i;
	int	readen;
	char	*str;

	readen = -1;
	
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
