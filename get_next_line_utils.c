#include "get_next_line.h"

int	find_char(char *str, char c)
{
	int	i;

	if (!str)
		return (-2);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
