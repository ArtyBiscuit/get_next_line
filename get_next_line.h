#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <fcntl.h>

char *mini_split(char *src, char *src_prev, int index);
void    ft_strcpy(char *src, char *dest, int size);
int		chek_bn(char *str);
char    *ft_strcat(char *s1, char *s2);

#endif
