/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maskour <maskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:34:20 by maskour           #+#    #+#             */
/*   Updated: 2025/02/28 14:53:31 by maskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*process_line(char *allin, char *line)
{
	char	*tmp;

	if (line[0] == '\n')
	{
		free(line);
		free(allin);
		return (NULL);
	}
	tmp = allin;
	allin = ft_strjoin(allin, line);
	free(line);
	free(tmp);
	return (allin);
}

static char	*join_lines(int fd)
{
	char	*line;
	char	*all_line;

	line = NULL;
	all_line = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		all_line = process_line(all_line, line);
		if (all_line == NULL)
			break ;
	}
	return (all_line);
}

char	**read_map(char *maps_file)
{
	char	**result;
	int		fd;
	char	*allin;

	fd = open(maps_file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	allin = join_lines(fd);
	close(fd);
	if (!allin || allin[0] == '\0')
	{
		free(allin);
		return (NULL);
	}
	result = ft_split(allin, '\n');
	free(allin);
	return (result);
}
