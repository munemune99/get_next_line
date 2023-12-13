#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>

char    *get_next_line(int fd);
int	    ft_cut(const char *s);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char    *ft_strized(char *stock);
void	*ft_memmove(void *dest, const void *source, size_t n);

#endif