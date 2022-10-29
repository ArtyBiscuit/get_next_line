/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:06:12 by arforgea          #+#    #+#             */
/*   Updated: 2022/10/29 18:12:18 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>

void	ft_strcpy(char *src, char *dest, int size)
{
	int index;

	index = 0;
	while (src[index] && size)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index + 1] = '\0';
}

char *mini_split(char *src, char *src_prev, int index)
{
	int src_size;
	char *f_str;

	src_size = 0;
	while (src[src_size])
		src_size++;
	f_str = malloc(sizeof(char) * index + 1);
	ft_strcpy(src, f_str, index);
	src_prev = malloc(sizeof(char) * src_size - index + 1);
	ft_strcpy(src + index, src_prev, src_size - index);
	return (f_str);
}

int	chek_bn(char *str)
{
	int	index;
	int size;

	if (!str)
		return (0);
	size = 0;
	while (str[size])
		size++;
	index = 0;
	while (str[index] != '\n' && str[index])
		index++;
	if (size == index)
		return (0);
	return (index);
}

char	*ft_strcat(char *s1, char *s2)
{
	int		s_s1;
	int		s_s2;
	char	*f_str;

	s_s1 = 0;
	while(s1[s_s1])
		s_s1++;
	s_s2 = 0;
	while(s2[s_s2])
		s_s2++;
	f_str = malloc(sizeof(char) * s_s1 + s_s2 + 1);
	if (!f_str)
		return (0);
	s_s1 = -1;
	s_s2 = -1;
	while (s1[++s_s1])
		f_str[s_s1] = s1[s_s1];
	while (s2[++s_s2])
	{
		f_str[s_s1] = s2[s_s2];
		s_s1++;
	}
	f_str[s_s1 + 1] = '\0';
	return (f_str);
}
