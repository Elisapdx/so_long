/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:42:21 by elisa             #+#    #+#             */
/*   Updated: 2023/01/25 17:43:13 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	exit_wwin(int coin, int nb_coin)
{
	if (coin == nb_coin)
	{
		write(1, "Vous êtes sorti du jeu\n", 25);
		exit(0);
	}
	else
		write(1, "Pas assez de coins pour fuir !\n", 32);
}

/* up = 13 || 126
down = 1 || 125
right = 2 || 124
left = 0 || 123 */
int	key_hook(int keycode, void *game)
{
	t_game	*key;

	key = (t_game *) game;
	if (keycode == 2 || keycode == 124)
		move(key, 1, 0);
	else if (keycode == 0 || keycode == 123)
		move(key, -1, 0);
	else if (keycode == 13 || keycode == 126)
		move(key, 0, -1);
	else if (keycode == 1 || keycode == 125)
		move(key, 0, 1);
	else if (keycode == 53)
	{
		write(1, "Vous avez quitté le jeu\n", 26);
		exit(0);
	}
	return (1);
}
