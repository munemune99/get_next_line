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

char	*ft_reset_stock(char *stock)
{
	int	i;
	int	y;
	char *result;
	int test;

	i = 0;
	while (stock[i] != '\n')
		i++;
	i++;
	while (stock[i] != '\0')
	{
		i++;
		y++;
	}
	result = malloc(sizeof(char) * y + 1);
	result[y] = '\0';
	i -= y;
	y = 0;
	while (result[y] != '\0')
	{
		result[y] = stock[i];
		i++;
		y++;
	}
	result[y] = '\0';
	//free(stock);
	return (result);
}

char	*ft_strchr(const char *s, int c)
{
	char	*pt;
	size_t	i;

	i = 0;
	while (c > 127)
		c = c - 128;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			pt = (char *)&s[i];
			return (pt);
		}
		else
			i++;
	}
	if (c == '\0')
	{
		pt = (char *)&s[i];
		return (pt);
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
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
	//free(s2);
	//free(s1);
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
