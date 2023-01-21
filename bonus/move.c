/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:28:29 by elisa             #+#    #+#             */
/*   Updated: 2023/01/21 17:31:54 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 12);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		c = n % 10 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n + '0';
		write(1, &c, 1);
	}
}

static int	ft_count(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;
	long	nb;

	i = 0;
	nb = n;
	res = (char *)malloc(sizeof(char) * (ft_count(nb) + 1));
	if (!res)
		return (NULL);
	i = ft_count(nb);
	res[i--] = '\0';
	if (nb < 0)
		nb *= -1;
	while (i >= 0)
	{
		res[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
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

void	move_player(t_game *game, int x_inc, int y_inc)
{
	int	old_x;
	int	old_y;
	char *nb_step_player;

	game->nb_move++;
	write(1, "Nombre de pas du joueur: ", 26);
	nb_step_player = ft_itoa(game->nb_move);
	put_img_to_window(game, game->bdd.wall, 0, 0);
	mlx_string_put(game->mlx, game->window.reference, 10, 10, 0x00FFFFFF, nb_step_player);
	free(nb_step_player);
	ft_putnbr_fd(game->nb_move, 1);
	write(1, "\n", 1);
	old_x = game->player.pos_x;
	old_y = game->player.pos_y;
	game->player.pos_x += x_inc;
	game->player.pos_y += y_inc;
	put_img_to_window(game, game->bdd.player, game->player.pos_x * 40,
		game->player.pos_y * 40);
	put_img_to_window(game, game->bdd.floor, old_x * 40, old_y * 40);
}

void	move(t_game *game, int x_inc, int y_inc)
{
	int	stock_move;

	stock_move = game->map[game->player.pos_y + y_inc]
	[game->player.pos_x + x_inc];
	if (game->player.pos_x + x_inc > 0
		&& game->player.pos_x + x_inc < game->limit_x
		&& game->player.pos_y + y_inc > 0
		&& game->player.pos_y + y_inc < game->line_count)
	{
		if (stock_move == 'C')
			game->collect++;
		if (stock_move != '1' && stock_move != 'E')
			move_player(game, x_inc, y_inc);
		if (stock_move == 'M')
		{
			write(1, "Vous avez été tué par un ennemi !\n", 38);
			exit(0);
		}
		if (stock_move == 'E')
		{
			if (game->collect == game->count_c)
			{
				write(1, "Vous êtes sorti du jeu\n", 25);
				exit(0);
			}
			else
				write(1, "Pas assez de coins pour fuir !\n", 32);
		}
	}
}
