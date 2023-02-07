/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:41:15 by elisa             #+#    #+#             */
/*   Updated: 2023/02/07 17:11:46 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	set_player(t_game *game, int x, int y)
{
	game->player.pos_x = x;
	game->player.pos_y = y;
	put_img_to_window(game, game->bdd.floor, x * 40, y * 40);
	put_img_to_window(game, game->bdd.player, x * 40, y * 40);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.addr = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

void	put_img_to_window(t_game *game, t_image image, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window.reference,
		image.reference, x, y);
}

void	load_img(t_game *game)
{
	game->bdd.player = ft_new_sprite(game->mlx, "./image_xpm/pacman_l.xpm");
	game->bdd.floor = ft_new_sprite(game->mlx, "./image_xpm/floor.xpm");
	game->bdd.wall = ft_new_sprite(game->mlx, "./image_xpm/wall.xpm");
	game->bdd.coin = ft_new_sprite(game->mlx, "./image_xpm/coin.xpm");
	game->bdd.exit = ft_new_sprite(game->mlx, "./image_xpm/exit.xpm");
}

void	load_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				put_img_to_window(game, game->bdd.wall, j * 40, i * 40);
			else if (game->map[i][j] == '0')
				put_img_to_window(game, game->bdd.floor, j * 40, i * 40);
			else if (game->map[i][j] == 'C')
				put_img_to_window(game, game->bdd.coin, j * 40, i * 40);
			else if (game->map[i][j] == 'P')
				set_player(game, j, i);
			else if (game->map[i][j] == 'E')
			{
				game->coor_exit.x = j;
				game->coor_exit.y = i;
				put_img_to_window(game, game->bdd.exit, j * 40, i * 40);
			}
		}
	}
}
