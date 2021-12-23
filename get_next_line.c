/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:31:32 by mbaioumy          #+#    #+#             */
/*   Updated: 2021/12/23 21:24:20 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

char	*get_line(char **str, int var)
{
	int		i;
	char	*tmp;
	int		j;

	j = 0;
	i = 0;
	if (var)
	{
		tmp = ft_strdup("");
		while (str[0][i])
		{
			if (str[0][i] == '\n')
				break ;
			tmp[j] = str[0][i];
			j++;
			i++;
		}
		tmp[j] = '\n';
		return (tmp);
	}
	else
	{
		i = 0;
		while (str[0][i])
		{
			if (str[0][i] == '\n')
			{
				*str = ft_substr(str, i + 1, strlen(*str));
				return (*str);
			}
			i++;
		}
	}
	return (*str);
}

char	*magic(char *str, int fd)
{
	int			c;
	int			i;
	char		*tmp;
	static char	*line;

	i = 0;
	c = 1;
	if (line == NULL)
		line = ft_strdup("");
	tmp = ft_strdup(line);
	while (c > 0 && checknl(line))
	{
		c = read(fd, str, BUFFER_SIZE);
		str[c] = '\0';
		if (c < 0)
			return (NULL);
		if (c > 0)
			line = ft_strjoin(&line, str);
	}
	tmp = get_line(&line, 1);
	line = get_line(&line, 0);
	return (tmp);
}

char    *get_next_line(int fd)
{
	char		*str;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	return (magic(str, fd));
}

// int main()
// {
// 	int file;
// 	int i = 1;

// 	file = open("files/empty", O_RDONLY);
// 	// while (i <= 5)
// 	// {
// 	 	printf("%d: %s", i, get_next_line(file));
// 	// 	i++;
// 	// }
// 	return (0);
// }