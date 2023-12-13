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

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	s1 = (char *)dest;
	s2 = (char *)source;
	i = 0;
	if (s1 == s2 || n == 0)
		return (s1);
	if (s1 > s2)
	{
		while (n-- > 0)
			s1[n] = s2[n];
	}
	else
	{
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (s1);
}

int	ft_cut(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
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
	free(s1);
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
