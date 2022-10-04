#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (!str[i])
		i++;
	return (i);
}

int	ft_find_nl(char *str)
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

char	*ft_substr(char *str, int len)
{
	int	i;
	char	*sbstr;
	
	sbstr = ft_calloc(sizeof(char), (len + 1));
	if (!sbstr)
		return (NULL);
	i = 0;
	while (i <= end)
	{
		sbstr[i] = str[i];
		i++;
	}
	//sbstr[i] = '\0';
	return (sbstr);
}

void	*ft_calloc(int size, int count)
{
	char	*mem;
	int		i;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	i = 0;
	while (i < (size * count))
		mem[i++] = '\0';
	return ((void *)mem);
}
