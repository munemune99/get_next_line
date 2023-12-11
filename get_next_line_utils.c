/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:21:08 by jfrancoi          #+#    #+#             */
/*   Updated: 2023/11/30 11:21:10 by jfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_result(char* stock)
{
    size_t  i;
    char *new;

    while (stock[i] != '\n')
        i++;
    new = calloc(sizeof(char), i + 1);
    i = 0;
    while (stock[i] != '\n')
    {
        new[i] = stock[i];
        i++;
    }
    new[i] = '\n';
    return (new);
}

char    *ft_resetstock(char* stock)
{
    size_t  i;
    size_t  y;
    char    *new;

    i = 0;
    while (stock[i] != '\n')
        i++;
    i++;
    while (stock[i])
    {
        i++;
        y++;
    }
    new = malloc (sizeof(char) * i + 1);
    i -= y;
    y = 0;
    while (stock[i])
    {
        new[y] = stock[i];
        i++;
        y++;
    }
    new[y] = '\0';
    return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	y;
	char	*str;

	i = 0;
	y = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	str = malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		str[i] = s1[i];
		i++;
	}
	while (y < ft_strlen(s2) + 1)
		str[i++] = s2[y++];
	return (str);
}
char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	s2 = malloc (sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
