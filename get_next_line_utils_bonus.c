/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 17:39:25 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/02/18 21:40:00 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned int	len;
	void			*ptr;
	size_t			i;
	char			*str;

	i = 0;
	len = count * size;
	ptr = malloc(len * sizeof(char));
	if (!ptr)
		return (NULL);
	str = (char *)ptr;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}

char	*ft_strdup(char *src)
{
	int		i;
	size_t	len;
	char	*dest;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	char			*s1;

	if (s == NULL)
		return (NULL);
	s1 = s;
	i = start;
	j = -1;
	if (len > ft_strlen(s1 + start))
		str = (char *)ft_calloc((ft_strlen(s1 + start) + 1), sizeof(char));
	if (len <= ft_strlen(s1 + start))
		str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] && (size_t)++j < len)
		str[j] = s1[i++];
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	size_t	total;
	int		i;
	int		pos;

	pos = 0;
	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2) + 1;
	tab = (char *)malloc(sizeof(char) * total + 1);
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[pos++] = s1[i++];
	tab[pos] = '\0';
	i = 0;
	while (s2[i])
		tab[pos++] = s2[i++];
	tab[pos] = '\0';
	return (tab);
}
