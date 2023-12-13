#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>

char    *get_next_line(int fd);
char	*ft_reset_stock(char *stock);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char    *ft_strized(char *stock);
char	*ft_strchr(const char *s, int c);

#endif