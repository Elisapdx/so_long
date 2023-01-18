/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:49:31 by elisa             #+#    #+#             */
/*   Updated: 2023/01/16 15:26:59 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	error_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
				game->count_p++;
			else if (game->map[i][j] == 'E')
				game->count_e++;
			else if (game->map[i][j] == 'C')
				game->count_c++;
			j++;
		}
		j = 0;
		i++;
	}
	if (!game->count_p || game->count_e || game->count_c)
		return (0);
	return (1);
}

int	checker_map(t_game *game, int ard)
{
	int	i;

	i = 0;
	while (game->map[ard][i] && game->map[ard][i] != '\n')
	{
		if (game->map[ard][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_rect(t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->map[i++]);
	while (i < game->line_count)
		if (len != ft_strlen(game->map[i++]))
			return (0);
	return (1);
}

int	checker_line_next(t_game *game)
{
	int	i;
	int	len;

	i = 1;
	len = ft_strlen(game->map[0]);
	if (checker_map(game, 0) != 1 || checker_map(game, game->line_count) != 1)
		return (0);
	while (i < game->line_count)
	{
		if (game->map[i][0] != '1' || game->map[i][len - 2] != '1')
			return (0);
		i++;
	}
	game->limit_x = len - 2;
	return (1);
}

int	checker_map_poss(t_game *game)
{
	int	i;
	int	j;

	i = 1;
	while (i < game->line_count)
	{
		j = -1;
		while (game->map[i][++j])
			if (game->map[i][j] == 'C' || game->map[i][j] == 'P'
				|| game->map[i][j] == 'E')
				if (game->map[i][j + 1] == '1' && game->map[i][j - 1] == '1'
					&& game->map[i + 1][j] == '1' && game->map[i - 1][j] == '1')
					return (0);
		i++;
	}
	return (1);
}
