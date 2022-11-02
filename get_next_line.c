/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:18:46 by arforgea          #+#    #+#             */
/*   Updated: 2022/11/02 20:47:27 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	check_buff(char *buff)
{
	int	index;

	index = 0;
	if (!buff)
		return (0);
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
	int		index_s;
	int		index_e;
	char	*final_str;
	char	*tmp;

	index_s = check_buff(str);
	index_e = ft_strlen(str);
	tmp = malloc(sizeof(char) * index_e + 1);
	ft_strlcpy(tmp, str, index_e + 1);
	final_str = ft_substr(tmp, 0, index_s);
	free(tmp);
	return (final_str);
}

char	*get_satic(char *str)
{
	int		index_s;
	int		index_e;
	char	*final_str;

	index_s = check_buff(str);
	index_e = ft_strlen(str);
	final_str = ft_substr(str, index_s, index_e - index_s);
	free(str);
	return (final_str);
}

char	*get_last_line(char *str)
{
	char	*tmp;
	int		str_size;

	if (!str)
		return (0);
	str_size = 1 + ft_strlen(str);
	tmp = malloc(sizeof(char) * str_size);
	ft_strlcpy(tmp, str, str_size);
	free(str);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buff;
	char		*final_str;
	int			read_size;

	while (!check_buff(tmp))
	{
		buff = malloc(sizeof(char) * 100);
		read_size = read(fd, buff, 100);
		if (!read_size)
		{
			free(buff);
			if (tmp != NULL)
			{
				final_str = get_last_line(tmp);
				tmp = NULL;
				return (final_str);
			}	
			return (NULL);
		}
		tmp = ft_strcat(tmp, buff);
	}
	final_str = get_line(tmp);
	tmp = get_satic(tmp);
	return (final_str);
}
