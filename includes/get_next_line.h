/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:34:51 by mzelouan          #+#    #+#             */
/*   Updated: 2024/03/06 13:34:47 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd, int clear);
void	read_line_fd(char **stash, int fd);
char	*ft_strchr_get(const char *s, int c);
char	*ft_strjoin_get(char *left_str, char *buff);
size_t	ft_strlen_get(const char *s);
char	*extract_line(char *stash);
char	*clean_stash(char *stash);

#endif
