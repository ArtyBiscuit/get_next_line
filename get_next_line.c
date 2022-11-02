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
#include "get_next_line.h"

int	check_buff(char *buff)
{
	int	index;

	index = 0;
	if (!buff)
		return 0;
	while (buff[index])
	{
		if (buff[index] == '\n')
			return (index + 1);
		index += 1;
	}
	return (0);
}

char	*get_line(char *str)
{
	int	index_s;
	int	index_e;
	char *final_str;
	char *tmp;

	index_s = check_buff(str);
	index_e = ft_strlen(str);
	tmp = malloc(sizeof(char) * index_e + 1);
	ft_strlcpy(tmp, str, index_e);
	final_str = ft_substr(tmp, 0, index_s);
	free(tmp);
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
	char	*buff;
	char	*final_str;
	int		read_size;
	
	while (!check_buff(tmp))
	{
		buff = malloc(sizeof(char) * 100);
		read_size = read(fd, buff, 100);
		if (!read_size)
		{
			free(buff);
			free(tmp):
			return (NULL);
		}
		tmp = ft_strcat(tmp, buff);
	}
	final_str = get_line(tmp);
	tmp = get_satic(tmp);
	return (final_str);
}


#include <stdio.h>
int main(void)
{
	int fd;
	int cmp;
	char *str;

	cmp = 0;
	fd = open("GNL.txt", O_RDONLY);
	while (++cmp < 6)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
	}
		free(str);
	close(fd);
}
