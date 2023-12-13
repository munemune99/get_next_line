/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:56:31 by jfrancoi          #+#    #+#             */
/*   Updated: 2023/11/30 10:56:38 by jfrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strized(char *stock)
{
    int i;
    char    *result;

    i = 0;
    if (ft_cut(stock) == -1)
        {
            result = ft_strdup(stock);
            return (result);
        }
    while (stock[i] != '\n')
        i++;
    result = malloc(sizeof(char) * i + 2);
    i = 0;
    while (stock[i] != '\n')
    {
        result[i] = stock[i];
        i++;
    }
    result[i] = '\n';
    result[i + 1] = 0;
    return (result);
}

char    *get_next_line(int fd)
{
    static char stock[BUFFER_SIZE + 1];
    char        fill[BUFFER_SIZE + 1];
    char        *str;
    char        *stash;
    int         n;

    if (fd < 0 || buffer_size <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    n = 1;
    stash = ft_strdup(stock);
    if (stash == NULL)
        return (NULL); 
    while (n != 0 && ft_cut(stash) == -1)
    {
        n = read(fd, fill, BUFFER_SIZE);
        fill[n] = 0;
        if (n == -1)
            return (free(stash), NULL);
        stash = ft_strjoin(stash, fill);
        if (ft_cut(stash) != -1)
            break;
    }
    str = ft_strized(stash);
    if ((ft_cut(stash) != -1) && n != 0)
        ft_memmove(stock, stash + ft_cut(stash) + 1, ft_strlen(stash) - ft_cut(stash));
    else
        stock[0] = '\0';
   if (str[0] == '\0')
        return (free(stash), free(str), NULL);
    else
        return (free(stash), str);
}
int main(void)
{
    int i;
    int n;
    char    *str;

    n = 3;
    i = open ("txt.txt", O_RDONLY);
    str = get_next_line(i);
    while (str)
    {
        printf("%s", str);
        free(str);
        str = get_next_line(i);
        n--;
    }
    close(i);
    return (0);
}
// PROBLEME : NE PEUT PAS LIRE LE '\0' DE LA DERNIERE LIGNE
// NE MARCHE PAS AVEC DES BUFFER_SIZE DE 5 (PEUT ETRE MOINS)
