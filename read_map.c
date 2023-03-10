/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:41:08 by elisa             #+#    #+#             */
/*   Updated: 2023/02/06 17:43:35 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	null_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	exit(1);
}

int	file_empty(char *file)
{
	int		fd;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (0);
	read(fd, &c, 1);
	if (c == '\0')
		return (0);
	return (1);
}

static int	linecount_map(char *file)
{
	int		line_count;
	int		fd;
	int		read_count;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	line_count = 1;
	while (1)
	{
		read_count = read(fd, &c, 1);
		if (read_count == 0)
			break ;
		if (read_count < 0)
			return (-1);
		if (c == '\n')
			line_count++;
	}
	close(fd);
	return (line_count);
}

/* Allocates memory */
static char	**check_alloc_map(char *file, t_game *game)
{
	char	**map;
	int		line_count;

	line_count = linecount_map(file);
	game->line_count = line_count;
	if (!file_empty(file))
		null_error("Error\n file empty or not exist");
	map = malloc(sizeof(char *) * (line_count + 1));
	if (map == NULL)
		null_error("Error\n Malloc error !");
	return (map);
}

/* Creates a char map */
char	**read_map(char *file, t_game *game)
{
	char	**map;
	int		fd;
	int		i;

	map = check_alloc_map(file, game);
	if (map == NULL)
		return (NULL);
	fd = open(file, O_RDONLY);
	i = 0;
	while (i < game->line_count + 1)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}
