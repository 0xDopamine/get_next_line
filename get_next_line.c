/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:31:32 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/01/06 19:09:55 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

void	freethis(char *ptr)
{
	free(ptr);
}

char	*get_line(char **str, int var)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!**str)
		return (NULL);
	if (var)
	{
		while (str[0][i] != '\n' && str[0][i])
			i++;
		tmp = ft_substr(str, 0, i + 1);
		tmp[i + 1] = '\0';
		return (tmp);
	}
	else
	{
		while (str[0][i] != '\n' && str[0][i])
			i++;
		*str = ft_substr(str, i + 1, ft_strlen(*str));
		return (*str);
	}
	return (*str);
}

char	*magic(char *str, int fd)
{
	int			c;
	char		*tmp;
	static char	*line;

	c = 1;
	if (line == NULL)
		line = ft_strdup("");
	while (checknl(line))
	{
		c = read(fd, str, BUFFER_SIZE);
		str[c] = '\0';
		if (c <= 0)
			break;
		line = ft_strjoin(&line, str);
	}
	tmp = get_line(&line, 1);
	line = get_line(&line, 0);
	if (!c)
	{
		freethis(line);
		//freethis(str);
	}
	return (tmp);
}

char    *get_next_line(int fd)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	str = magic(str, fd);
	freethis(str);
	return (str);
}

// int main()
// {
// 	int file;
// 	int i = 1;

// 	file = open("41_with_nl", O_RDONLY);
// 	while (i < 41)
// 	{
// 	 	printf("%d: %s", i, get_next_line(file));
// 		i++;
// 	}
// 	return (0);
// }