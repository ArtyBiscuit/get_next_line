/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:29:36 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/29 18:26:27 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>

#include <stdio.h>

char *get_next_line(int fd)
{
	char buff[1];
	char *f_str;
	char *tmp;
	char *tmp2;
	int  read_size;
	int index;

	tmp = NULL;
	f_str = NULL;
	read_size = 1;
	while (read_size)
	{
		read_size = read(fd, buff, 1);
		index = chek_bn(buff);
		if (index)
		{
			if (!f_str)
				f_str = mini_split(buff, tmp2, index);
			else
				tmp = mini_split(buff, tmp2, index);
				ft_strcat
		}		
		if (!tmp)
		{
			tmp = malloc(sizeof(char) * read_size);
			ft_strcpy(buff, tmp, read_size);
		}
		else if (tmp)
		{
			f_str = ft_strcat(tmp, buff);
			free(tmp);
			tmp = NULL;
			printf("%s", f_str);
		}
	}
	
}

int	main(void)
{
	int	fd;
//	int i = 0;
	
	fd = open("GNL.txt", O_RDONLY);
//	while (1)
//	{
//		getchar();
		get_next_line(fd);
//	}
	return (0);
}
