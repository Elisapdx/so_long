/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 17:42:21 by elisa             #+#    #+#             */
/*   Updated: 2023/02/06 17:51:57 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_coor_exit(t_game *game, int x, int y)
{
	game->coor_exit.x = x;
	game->coor_exit.y = y;
	put_img_to_window(game, game->bdd.exit, x * 40, y * 40);
}

void	aff_nb_steps(t_game *game)
{
	char	*nb_step_player;

	nb_step_player = ft_itoa(game->nb_move);
	put_img_to_window(game, game->bdd.wall, 0, 0);
	put_img_to_window(game, game->bdd.wall, 40, 0);
	put_img_to_window(game, game->bdd.wall, 80, 0);
	mlx_string_put(game->mlx, game->window.reference,
		20, 20, 0x00FFFFFF, "nb pas: ");
	mlx_string_put(game->mlx, game->window.reference,
		75, 20, 0x00FFFFFF, nb_step_player);
	free(nb_step_player);
}

void	exit_wwin(t_game *game, int x_inc, int y_inc)
{
	if (game->collect == game->count_c)
	{
		write(1, "Vous avez gagné !\n", 20);
		exit(0);
	}
	else
	{
		move_player(game, x_inc, y_inc);
		write(1, "Vous n'avez assez collecté pour fuir !\n", 41);
	}
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

int	verif_fichier(char *fichier)
{
	size_t	len;
	int		fd;

	len = ft_strlen(fichier);
	if (open(fichier, O_DIRECTORY) >= 0)
	{
		fd = open(fichier, O_DIRECTORY);
		close(fd);
		return (0);
	}
	else
	{
		fd = open(fichier, O_RDONLY);
		close (fd);
		if ((fichier[len - 4] != '.' && fichier[len - 3] != 'b'
				&& fichier[len - 2] != 'e'
				&& fichier[len - 1] != 'r') || fd < 0)
			return (0);
		return (1);
	}
}
