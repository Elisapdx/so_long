/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elisa <elisa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:20:14 by epraduro          #+#    #+#             */
/*   Updated: 2023/01/25 17:40:34 by elisa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_window	new_window(t_game *game, int widht, int height, char *name)
{
	t_window	window;

	window.reference = mlx_new_window(game->mlx, widht, height, name);
	return (window);
}

int	error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (1);
}

int	exit_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window.reference);
	write(1, "Vous avez fermé la fenêtre du jeu!\n", 38);
	exit(0);
}

void	start_game(char *fichier, t_game *game)
{
	game->mlx = mlx_init();
	game->window = new_window(game, game->colone_count * 40,
			game->line_count * 40, "Pacman!");
	game->nb_move = 0;
	load_img(game);
	load_map(game);
	mlx_key_hook(game->window.reference, key_hook, game);
	mlx_hook(game->window.reference, 17, 0, exit_window, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc > 2)
		return (error("usage ./so_long <map>\n"));
	game.map = read_map(argv[1], &game);
	game.count_c = 0;
	game.count_e = 0;
	game.count_p = 0;
	game.collect = 0;
	if (!check_rect(&game) || !checker_line_next(&game))
		return (error("map invalid\n"));
	if (!checker_map_poss(&game) || !resolver_map(&game))
		return (error("map invalid ou inacesssible object"));
	if (!error_map(&game))
		return (error("problem with objects in map"));
	start_game(argv[1], &game);
}
