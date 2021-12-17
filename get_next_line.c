/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:31:32 by mbaioumy          #+#    #+#             */
/*   Updated: 2021/12/17 14:59:01 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int     linecount(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\n')
        i++;
    return i;
}

char    *get_next_line(int fd)
{
    char    *str;
    int     i;
    int     j;
    char    *line;

    j = 0;
    i = 0;
    str = (char *)malloc(sizeof(char) * BUFFER_SIZE);
    j = read(fd, str, BUFFER_SIZE);
    if (!j)
        return (NULL);
    str[j] = '\0';
    return (str);
}

int main()
{
    int file;

    file = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(file));

    return (0);
}