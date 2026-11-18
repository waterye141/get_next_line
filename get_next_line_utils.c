/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboughad <aboughad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 15:36:52 by aboughad          #+#    #+#             */
/*   Updated: 2026/11/18 16:35:42 by aboughad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_memcpy(void *dst, void *src, size_t len)
{
	char *d;
	char *s;

	d = dst;
	s = src;
	while(len--)		
		*d++ = *s++;
}

int	find_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return(0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	char	*new_str;

	if (!s1)
		return (s2);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, ft_strlen(s1));
	i = 0;
	while (i < ft_strlen(s2))
	{
		new_str[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	new_str[ft_strlen(s1) + i] = '\0';
	free(s1);
	return (new_str);
}

char	*ft_substr(char *str, unsigned int start)
{
	char	*sub;
	size_t	len;

	len = ft_strlen(&str[start]) + 1;
	sub = malloc(len);
	ft_memcpy(sub, &str[start], len);
	sub[len - 1] = '\0';
	free(str);
	return (sub);
}
