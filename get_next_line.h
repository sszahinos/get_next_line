/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:01:27 by sersanch          #+#    #+#             */
/*   Updated: 2022/10/04 15:31:29 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#	define BUFFER_SIZE 5
# endif


# include <limits.h>
# include <stdlib.h>
//BORRAR esto y printfs
	#include <stdio.h>
//

char	*get_next_line(int fd);

/*UTILS*/
int	ft_strlen(char *str);
int	ft_find_nl(char *str);
char	*ft_substr(char *str, int len);
void	*ft_calloc(int size, int count);
char	*ft_strjoin(char *s1, char *s2);



#endif
