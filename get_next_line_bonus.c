/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:39:02 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/02/20 21:59:09 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	freethis(char *ptr)
{
	free(ptr);
	ptr = NULL;
}

int	checknl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_line(char *str, int var)
{
	int		i;
	char	*tmp;

	i = 0;
	if (!*str)
		return (NULL);
	if (var)
	{
		while (str[i] != '\n' && str[i])
			i++;
		tmp = ft_substr(str, 0, i + 1);
		return (tmp);
	}
	else
	{
		while (str[i] != '\n' && str[i])
			i++;
		if (str[i] == '\n')
			i++;
		tmp = ft_substr(str, i, ft_strlen(str));
		return (tmp);
	}
	return (NULL);
}

char	*magic(char *str, int fd)
{
	int			c;
	char		*tmp;
	char		*tmp2;
	static char	*line[OPEN_MAX];

	c = 1;
	if (line[fd] == NULL)
		line[fd] = ft_strdup("");
	while (checknl(line[fd]))
	{
		c = read(fd, str, BUFFER_SIZE);
		if (c <= 0)
			break ;
		str[c] = '\0';
		tmp = line[fd];
		line[fd] = ft_strjoin(line[fd], str);
		freethis(tmp);
	}
	tmp2 = line[fd];
	tmp = get_line(tmp2, 1);
	line[fd] = get_line(tmp2, 0);
	freethis(tmp2);
	freethis(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (0);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		freethis(str);
		return (NULL);
	}
	str = magic(str, fd);
	return (str);
}

// int	main(int argc, char **argv)
// {
// 	int	fd, fd2, fd3, fd4;

// 	fd = open(argv[1], O_RDONLY);
// 	fd2 = open(argv[2], O_RDONLY);
// 	fd3 = open(argv[3], O_RDONLY);
// 	fd4 = open(argv[4], O_RDONLY);
// 	// printf("file1: %s\n", get_next_line(fd));
// 	// printf("file2: %s\n", get_next_line(fd2));
// 	// printf("file3: %s\n", get_next_line(fd3));
// 	// printf("file4: %s\n", get_next_line(fd4));
// 	// printf("file1: %s\n", get_next_line(fd));
// 	printf("%d", OPEN_MAX);
// 	return (0);
// }