/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:15:59 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/26 16:16:03 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;

	mem = malloc(size * count);
	if (!mem)
		return (0);
	i = 0;
	while (i < (size * count))
		mem[i++] = '\0';
	return ((void *)mem);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return ((size_t)i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	if ((unsigned char)s[i] == (unsigned char)c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		lens;
	int		i;
	int		j;
	char	*new_word;

	if (!s1)
	{
		s1 = ft_calloc(sizeof(char), 1);
		if (!s1)
			return (NULL);
	}
	lens = ft_strlen(s1) + ft_strlen(s2);
	new_word = malloc(sizeof(char) * (lens + 1));
	if (!new_word)
		return (ft_free(&s1));
	i = -1;
	while (s1 && s1[++i])
		new_word[i] = s1[i];
	j = 0;
	while (s2[j])
		new_word[i++] = s2[j++];
	new_word[i] = '\0';
	free(s1);
	return (new_word);
}
