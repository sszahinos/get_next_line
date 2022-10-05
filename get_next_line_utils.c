/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:57:54 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/05 14:55:59 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		//printf("strlen str[%d] = >%c<\n", i, str[i]);
		i++;
	}
	return (i);
}

int	ft_find_nl(char *str)
{
	int	i;

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
	while (i < len)
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens1;
	int		lens2;
	int		i;
	int		j;
	char	*new_word;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	new_word = ft_calloc(sizeof(char), (lens1 + lens2 + 1));
	if (!new_word)
		return (0);
	i = -1;
	while (s1[++i])
		new_word[i] = s1[i];
	j = 0;
	while (s2[j])
	{
		new_word[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	free(s2);
	//printf("llega");
	return (new_word);
}
