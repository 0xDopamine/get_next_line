/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaioumy <mbaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:56:37 by mbaioumy          #+#    #+#             */
/*   Updated: 2022/01/05 18:50:08 by mbaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

int		checknl(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

size_t  ft_strlen(char *str)
{
        size_t  len;

        len = 0;
        while (str[len] != '\0')
                len++;
        return (len);
}

char	*ft_substr(char **s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	char			*s1;

	if (s == NULL)
		return (NULL);
	s1 = *s;
	i = start;
	j = -1;
	// if (len == 0 || start > ft_strlen(s1))
	// 	return (ft_strdup(""));
	if (len > ft_strlen(s1 + start))
		str = (char *)calloc((ft_strlen(s1 + start) + 1), sizeof(char));
	if (len <= ft_strlen(s1 + start))
		str = (char *)calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s1[i] && (size_t)++j < len)
		str[j] = s1[i++];
	return (str);
}

char	*cat(char *dest, char *s, int pos)
{
	int	i;

	i = 0;
	while (s[i])
	{
		dest[pos] = s[i];
		pos++;
		i++;
	}
	dest[pos] = '\0';
	return (dest);
}

char	*ft_strjoin(char  **s1, char  *s2)
{
	char	*tab;
	size_t	total;
	int		i;
	int		j;

	j = 0;
	if (*s1 == NULL && s2 == NULL)
		return (NULL);
	total = ft_strlen(*s1) + ft_strlen(s2) + 1;
	i = 0;
	tab = (char *)malloc(sizeof(char) * total + 1);
	if (!tab)
		return (NULL);
	tab = cat(tab, *s1, 0);
	tab = cat(tab, s2, ft_strlen(*s1));
	//free(*s1);
	return (tab);
}

char	*ft_strdup(char *src)
{
	int		i;
	size_t	len;
	char	*dest;

	i = 0;
	len = strlen(src);
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