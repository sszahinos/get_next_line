#include "get_next_line.h"

int	ft_find_nl(char *str, int i)
{
	if (!str)
		return (-2);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
