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

// char    *get_next_line(int fd)
// {
//     int i;
//     int n;
//     char*   buf;
//     char*   str;
//     static char*   stock;

//     n = 1;
//     buf = malloc(sizeof(char) * BUFFER_SIZE);
//     if (buf == NULL)
//         return (NULL);
//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (NULL);
//     while (n != 0)
//     {
//         i = 0;
//         n = read(fd, buf, BUFFER_SIZE);
//         if (n == 0)
//             return (NULL);
//         stock = ft_strjoin(stock, buf);
//         while (stock[i])
//         {
//             if (stock[i] == '\n')
//             {
//                 str = ft_result(stock);
//                 stock = ft_resetstock(stock);
//                 free(buf);
//                 return (str);
//             }
//             i++;
//         }
//     }
//     return (stock);
// }


int ft_is_empty(char* buf)
{
    if (!buf)
        return (-1);
    else
        return (0);
}

int ft_check_backslash(char *buf)
{
    size_t  i;

    i = 0;
    while (buf[i])
    {
        if (buf[i] == '\n')
            return (0);
        i++;
    }
    return (-1);
}

char    *get_next_line(int fd)
{
    char    *buf;
    char    *str;
    static char *stock;
    int     n;

    n = 1;
    while (n != 0)
    {
        buf = calloc(sizeof(char), BUFFER_SIZE + 1);
        n = read(fd, buf, BUFFER_SIZE);
        buf[n] = '\0';
        stock = calloc(sizeof(char), ft_strlen(buf));
        stock = ft_strjoin(stock, buf);
        if (ft_check_backslash(buf) == 0)
        {
            str = ft_result(stock);
            stock = ft_resetstock(stock);
            return (str);
        }
    }
    return (NULL);
}
int main(void)
{
    int i;
    int n;
    char    *str;

    n = 6;
    while (n > 0)
    {
        i = open ("txt.txt", O_RDONLY);
        str = get_next_line(i);
        printf("%s", str);
        n--;
    }
    return (0);
}
