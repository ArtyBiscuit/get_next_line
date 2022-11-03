/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:18:46 by arforgea          #+#    #+#             */
/*   Updated: 2022/11/03 19:47:27 by arforgea         ###   ########.fr       */
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	int		b_size;

	b_size = nmemb * size;
	if (nmemb >= 2147483647 && size >= 2147483647)
		return (NULL);
	tab = malloc(b_size);
	if (!tab)
		return (NULL);
	while (b_size)
		tab [--b_size] = 0;
	return (tab);
}

char	*get_last_line(char **str)
{
	char	*final_str;

	final_str = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (final_str);
}

char	*get_tmp(char **tmp)
{
	char	*final_str;
	int		tmp_size;
	int		index;

	index = check_buff(*tmp);
	tmp_size = ft_strlen(*tmp);
	final_str = ft_substr(*tmp, index, tmp_size - index);
	free(*tmp);
	*tmp = NULL;
	return (final_str);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		*buff;
	char		*final_str;
	int			read_size;

	while (!check_buff(tmp))
	{	
		buff = ft_calloc(1, BUFFER_SIZE + 1);
		read_size = read(fd, buff, BUFFER_SIZE);
		if (!read_size || read_size == -1)
		{
			free(buff);
			if (tmp && *tmp != 0)
			{
				final_str = get_last_line(&tmp);
				return (final_str);
			}
			return (NULL);
		}
		tmp = ft_strcat(tmp, buff);
	}
	final_str = ft_substr(tmp, 0, check_buff(tmp));
	tmp = get_tmp(&tmp);
	return (final_str);
}
