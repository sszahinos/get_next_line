#include "get_next_line.h"

int	ft_find_nl(t_line_info tli, int fd)
{
	if (!str)
		return (-2);
	i = 0;
	while (str[tli->index[fd]])
	{
		if (str[tli->index[fd]] == '\n')
			return (tli->index[fd]);
		tli->index[fd]++;
	}
	return (-1);
}
