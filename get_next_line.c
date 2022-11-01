/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:18:46 by arforgea          #+#    #+#             */
/*   Updated: 2022/11/01 23:07:07 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	check_buff(char *buff)
{
	int	index;

	index = 0;
	if (!buff)
		return 0;
	while (buff[index])
	{
		if (buff[index] == '\n')
			return (index);
		index += 1;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*src;
	char	*dest;
	int		i;

	src = (char *) s;
	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_s;

	src_s = ft_strlen(src);
	i = 0;
	if (!size)
		return (src_s);
	while (size - 1 > i && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final_tab;
	size_t	s_len;
 
	if (!s)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		final_tab = ft_strdup("");
		return (final_tab);
	}
	s_len = ft_strlen(s + start);
	if (s_len < len)
		len = s_len;
	final_tab = malloc(sizeof (char) * len + 1);
	if (!final_tab)
		return (NULL);
	ft_strlcpy(final_tab, s + start, len + 1);
		return (final_tab);
}

char	*get_line(char *str)
{
	int	index_s;
	int	index_e;
	char *final_str;

	index_s = check_buff(str);
	index_e = ft_strlen(str);
	final_str = ft_substr(str, 0, index_s);
	return (final_str);
}

char	*get_satic(char *str)
{
	int	index_s;
	int	index_e;
	char *final_str;

	index_s = check_buff(str);
	index_e = ft_strlen(str);
	final_str = ft_substr(str, index_s, index_e - index_s);
	free(str);
	return (final_str);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char	buff[6];
	char	*final_str;
	int		read_size;

	read_size = 1;
	while (!check_buff(tmp) || read_size)
	{
		read_size = read(fd, buff, 6);
		tmp = ft_strcat(tmp, buff);
	}
	final_str = get_line(tmp);
	tmp = get_satic(tmp);
	return (final_str);
}

int main(void)
{
	int fd;
	fd = open("GNL.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
}
