/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboughad <aboughad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:29:35 by aboughad          #+#    #+#             */
/*   Updated: 2026/11/19 16:52:03 by aboughad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*extract_line(char *s, int end)
{
	char	*line;

	line = malloc(end + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, s, end);
	line[end] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;
	char		*temp;
	int			bytes_read;

	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (find_newline(stash[fd]) < 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			line = stash[fd];
			stash[fd] = NULL;
			return (free(temp), line);
		}
		temp[bytes_read] = '\0';
		stash[fd] = ft_strjoin(stash[fd], temp);
	}
	line = extract_line(stash[fd], find_newline(stash[fd]) + 1);
	stash[fd] = ft_substr(stash[fd], find_newline(stash[fd]) + 1);
	return (free(temp), line);
}
