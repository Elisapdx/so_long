/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epraduro <epraduro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:20:14 by epraduro          #+#    #+#             */
/*   Updated: 2023/01/18 18:00:32 by epraduro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
	return (1);
}

void	start_game(char *fichier, t_game *game)
{
	game->mlx = mlx_init();
	game->window = new_window(game, game->colone_count * 40,
			game->line_count * 40, "Pacman!");
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
	if (!check_rect(&game) || !checker_line_next(&game))
		return (error("map invalid\n"));
	if (!checker_map_poss(&game))
		return (error("map impossible, inacesssible object"));
	start_game(argv[1], &game);
}
