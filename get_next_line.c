
#include "get_next_line.h"
#include <unistd.h>

/*
 * Cut a line from 0 to index. Frees the entire line
 * and returns the new line.
 */
void	*cut_line(void *line, int index)
{
	int	i;
	
	new_line = malloc(sizeof(char) * (index + 1));
	if (!new_line)
		return (NULL);
	i = 0;
	while (i <= index)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[i] = '\0';
	free(line);
	return (new_line);
}

char	*get_next_line(int fd)
{
	void	**line[256];
	int		found;

	found = 0;
	if (fd < 0 || fd >= 256)//controlar line[]?
		return (null)
	line[fd] = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!line[fd])
		return (NULL);
	while (!found)
	{
		if (read(fd, line[fd], BUFFER_SIZE) > 0)
		{//hay texto
			index = ft_find_char((char *)line[fd], '\n');
			if (index > 0) //encuentra \n o EOF
			{
				found = 1;
				return (ft_cut_line(line[fd], index));
			}
			else //else no hace falta
			{//No ha encontrado \n ni EOF. aumenta la linea
				ft_reset_	
			}
		}
	}
	free(line[fd]);
//	free(line);
	return (NULL);
}

/*
int	main(void)
{
	
}*/
