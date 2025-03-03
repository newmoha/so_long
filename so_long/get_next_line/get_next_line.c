/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:46:13 by maskour           #+#    #+#             */
/*   Updated: 2025/02/28 14:50:25 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*ft_get_line(char *save)
{
	int		i;
	char	*line;
	int		extra;

	extra = 1;
	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		extra++;
	line = malloc(sizeof(char) * (i + extra));
	if (!line)
		return (NULL);
	ft_memcpy(line, save, i);
	if (save[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_save(char *save)
{
	int		i;
	char	*str;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	str = ft_strdup(&save[i + 1]);
	if (!str)
	{
		free(save);
		return (NULL);
	}
	free(save);
	return (str);
}

static char	*ft_read_and_save(int fd, char *save)
{
	char	*buff;
	int		read_bytes;
	char	*temp;

	buff = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buff)
		return (free(save), save = NULL, NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		buff[read_bytes] = '\0';
		if (!save)
			save = ft_strdup("");
		temp = save;
		save = ft_strjoin(temp, buff);
		free(temp);
		if (ft_strchr(save, '\n'))
			break ;
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*save;

	if (BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (read(fd, 0, 0) != 0)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	if (!line)
		return (free(save), save = NULL, NULL);
	save = ft_save(save);
	if (!save)
		save = NULL;
	return (line);
}
