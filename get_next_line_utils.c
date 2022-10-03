#include "get_next_line.h"

int	ft_find_nl(t_line_info tli)
{
	if (!tli->line)
		return (-2);
	//i = 0;
	while (tli->line[index])
	{
		if (tli->line[index] == '\n')
		{
			tli.index++;
			return (tli->index[fd]);
		}
		tli.index++;
	}
	return (-1);
}
