/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:18:46 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/31 22:42:04 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_linge.h"

int	check_buff(char *buff)
{
	int	index;

	index = 0;
	while (buff[index])
	{
		if (buff[index] == '\n')
			return (1);
		else
			index += 1;
	}
	return (0);
}

char	*get_next_linge(int fd)
{
	char		buff[6];
	char		tmp;
	static char	tmp2;
	int			read_size;

	tmp = NULL;
	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buff, 1)
		if (!read_size)
			break;
		if (tmp2)
		{
			tmp = ft_strcat(tmp2, buff);
			tmp2 = NULL;
			continue;
		}
		if (!check_buff(buff))
		{
			tmp = ft_strcat(tmp, buff);
			tmp = NULL;
			continue;
		}
		else
		{
			if (!tmp)
				final_str = ft_split(buff, tmp2);
			else
				{
					tmp3 = ft_split(buff, tmp2);
					final_str = ft_strcat(tmp, tmp3);
				}
			return (final_str)
		}
	}
		write(1, "(null)", 6);
		return (0);
}
