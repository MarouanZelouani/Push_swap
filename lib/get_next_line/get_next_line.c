/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:34:41 by mzelouan          #+#    #+#             */
/*   Updated: 2024/03/06 13:35:21 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/get_next_line.h"

void	read_line_fd(char **stash, int fd)
{
	char	*holder;
	int		read_count;

	while (!ft_strchr_get(*stash, '\n'))
	{
		holder = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
		if (holder == NULL)
			return ;
		read_count = read(fd, holder, BUFFER_SIZE);
		if (read_count == 0)
		{
			free(holder);
			return ;
		}
		if (read_count == -1)
		{
			free(holder);
			free(*stash);
			*stash = NULL;
			return ;
		}
		holder[read_count] = '\0';
		*stash = ft_strjoin_get(*stash, holder);
		free(holder);
	}
}

char	*extract_line(char *stash)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (!stash || !ft_strlen_get(stash))
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (line == NULL)
		return (NULL);
	i = -1;
	while (stash[++i] && stash[i] != '\n')
		line[i] = stash[i];
	if (stash[i] && stash[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	char	*holder;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	holder = malloc(((ft_strlen_get(stash) - i) + 1) * sizeof(char));
	if (holder == NULL)
		return (NULL);
	while (stash[i])
	{
		holder[j] = stash[i];
		j++;
		i++;
	}
	holder[j] = '\0';
	free(stash);
	return (holder);
}

char	*get_next_line(int fd, int clear)
{
	static char	*stash;
	char		*line;

	if (clear)
		return (free(stash), NULL);
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	read_line_fd(&stash, fd);
	if (stash == NULL)
		return (NULL);
	line = extract_line(stash);
	if (line == NULL)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = clean_stash(stash);
	return (line);
}
