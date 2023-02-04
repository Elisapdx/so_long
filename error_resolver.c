/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_resolver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:07:31 by epraduro          #+#    #+#             */
/*   Updated: 2023/02/03 14:23:21 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**copy_map(t_game *game)
{
	int		i;
	char	**map_cop;

	map_cop = malloc(sizeof(char *) * (game->line_count + 1));
	i = -1;
	while (game->map[++i])
		map_cop[i] = ft_strdup(game->map[i]);
	map_cop[i] = NULL;
	return (map_cop);
}

int	resolver_map(t_game *game)
{
	char	**map_cop;

	game->y_cop = 0;
	map_cop = NULL;
	while (game->map[game->y_cop])
	{
		game->x_cop = 0;
		while (game->map[game->y_cop][game->x_cop])
		{
			chemin(game, map_cop, game->x_cop, game->y_cop);
			game->x_cop++;
		}
		game->y_cop++;
	}
	return (1);
}

int	path_poss(t_game *game, char **map_cop, int x, int y)
{
	if (game->map[y][x] == 'P')
		return (1);
	if (game->map[y][x] == 'E' || game->map[y][x] == '1'
		|| map_cop[y][x] == '1')
		return (0);
	map_cop[y][x] = '1';
	if (x > 0)
		if (path_poss(game, map_cop, x - 1, y))
			return (1);
	if (map_cop[y][x + 1])
		if (path_poss(game, map_cop, x + 1, y))
			return (1);
	if (y > 0)
		if (path_poss(game, map_cop, x, y - 1))
			return (1);
	if (map_cop[y + 1][x] != '\n')
		if (path_poss(game, map_cop, x, y + 1))
			return (1);
	return (0);
}

int	path_poss2(t_game *game, char **map_cop, int x, int y)
{
	if (game->map[y][x] == 'P')
		return (1);
	if (game->map[y][x] == '1' || map_cop[y][x] == '1')
		return (0);
	map_cop[y][x] = '1';
	if (x > 0)
		if (path_poss(game, map_cop, x - 1, y))
			return (1);
	if (map_cop[y][x + 1])
		if (path_poss(game, map_cop, x + 1, y))
			return (1);
	if (y > 0)
		if (path_poss(game, map_cop, x, y - 1))
			return (1);
	if (map_cop[y + 1][x] != '\n')
		if (path_poss(game, map_cop, x, y + 1))
			return (1);
	return (0);
}
