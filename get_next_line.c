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
    while (stock[i] != '\n')
        i++;
    result = malloc(sizeof(char) * i + 1);
    i = 0;
    while (stock[i] != '\n')
    {
        result[i] = stock[i];
        i++;
    }
    result[i] = '\n';
    return (result);
}

char    *get_next_line(int fd)
{
    char    *fill;
    char    *str;
    static char *stock;
    int     n;

    n = 1;
    while (n != 0)
    {
        if (!fill)
        {
            fill = malloc(sizeof(char) * BUFFER_SIZE + 1);
            fill[BUFFER_SIZE] = '\0';
        }
        n = read(fd, fill, BUFFER_SIZE);
        fill[BUFFER_SIZE] = '\0';
        if (n == -1)
            return (NULL);
        if (stock)
            stock = ft_strjoin(stock, fill);
        else
            stock = ft_strdup(fill);
        if (ft_strchr(stock, '\n'))
            break;
    }
    str = ft_strized(stock);
    stock = ft_reset_stock(stock);
   // free (fill); invalid pointer
    return (str);
}
int main(void)
{
    int i;
    int n;
    char    *str;

    n = 1;
    i = open ("txt.txt", O_RDONLY);
    while (n > 0)
    {
        str = get_next_line(i);
        printf("%s", str);
        n--;
    }
    free (str);
    return (0);
}
// PROBLEME : NE PEUT PAS LIRE LE '\0' DE LA DERNIERE LIGNE
// NE MARCHE PAS AVEC DES BUFFER_SIZE DE 5 (PEUT ETRE MOINS)
