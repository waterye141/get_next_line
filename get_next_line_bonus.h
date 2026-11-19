/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboughad <aboughad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 10:30:42 by aboughad          #+#    #+#             */
/*   Updated: 2026/11/19 15:39:16 by aboughad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		find_newline(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char *s, int end);
char	*ft_substr(char *str, unsigned int start);
void	ft_memcpy(void *dst, void *src, size_t len);

#endif
