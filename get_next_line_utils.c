/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforgea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 19:02:10 by arforgea          #+#    #+#             */
/*   Updated: 2022/11/03 18:05:15 by arforgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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

char	*ft_strcat(char *s1, char *s2)
{
	int		s_s1;
	int		s_s2;
	char	*f_str;

	s_s1 = 0;
	s_s2 = 0;
	if (s1)
		s_s1 = ft_strlen(s1);
	if (s2)
		s_s2 = ft_strlen(s2);
	f_str = malloc(sizeof(char) * (s_s1 + s_s2) + 1);
	if (s1)
	{
		ft_strlcpy(f_str, s1, s_s1 + 1);
		free(s1);
		s1 = NULL;
	}
	if (s2)
	{
		ft_strlcpy(f_str + s_s1, s2, s_s2 + 1);
		free(s2);
		s2 = NULL;
	}
	return (f_str);
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
